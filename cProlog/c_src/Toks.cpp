#include "Toks.h"

namespace iProlog
{
	typedef boost::tokenizer<boost::char_separator<char> > streamTokenizer;
	static std::string IF = "if";
	static std::string AND =  "and";
	static std::string DOT = ".";
	static std::string HOLDS = "holds";
	static std::string LISTS = "lists"; // todo
	static std::string IS =  "is"; // todo
	static boost::char_separator<char> sep(".!/:@[`{~");


	Toks *Toks::makeToks(const std::string &s, bool const fromFile)
	{
	  try
	  {
			std::ifstream  R(s.c_str());
		//if (fromFile)
		//{
		   
		//}
		//else
		//{
		//  R = new StringReader(s);
		//}
		Toks * const T = new Toks(R);
		return T;

		}

		
    catch (const IOException &e)
	  {
		e.what();
		return NULL;
	  }
	}

	Toks::Toks(std::ifstream& Reader) : reader(Reader)
	{

	  //resetSyntax();
	  //eolIsSignificant(false);
	  //ordinaryChar(L'.');
	  //ordinaryChars(L'!', L'/'); // 33-47
	  //ordinaryChars(L':', L'@'); // 55-64
	  //ordinaryChars(L'[', L'`'); // 91-96
		//ordinaryChars(L'{', L'~'); // 123-126
		
	
	 // wordChars(L'_', L'_');
	 // wordChars(L'a', L'z');
	 // wordChars(L'A', L'Z');
	 // wordChars(L'0', L'9');
	 // slashStarComments(true);
	 // slashSlashComments(true);
	 // ordinaryChar(L'%');

	 //StreamTokenizer(reader,sep);
	}



	std::vector<std::vector<std::vector<std::string>>> Toks::toSentences(const std::string &s, bool const fromFile)
	{
	  std::vector<std::vector<std::vector<std::string> > > Wsss;
	  std::vector<std::vector<std::string> > Wss;
	  std::vector<std::string> Ws;
	  Toks * const toks = makeToks(s, fromFile);
		std::string t;

		std::string ret;
		char buffer[4096];
		
    while (reader.read(buffer, sizeof(buffer)))
        ret.append(buffer, sizeof(buffer));
    		ret.append(buffer, reader.gcount());

				streamTokenizer tokens(ret,sep);
		
    for (streamTokenizer::iterator tok_iter = tokens.begin();
		tok_iter != tokens.end(); ++tok_iter){
    //  std::cout << "<" << *tok_iter << "> ";
					std::string t = "";
					std::string  firsttoken = *tok_iter;
					char first = firsttoken.at(0);
					if(isupper(first)|| '_' == first){
						 t = "v:" + *tok_iter;
					}	else {
						  try{
								int n = std::stoi(*tok_iter);
                if (abs(n) < 1 << 28) {
									t = "n:" + *tok_iter;
								} else {
									t = "c:" + *tok_iter;
								}
					  }catch(IOException e){
						t = "c:" + *tok_iter;
						e.what();
					}	
			 }						
		}


	  if (!t.empty()) 
	  {
		if(DOT == t)
		{
		  Wss.push_back(Ws);
		  Wsss.push_back(Wss);
		  Wss = std::vector<std::vector<std::string> >();
		  Ws = std::vector<std::string>();
		}

		else if (t.compare("c:" + IF))
		{		
		  Wss.push_back(Ws);
		  Ws = std::vector<std::string>();
		}
		else if (t.compare("c:" + AND))
		{
		  Wss.push_back(Ws);
		  Ws = std::vector<std::string>();
		}
		else if (t.compare("c:" + HOLDS))
		{
		  const std::string w = Ws[0];
		  Ws[0] = "h:" + w.substr(2);
		}
		else if (t.compare("c:" + LISTS))
		{
		  const std::string w = Ws[0];
		  Ws[0] = "l:" + w.substr(2);
		}
		else if (t.compare("c:" + IS))
		{
		   const std::string w = Ws[0];
		   Ws[0] = "f:" + w.substr(2);
		 }
		 else
		  {
		   Ws.push_back(t);
		 }
	  }
	  return Wsss;
	}

//	std::string Toks::toString(std::vector<void*> &Wsss)
//	{
//	  return Arrays::deepToString(Wsss);
//	}

//	void Toks::main(std::vector<std::string> &args)
//	{
//	  Main::pp(toSentences("prog.nl", true));
//	}
}