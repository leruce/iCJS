#include "StdAfx.h"
#ifndef _INTLIST_H
#define _INTLIST_H

#include "IntStack.h"
#include <string>
#include <vector>
#include <string>

// Typedefs


class IntList {
public:
	typedef IntList * IntListPtr;
	//     Variables
	//    IntList EMPTY = NULL;

	//  Constructors
	// see private functions
	//    IntList();
	//IntList(int head);


	//  Destructors



	//  Accessors
	// get value of head
	static int getHead(IntList Xs);
	static int getHead(IntList *Xs);

	// get tail
	static IntList* getTail(IntList Xs);
	static IntList* getTail(IntList *Xs);

	// Mutators



	//  Methods

	// is list empty
	static bool isEmpty(IntList Xs);
	static bool isEmpty(IntList * Xs);


	// add new head to a list
	static IntList * cons(int X, IntList *Xs);

	// append int vector xs to IntList Ys
	static IntList * app(std::vector <int> xs, IntList *Ys);



	// puts an IntList onto an IntStack
	// returns an IntStack object
	static IntStack * toInts(IntList *Xs);

	// calc length of an IntList
	static int len(IntList *Xs);


	// not sure what this does
	std::string toString();

	//    private data members
public:
	int         head;
	IntList *    tail; // pointer to next value after head


					   //  private Constructors

					   //    IntList(const int head);
	IntList(int head);
	IntList(int X, IntList *Xs);
	//    IntList(const int X, const IntList &Xs);

};


#endif //IPROLOG_INTLIST_H
