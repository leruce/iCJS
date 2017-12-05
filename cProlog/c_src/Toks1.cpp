//
// Created by Bidbip on 12/4/2017.
//


#include "Toks1.h"


string Toks1::getWord(string tok) {
    string t = ""; //Set the default null
    //Do we need an error checker if we know for the fact the current files will work?
    if (isupper(tok[0]) || tok[0] == '_') {
        t = "v:" + tok;
    }
    else {
        int num;
        try {
            num = boost::lexical_cast<int>(tok);
            if (abs(num) < 1 << 28) {
                t = "n:" + tok;
            }
            else {
                t = "c:" + tok;
            }
        }
        catch(boost::bad_lexical_cast const& e) {
            t = "c:" + tok;
        }
    }
    return t;
}

vector<vector<vector<string>>> Toks1::toSentence(string &s, bool fromFile) {
    vector<vector<vector<string>>> Wsss;
    vector<vector<string>> Wss;
    vector<string> Ws;
    const string IF = "if";
    const string AND = "and";
    const string DOT = ".";
    const string HOLDS = "holds";
    const string LISTS = "list";
    const string IS = "is";

    char CharSep[] = "!\"#$%&'()*+,-/:;<=>?@[\\]^`{|}~ ";
    if (fromFile) {
        ifstream inFile(s, ios::in);
        if (inFile.is_open()) {
            cout << "Open" << endl;
        }
        string getLine;
        while(getline(inFile, getLine)) {
            typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
            boost::char_separator<char> charSep(CharSep);
            tokenizer tok{getLine, charSep};
            for (tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter) {
                string t = getWord(*tok_iter);
                if (t == ("c:" + DOT)) {
                    Wss.push_back(Ws);
                    Wsss.push_back(Wss);
                    Wss.clear();
                    Ws.clear();
                }
                else if (t == ("c:" + IF)) {
                    Wss.push_back(Ws);
                    Ws.clear();
                }
                else if (t == ("c:" + AND)) {
                    Wss.push_back(Ws);
                    Ws.clear();
                }
                else if (t == ("c:" + HOLDS)) {
                    string w = Ws[0];
                    Ws[0] = "h:" + w.substr(2, w.size());
                }
                else if(t == ("c:" + LISTS)) {
                    string w = Ws[0];
                    Ws[0] = "l:" + w.substr(2, w.size());
                }
                else if(t == ("c:" + IS)) {
                    string w = Ws[0];
                    Ws[0] = "f:" + w.substr(2, w.size());
                }
                else {
                    Ws.push_back(t);
                }

            }
        }
    }
    else {
        //This is for anything with a single string.
        //This is for Testing Purpose
        typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        boost::char_separator<char> charSep(CharSep);
        tokenizer tok{s, charSep};
        for (tokenizer::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter) {
            string t = getWord(*tok_iter);
            if (t == ("c:" + DOT)) {
                Wss.push_back(Ws);
                Wsss.push_back(Wss);
                Wss.clear();
                Ws.clear();
            }
            else if (t == ("c:" + IF)) {
                Wss.push_back(Ws);
                Ws.clear();
            }
            else if (t == ("c:" + AND)) {
                Wss.push_back(Ws);
                Ws.clear();
            }
            else if (t == ("c:" + HOLDS)) {
                string w = Ws[0];
                Ws[0] = "h:" + w.substr(2, w.size());
            }
            else if(t == ("c:" + LISTS)) {
                string w = Ws[0];
                Ws[0] = "l:" + w.substr(2, w.size());
            }
            else if(t == ("c:" + IS)) {
                string w = Ws[0];
                Ws[0] = "f:" + w.substr(2, w.size());
            }
            else {
                Ws.push_back(t);
            }
        }
    }
    return Wsss;
}

void Toks1::PrintTok(vector<vector<vector<string>>> Wsss) {
    cout << "{";
    for (auto Wss : Wsss) {
        cout << "{";
        for (auto Ws : Wss) {
            cout << "{";
            for (auto W : Ws) {
                if (W == Ws.back()) {
                    cout << " " <<W;
                }
                else {
                    cout << W << " , ";
                }
            }
            if (Ws == Wss.back()) {
                cout << "}";
            }
            else {
                cout << "}, ";
            }
        }
        cout << "}";
    }
    cout << "}\n";
}