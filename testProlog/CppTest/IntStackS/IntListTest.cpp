# include <iostream>
#include <cstdio>
#include "IntList.h"
#include "stdafx.h"

using namespace std;

//IntList(int head);

int main(int argc, char ** argv) {

	IntList L1(1);
	IntList L2(2, &L1);
	cout<<IntList::getHead(&L2);
	
	
	
	return 0;
}


