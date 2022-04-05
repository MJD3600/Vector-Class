/****************************************************************************

   File:		VectorTester.cpp

   Author:		Michael James Davis

   Date:		March 10, 2021

   Purpose:	To Test all functions of MyVector Class

****************************************************************************/

#include <iostream>
#include <ostream>
#include <cassert>
#include <vector>

#include "Vector_362.h"

using namespace std;


int main() 
{

	int i;

	cout << "Start: Copy Constructor Tester() " << endl;
	cout << "v1(2)" << endl;

	my_Vector v1{ 2 };
	cout << endl;

	cout << "v(v1)" << endl;
	my_Vector v{ v1 };
	cout << endl;

	cout << "Done: Copy Constructor Tester()" << endl;

	cout << endl;

	cout << "***********************************************" << endl;
	cout << "Start: Copy Assignment Tester() " << endl;
	cout << "v2(2), v3" << endl;

	my_Vector v2{ 2 };
	my_Vector v3{ 1 };

	cout << endl << "Copy Assignment: v3 = v2" << endl;

	v3 = v2;

	cout << endl << "Done: Copy Assignment Tester() " << endl;

	cout << "***********************************************" << endl;

	cout << "Start: Testing Move Constructor " << endl;

	cout << "MakeIntVector(2)" << endl;
	makeIntVector(2);
	cout << endl;
	cout << "Done: Testing Move Constructor " << endl << endl;

	cout << "***********************************************" << endl;

	cout << "Start: Testing Move Assignment " << endl << endl;
	cout << "Make v4" << endl << endl;
	my_Vector v4;

	cout << "Move assignment: v4 = makeVector()" << endl << endl;
	v4 = makeIntVector(2);

	cout << "Done: Testing Move Constructor " << endl << endl;

	cout << "***********************************************" << endl;

	cout << "Testing Set Size" << endl;
	cout << "Set v5 size to 5" << endl;
	my_Vector v5;
	
	v5.setSize(5);

	cout << "V1:" << v5 << endl << endl;

	return 0;

}
/*
Start: Copy Constructor Tester()
	v1(2)
	Default / Default Parameter Constructor : 0x008FF978       mData : 0x00CAF000


	v(v1)
	Copy Constructor : 0x008FF964    mData : 0x00CAF118

	Done : Copy Constructor Tester()

	***********************************************
	Start : Copy Assignment Tester()
	v2(2), v3
	Default / Default Parameter Constructor : 0x008FF950       mData : 0x00CAF3B8

	Default / Default Parameter Constructor : 0x008FF93C       mData : 0x00CB0DB8


	Copy Assignment : v3 = v2
	Assignment Operator : 0x008FF93C mData : 0x00CAF620

	Done : Copy Assignment Tester()
	***********************************************
	Start : Testing Move Constructor
	MakeIntVector(2)
	Default / Default Parameter Constructor : 0x008FF7D4       mData : 0x00CAF150

	Move Constructor before move : 008FF840  mData : 0xCCCCCCCC
	Move Constructor after move : 008FF840   mData : 0x00CAF150

	Destructor : 0x008FF7D4  mData : 0x00000000
	Destructor : 0x008FF840  mData : 0x00CAF150

	Done : Testing Move Constructor

	***********************************************
	Start : Testing Move Assignment

	Make v4

	Move assignment : v4 = makeVector()

	Default / Default Parameter Constructor : 0x008FF7D4       mData : 0x00CAF508

	Move Constructor before move : 008FF82C  mData : 0xCCCCCCCC
	Move Constructor after move : 008FF82C   mData : 0x00CAF508

	Destructor : 0x008FF7D4  mData : 0x00000000
	Destructor : 0x008FF82C  mData : 0x00000000
	Done : Testing Move Constructor

	***********************************************
	Testing Set Size
	Set v5 size to 5
	V1 : (-842150451, -842150451, -842150451, -842150451, -842150451)

	Destructor : 0x008FF914  mData : 0x00CA5980
	Destructor : 0x008FF928  mData : 0x00CAF508
	Destructor : 0x008FF93C  mData : 0x00CAF620
	Destructor : 0x008FF950  mData : 0x00CAF3B8
	Destructor : 0x008FF964  mData : 0x00CAF118
	Destructor : 0x008FF978  mData : 0x00CAF000
*/