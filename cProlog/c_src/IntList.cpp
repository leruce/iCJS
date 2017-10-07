//
// Created by COLLEEN VANDERBILT on 9/28/17.
//

#include "IntList.h"


/*
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                   Public Constructors
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

/*
 ===========================================================================
 Function : IntList
 Parameters : none
 Object Constructed : IntList object, with int value in head = -1, tail set to Null
 Description : default constructor
 ===========================================================================
 */

IntList::IntList()
{
    head = -1;
    tail = NULL;


}

/*
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                   Private Constructors
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

/*
 ===========================================================================
 Function : IntList
 Parameters : int value for head
 Object Constructed : IntList object, with int as value in head, tail set to Null
 Description : head value constructor
 ===========================================================================
 */

IntList::IntList(int head)
{
    this->head = head;
    tail = NULL;


}


/*
 ===========================================================================
 Function : IntList
 Parameters : int value for head (X), address of IntList (Xs)
 Object Constructed : IntList object, with int as value in head, tail set to address of Xs
 Description : constructor with head and tail
 ===========================================================================
 */

IntList::IntList(int X, IntList &Xs)
{

    head = X;
    tail = &Xs;


}

/*
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                   Getters
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

/*
 ===================================================================
 Function: getHead
 Parameters: IntList
 Return: int
 Description: returns value of head of an IntList
 ===================================================================
 */
int IntList::getHead(IntList Xs) const
{

    return Xs.head;

}


/*
===================================================================
Function: gethead
Parameters: IntList
Return: int
Description: returns value of head of an IntList
===================================================================
*/
int IntList::getHead(IntList *Xs) const
{

    return Xs->head;

}


/*
 ===================================================================
 Function: getTail
 Parameters: IntList
 Return: pointer to IntList
 Description: return pointer to value following head in the IntList
 ===================================================================
 */
IntList * IntList::getTail(IntList Xs) const
{
    return Xs.tail;

}

/*
 ===================================================================
 Function: getTail
 Parameters: pointer to IntList
 Return: pointer to IntListP
 Description: return pointer to value following head in the IntList
 ===================================================================
 */
IntList * IntList::getTail(IntList *Xs) const
{
    return Xs->tail;

}
/*
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                   Functions
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
/*
 ===================================================================
 Function: isEmpty
 Parameters: IntList
 Return: bool
 Description: Checks to see if the IntList is empty
 ===================================================================
 */

bool IntList::isEmpty(IntList Xs) const
{
    if(Xs.tail == NULL)
        return true;
    else
        return false;
}


/*
 ===================================================================
 Function: isEmpty
 Parameters: IntList
 Return: bool
 Description: Checks to see if the IntList is empty
 ===================================================================
 */

bool IntList::isEmpty(IntList * Xs) const
{
    if(Xs->tail == NULL)
        return true;
    else
        return true;
}


/*
 ===================================================================
 Function: cons
 Parameters: int value for head, IntList value for tail
 Return: IntList with new head added
 Description: Add int as new head to IntList
 ===================================================================
 */

IntList * IntList::cons(int X, IntList Xs)
{
    return new IntList(X, Xs);

}



/*
 ===================================================================
 Function: app
 Parameters: array of integers, IntList
 Return: IntList
 Description: returns IntList with all ints in array added to end of IntList passed
 append starting with the last int in the array
 ===================================================================
 */

IntList * IntList::app(int xs [], IntList Ys, int arraySize)
{
    IntList Zs = Ys;
    IntListPtr ZsPtr = &Zs;
    for (int index = arraySize -1; index >= 0; index--)
    {
        ZsPtr = cons(xs[index], Zs);

    }

    return ZsPtr;
}

/*
 ===================================================================
 Function: toInts
 Parameters: IntList
 Return: IntStack
 Description: adds and IntList onto an IntStack
 ===================================================================
 */
IntStack * IntList::toInts(IntList Xs)
{
    IntListPtr tailPtr = Xs.tail;
    IntListPtr xsPtr = &Xs;
    IntStack is;
    while(!isEmpty(Xs))
    {
        is.push(Xs.head);
        xsPtr = tailPtr;
        tailPtr = Xs.tail;

    }
    return &is;
}

/*
 ===================================================================
 Function: len
 Parameters: IntList
 Return: int
 Description: returns an int with the number of ints in the IntList
 ===================================================================
 */
int IntList::len(IntList Xs) const
{
    int size = 0;
    IntListPtr tailPtr = Xs.tail;
    IntList copy = Xs;
    IntListPtr copyPtr = &Xs;

    while (copyPtr != NULL)
    {
        size++;

        copyPtr = tailPtr;
        tailPtr = copy.tail;

    }
    return size;

}

/*
 ===================================================================
 Function: toString
 Parameters: none
 Return: string
 Description: not really sure what this does
 ===================================================================
 */
std::string IntList::toString()
{
//    return toInts(this).toString();
    std::string str = "what?";
    return str;
}


/*
 ===================================================================
 Function:
 Parameters:
 Return:
 Description:
 ===================================================================
 */

/*
 ===================================================================
 Function:
 Parameters:
 Return:
 Description:
 ===================================================================
 */


/*
 ===================================================================
 Function:
 Parameters:
 Return:
 Description:
 ===================================================================
 */

