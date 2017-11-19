#pragma once

#include <string>
#include <vector>
#include <boost/optional.hpp>

namespace iProlog
{


	class Engine
	{

  public:
	  static constexpr int MAXIND = 3; // number of index args
	  static constexpr int START_INDEX = 20;
	  // switches off indexing for less then START_INDEX clauses e.g. <20


	  virtual ~Engine()
	  {
		  delete syms;
		  delete trail;
		  delete ustack;
		  delete spines;
		  delete query;
	  }

	  Engine(const std::wstring &fname);


	  std::vector<Clause*> const clauses;

	  std::vector<int> const cls;
	  /// <summary>
	  /// symbol table made of map + reverse map from ints to syms </summary>

	  LinkedHashMap<std::wstring, int> *const syms;
  private:
	  const std::vector<std::wstring> slist;

	

	  std::vector<int> heap;
	  int top = 0;
  public:
	  static int MINSIZE; // power of 2

  private:
	  IntStack *const trail;
	  IntStack *const ustack;
	  ObStack<Spine*> *const spines = new ObStack<Spine*>();

  public:
	  Spine *query;

	  std::vector<IMap<int>*> const imaps;
	  std::vector<IntMap*> const vmaps;

	
  private:
	  static constexpr int V = 0;
	  static constexpr int U = 1;
	  static constexpr int R = 2;

	  static constexpr int C = 3;
	  static constexpr int N = 4;

	  static constexpr int A = 5;

	  // G - ground?

	  static constexpr int BAD = 7;


	  static int tag(int const t, int const w);

	  /// <summary>
	  /// removes tag after flipping sign
	  /// </summary>
	  static int detag(int const w);

	
	  static int tagOf(int const w);


	  int addSym(const std::wstring &sym);


	  std::wstring getSym(int const w);

	  void makeHeap();

	  void makeHeap(int const size);

	  int getTop();

	  int setTop(int const top);

	  void clear();

	  void push(int const i);

  public:
	  int size();


  private:
	  void expand();

	  void ensureSize(int const more);

	

	  static std::vector<std::vector<std::wstring>> maybeExpand(std::vector<std::wstring> &Ws);


	  static std::vector<std::vector<std::wstring>> mapExpand(std::vector<std::vector<std::wstring>> &Wss);


  public:
	  virtual std::vector<Clause*> dload(const std::wstring &s);

  private:
	  static std::vector<int> toNums(std::vector<Clause*> &clauses);

	  /*
	   * encodes string constants into symbols while leaving
	   * other data types untouched
	   */
	};

}
