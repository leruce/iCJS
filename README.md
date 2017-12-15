2017 Project for CSCE 5430

Group Members:
Garrett Addington Leruce


Colleen Vanderbilt //Dropped

Charles Goff

Arafat Hasan
Md Khorrom Khan
Aashis Karki

Project Purpose:

We are porting the iProlog code into a C++ Verison.

The goal is to correctly port iProlog to be runned using GCC.
We want to be able run prolog code using C++ engine.


Currently main code is the main.cpp to run the code yo can just
c++ compiler to compile the main.cpp

Current Progress:

IntList: Done

IntStack: Done

IntMap: Done

Clause: Done

Spline: Done

IMap: Done

Toks: Done

Engine: Need to debug as well finish ShowTerm

Prog: Need to Work On (Need to finish the other first) 11/25

Do not need 40% of the code. Splitolater/customer/streamsupport removed

ObStack: Done (Vector provide all the functions ie pop_back/push_back/back)


Current Task:
So we can work on Prog.

Work Order:
Prog -> showTerm -> DEBUGGING PROCESS

~150 Lines left to translate


TO RUN THE CODE:

Download the this Resp.

Make sure you have Boost installed

Run the CMake file

Make sure you use the iProlog's converter and run it on any files you need to get the .nl file

Proceed to run the code given by the cmake with the arguement such as add.pl or queens.pl

Other option, 
go to that folder
https://github.com/leruce/iCJS/tree/master/cProlog/cmake-build-debug


Run cProlog.exe in the commandline with one given arguement such as add.pl or queen.pl as long you have the files in that dir.

You also just upload the project into the CLion and run the code there with it inbuild build/run
