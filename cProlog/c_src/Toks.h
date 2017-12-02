#pragma once
#define _GLIBCXX_USE_CXX11_ABI 0

#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/split.hpp>
#include "exceptionhelper.h"
#include "stringhelper.h"


namespace iProlog
{
  

	class Toks
	{

	

  public:
	 
	  //static ifstream Reader;
      
	  
	  std::ifstream& reader;

	  Toks *makeToks(const std::string &s, bool const fromFile);

	  Toks(std::ifstream& reader);

	  virtual std::string getWord();

	  std::vector<std::vector<std::vector<std::string> > > toSentences(const std::string &s, bool const fromFile);

	  static std::string toString(std::vector<void*> &Wsss);

	  static void main(std::vector<std::string > &args);
	};
}