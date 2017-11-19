#include "Engine.h"

namespace iProlog
{

	Engine::Engine(const std::wstring &fname) : clauses(dload(fname)), cls(toNums(clauses)), syms(new LinkedHashMap<std::wstring, int>()), slist(std::vector<std::wstring>()), trail(new IntStack()), ustack(new IntStack()), imaps(index(clauses, vmaps)), vmaps(vcreate(MAXIND))
	{

	  makeHeap();




	  query = init();

	}

int Engine::MINSIZE = 1 << 15;

	int Engine::tag(int const t, int const w)
	{
	  return -((w << 3) + t);
	}

	int Engine::detag(int const w)
	{
	  return -w >> 3;
	}

	int Engine::tagOf(int const w)
	{
	  return -w & 7;
	}

	int Engine::addSym(const std::wstring &sym)
	{
	  boost::optional<int> I = syms->get(sym);
	  if (nullptr == I)
	  {
		constexpr int i = syms->size();
		I = boost::optional<int>(i);
		syms->put(sym, I);
		slist.push_back(sym);
	  }
	  return I.value();
	}

	std::wstring Engine::getSym(int const w)
	{
	  if (w < 0 || w >= slist.size())
	  {
		return L"BADSYMREF=" + std::to_wstring(w);
	  }
	  return slist[w];
	}

	void Engine::makeHeap()
	{
	  makeHeap(MINSIZE);
	}

	void Engine::makeHeap(int const size)
	{
	  heap = std::vector<int>(size);
	  clear();
	}

	int Engine::getTop()
	{
	  return top;
	}

	int Engine::setTop(int const top)
	{
	  return this->top = top;
	}

	void Engine::clear()
	{
	  //for (int i = 0; i <= top; i++)
	  //heap[i] = 0;
	  top = -1;
	}

	void Engine::push(int const i)
	{
	  heap[++top] = i;
	}

	int Engine::size()
	{
	  return top + 1;
	}

	void Engine::expand()
	{
	  constexpr int l = heap.size();
	  const std::vector<int> newstack = std::vector<int>(l << 1);

	  System::arraycopy(heap, 0, newstack, 0, l);
	  heap = newstack;
	}

	void Engine::ensureSize(int const more)
	{
	  if (1 + top + more >= heap.size())
	  {
		expand();
	  }
	}

	std::vector<std::vector<std::wstring>> Engine::maybeExpand(std::vector<std::wstring> &Ws)
	{
	  const std::wstring W = Ws[0];
	  if (W.length() < 2 || L"l:" != W.substr(0, 2))
	  {
		return nullptr;
	  }

	  constexpr int l = Ws.size();
	  const std::vector<std::vector<std::wstring>> Rss = std::vector<std::vector<std::wstring>>();
	  const std::wstring V = W.substr(2);
	  for (int i = 1; i < l; i++)
	  {
		const std::vector<std::wstring> Rs = std::vector<std::wstring>(4);
		const std::wstring Vi = 1 == i ? V : V + L"__" + std::to_wstring(i - 1);
		const std::wstring Vii = V + L"__" + std::to_wstring(i);
		Rs[0] = L"h:" + Vi;
		Rs[1] = L"c:list";
		Rs[2] = Ws[i];
		Rs[3] = i == l - 1 ? L"c:nil" : L"v:" + Vii;
		Rss.push_back(Rs);
	  }
	  return Rss;

	}

	std::vector<std::vector<std::wstring>> Engine::mapExpand(std::vector<std::vector<std::wstring>> &Wss)
	{
	  const std::vector<std::vector<std::wstring>> Rss = std::vector<std::vector<std::wstring>>();
	  for (auto Ws : Wss)
	  {

		const std::vector<std::vector<std::wstring>> Hss = maybeExpand(Ws);

		if (nullptr == Hss)
		{
		  const std::vector<std::wstring> ws = std::vector<std::wstring>(Ws.size());
		  for (int i = 0; i < ws.size(); i++)
		  {
			ws[i] = Ws.get(i);
		  }
		  Rss.push_back(ws);
		}
		else
		{
		  for (auto X : Hss)
		  {
			Rss.push_back(X);
		  }
		}
	  }
	  return Rss;
	}

	std::vector<Clause*> Engine::dload(const std::wstring &s)
	{
	  constexpr bool fromFile = true;
	  const std::vector<std::vector<std::vector<std::wstring>>> Wsss = Toks::toSentences(s, fromFile);

	  const std::vector<Clause*> Cs = std::vector<Clause*>();

	  for (auto Wss : Wsss)
	  {
		// clause starts here

		LinkedHashMap<std::wstring, IntStack*> * const refs = new LinkedHashMap<std::wstring, IntStack*>();
		IntStack * const cs = new IntStack();
		IntStack * const gs = new IntStack();

		const std::vector<std::vector<std::wstring>> Rss = mapExpand(Wss);
		int k = 0;
		for (auto ws : Rss)
		{

		  // head or body element starts here

		  constexpr int l = ws.size();
		  gs->push(tag(R, k++));
		  cs->push(tag(A, l));

		  for (auto w : ws)
		  {

			// head or body subterm starts here

			if (1 == w.length())
			{
			  w = L"c:" + w;
			}

			const std::wstring L = w.substr(2);

			switch (w.charAt(0))
			{
			  case L'c':
				cs->push(encode(C, L));
				k++;
			  break;
			  case L'n':
				cs->push(encode(N, L));
				k++;
			  break;
			  case L'v':
			  {
				IntStack *Is = refs->get(L);
				if (nullptr == Is)
				{
				  Is = new IntStack();
				  refs->put(L, Is);
				}
				Is->push(k);
				cs->push(tag(BAD, k)); // just in case we miss this
				k++;
			  }
			  break;
			  case L'h':
			  {
				IntStack *Is = refs->get(L);
				if (nullptr == Is)
				{
				  Is = new IntStack();
				  refs->put(L, Is);
				}
				Is->push(k - 1);
				cs->set(k - 1, tag(A, l - 1));
				gs->pop();
			  }
			  break;
			  default:
				Main::pp(L"FORGOTTEN=" + w);
			} // end subterm
		  } // end element
		} // end clause

		// linker
		const Iterator<IntStack*> K = refs->values().begin();

		while (K->hasNext())
		{
		  IntStack * const Is = K->next();

		  // finding the A among refs
		  int leader = -1;
		  for (int j : Is->toArray())
		  {
			if (A == tagOf(cs->get(j)))
			{
			  leader = j;

			  break;
			}
		  }
		  if (-1 == leader)
		  {
			// for vars, first V others U
			leader = Is->get(0);
			for (int i : Is->toArray())
			{
			  if (i == leader)
			  {
				cs->set(i, tag(V, i));
			  }
			  else
			  {
				cs->set(i, tag(U, leader));
			  }

			}
		  }
		  else
		  {
			for (int i : Is->toArray())
			{
			  if (i == leader)
			  {
				continue;
			  }
			  cs->set(i, tag(R, leader));
			}
		  }
			K++;
		}

		constexpr int neck = 1 == gs->size() ? cs->size() : detag(gs->get(1));
		const std::vector<int> tgs = gs->toArray();

		Clause * const C = putClause(cs->toArray(), tgs, neck);

		Cs.push_back(C);

	  } // end clause set

	  constexpr int ccount = Cs.size();
	  std::vector<Clause*> cls(ccount);
	  for (int i = 0; i < ccount; i++)
	  {
		cls[i] = Cs[i];
	  }
	  return cls;
	}

	std::vector<int> Engine::toNums(std::vector<Clause*> &clauses)
	{
	  constexpr int l = clauses.size();
	  const std::vector<int> cls = std::vector<int>(l);
	  for (int i = 0; i < l; i++)
	  {
		cls[i] = i;
	  }
	  return cls;
	}
}
