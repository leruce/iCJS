#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include "exceptionhelper.h"
#include "stringhelper.h"

namespace iProlog
{

    using namespace std;
	/// <summary>
	/// Reads chars from char streams using the current default encoding
	/// </summary>
	class Toks
	{

	  // reserved words - with syntactic function

  public:
	  static std::wstring IF;
	  static std::wstring AND;
	  static std::wstring DOT;
	  static std::wstring HOLDS;
	  static std::wstring LISTS; // todo
	  static std::wstring IS; // todo
	  //static ifstream Reader;

	  static Toks *makeToks(const std::string &s, bool const fromFile);

	  Toks(std::ifstream& reader);

	  virtual std::wstring getWord();

	  static std::vector<std::vector<std::vector<std::wstring> > > toSentences(const std::wstring &s, bool const fromFile);

	  static std::wstring toString(std::vector<void*> &Wsss);

	  static void main(std::vector<std::wstring > &args);
	};
}