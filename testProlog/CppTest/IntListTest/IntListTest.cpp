# include <iostream>
#include <cstdio>
#include "IntList.h"
#include "stdafx.h"

using namespace std;


int main(int argc, char ** argv) {

	IntList L1(1);
	IntList L2(2, &L1);
	IntList L3(3, &L2);
	cout << IntList::getHead(L1)<<endl<<IntList::getHead(L2)<<endl<<IntList::getHead(L3)<<endl;
	
	return 0;
}


/*
Output =[3,2,1]
*/
