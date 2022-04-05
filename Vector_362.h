/************************************************************************

	File:		myVector_362.h

	Author:		Michael Davis

	Date:		March 10, 2021

	Purpose:	This file contains the definition of the myVector class

************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <istream>
#include <ostream>
#include <cassert>
using namespace std;

class my_Vector 
{
public:
	
	explicit my_Vector(int cap = 0);

	my_Vector(int cap, const int& init_Val);

	my_Vector(const my_Vector& v);

	~my_Vector();

	my_Vector(my_Vector&& v);

	my_Vector& operator=(const my_Vector& v);
	my_Vector& operator=(my_Vector&& v);

	int getSize() const { return mSize; }

	void output(ostream& strm) const;
	void input(istream& strm);

	void insert(const int& pos, const int& val);
	void pushback(const int elem);
	void setSize(int size);
	
private:

	//Private Faciliator functions
	void reserve(int cap);
	void makeEmpty();
	void makeCopy(const my_Vector& v);

	int mSize;
	int mCapacity;
	int* mData;

};

my_Vector::my_Vector(int cap)
{
	if (cap > 0) // Creates a defualt value or one paramter constructor
	{
		mSize = 0;
		mCapacity = (int)pow(2, ceil(log2(cap)));
		reserve(mCapacity);

		cout << "Default/Default Parameter Constructor: 0x" << this;
		cout << "\tmData: 0x" << mData << endl;
		cout << endl;
	}
};

my_Vector::my_Vector(int cap, const int & init_Val)
{
	if (cap > 0)
	{
		mSize = 0;
		mCapacity = (int)pow(2, ceil(log2(cap))); // Uses two paramter constructor to create vector 
		reserve(mCapacity);
		for (int i = 0; i < mCapacity; ++i)
		{
			mData[i] = init_Val;
		}
	}
	cout << "Initial Value Constructor: 0x" << this;
	cout << "\tmData: 0x" << mData << endl;
}

my_Vector::my_Vector(const my_Vector & v)
{
	makeCopy(v);
	cout << "Copy Constructor: 0x" << this << "\tmData: 0x" << mData << endl;
}

my_Vector::~my_Vector()
{
	cout << "Destructor: 0x" << this << "\tmData: 0x" << mData << endl;
	makeEmpty();
}

my_Vector::my_Vector(my_Vector && v)
{
	cout << "Move Constructor before move: " << this << "\tmData: 0x" << mData << endl;

	mSize = v.mSize;
	mCapacity = v.mCapacity;
	mData = v.mData;

	cout << "Move Constructor after move: " << this << "\tmData: 0x" << mData << endl;
	cout << endl;

	v.mSize = v.mCapacity = 0;
	v.mData = nullptr;
}

my_Vector & my_Vector::operator=(const my_Vector & v)
{
	if (this != &v)
	{
		makeCopy(v);
	}
	cout << "Assignment Operator: 0x" << this << "\tmData: 0x" << mData << endl;
	return *this;
}

my_Vector & my_Vector::operator=(my_Vector && v)
{
	if (this != &v)
	{
		// Free the existing resource.
		delete[] mData;

		// Copy the data pointer and its length from the
		// source object.
		mData = v.mData;
		mSize = v.mSize;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		v.mData = nullptr;
		v.mSize = 0;
	}
	return *this;
}

void my_Vector::insert(const int & pos, const int & val)
{
		if (mCapacity <= mSize)  // Create some space if it doesn't have enough to take another element..
			reserve(mSize);
		mSize++;
		cout << "Before Inserting: " << this << "\tmData: 0x" << mData << endl;
		for (int i = mSize - 1; i > pos; i--)  //  Shift all the elements one step towards right, beginning from "pos"+1..
		{
			mData[i] = mData[i - 1];
		}
		mData[pos] = val;
		cout << "After Inserting: " << this << "\tmData: 0x" << mData << endl;
}

void my_Vector::pushback(const int elem)
{
	if (mSize == mCapacity)
	{
		if (mCapacity == 0)
		{
			mCapacity++;
		}
		else
			mCapacity = 2 * mCapacity;
	}
	int i = mSize++;
	mData[i] = elem;
}



	void my_Vector::setSize(int size)
{
	if (mSize < mCapacity)
		mSize = size;
	else
	{
		makeEmpty();
		mCapacity = (int)pow(2, ceil(log2(size)));
		reserve(mCapacity);
		mSize = size;
	}
}

void my_Vector::reserve(int cap)
{
	mCapacity = cap;
	mData = new int[mCapacity];
	
}// reserve(...)

void my_Vector::makeEmpty()
{
	if (mCapacity > 0 && mData)
	{
		delete[] mData;
		mSize = mCapacity = 0;
		mData = nullptr;
	}
}

void my_Vector::makeCopy(const my_Vector & v)
{
	// delete and allocate mData if different sizes
	if (mCapacity != v.mCapacity)
	{
		makeEmpty();
		reserve(v.mCapacity);
	}

	// set size and capacity
	mSize = v.mSize;
	mCapacity = v.mCapacity;

	// copy all integers from v
	for (int i = 0; i < mCapacity; ++i)
		mData[i] = v.mData[i];
}

my_Vector makeIntVector( int val)
{
	my_Vector v(val);

	return v;
}

void my_Vector::output(ostream& strm) const
{
	cout << "( ";
	for (int i = 0; i < mSize - 1; ++i)
		cout << mData[i] << ", ";
	if (mSize > 0)
		cout << mData[mSize - 1];
	cout << " )";
}

void my_Vector::input(istream& strm) {

	//	Clear out the old elements
	makeEmpty();

	//	Check for initial parenthesis
	char c;
	strm >> c;
	assert(c == '(');

	//	Check for final parenthesis
	strm >> c;
	if (c == ')')
		return;						// Vector is empty

	strm.putback(c);

	//	Allocate memory for 2 element
	int numRead = 0;
	reserve(2);

	//	Read elements until final parenthesis is encountered
	while (c != ')')
	{
		//	See if array is full
		if (numRead == mCapacity)
			reserve(2 * mCapacity);		// Double the size

		//	Read the element
		strm >> mData[numRead++];
		++mSize;
		strm >> c;						// Read the comma
		assert(c == ',' || c == ')');
	}
}

ostream& operator<<(ostream& strm, const my_Vector& v)
{
	v.output(strm);
	return strm;
}

istream& operator>>(istream& strm, my_Vector& v) {
	v.input(strm);
	return strm;
}

#endif

