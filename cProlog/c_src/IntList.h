//
// Created by COLLEEN VANDERBILT on 9/28/17.
//

#ifndef IPROLOG_INTLIST_H
#define IPROLOG_INTLIST_H

#include "IntStack.h"
#include <string>
#include <vector>
/*
 ===========================================================================
 Name : IntList.h
 Author : Colleen A. Vanderbilt
 CSCE 5430
 Description : IntList C++ version of Java class in iProlog
 ===========================================================================
 */

/*
===================================================================
Class IntList
    Private data members: ?
    Default Constructor ?
    Constructor ?
    Copy constructor ?
    Accessors provided for all data members
    Mutators provided for all data members
    Assignment operator ?

===================================================================
*/

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
    IntList(int head);


//  Destructors



//  Accessors
    // get value of head
    int getHead (IntList Xs) const;
    int getHead (IntList *Xs) const;

    // get tail
    IntList* getTail (IntList Xs) const;
    IntList* getTail (IntList *Xs) const;

    // Mutators



//  Methods

    // is list empty
    bool isEmpty(IntList Xs) const;
    bool isEmpty(IntList * Xs) const;


    // add new head to a list
    IntList * cons(int X, IntList *Xs);

    // append int vector xs to IntList Ys
    IntList * app(std::vector <int> xs, IntList *Ys);



    // puts an IntList onto an IntStack
    // returns an IntStack object
    IntStack * toInts(IntList *Xs);

    // calc length of an IntList
    int len(IntList *Xs) const;


    // not sure what this does
    std::string toString();

//    private data members
private:
    int         head;
    IntList *    tail; // pointer to next value after head


//  private Constructors

//    IntList(const int head);
    IntList(int X, IntList *Xs);
//    IntList(const int X, const IntList &Xs);

};


#endif //IPROLOG_INTLIST_H
