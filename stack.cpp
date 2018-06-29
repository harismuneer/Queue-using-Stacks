#include <iostream>
using namespace std;

//Templatized Stack Class
template <typename T>

class Stack
{

private:

	T*  stk;

	int stkPtr;
	int maxSize;

public:

	//Constructor with Default Parameters
	Stack (int s = 10)
	{
		if(s<=0)
			s = 10;

		stk = new T [s];
		maxSize = s;
		stkPtr = -1;
	}


	//Destructor
	~Stack ()
	{
		if(stk)
			delete stk;
	}


	//Top Function to view the data on the top of the Stack
	bool Top (T& data)
	{
		if(!IsEmpty())
		{
			data =  stk [stkPtr];
			return true;
		}

		return false;
	}


	//Function to check if Stack is empty
	bool IsEmpty ()
	{
		return (stkPtr == -1);
	}


	//Function to check if Stack is full
	bool IsFull ()
	{
		return (stkPtr == maxSize -1);
	}


	//Function to push data into the top of the Stack
	bool Push (T& data)
	{
		if(!IsFull())
		{
			stk [++stkPtr] = data;
			return true;
		}

		return false;
	}


	//Function to pop data from the top of the Stack
	bool Pop(T& data)
	{
		if(!IsEmpty())
		{
			data = stk [stkPtr--];
			return true;
		}

		return false;
	}


	//Copy Constructor
	Stack(Stack& obj)
	{
		stk = new T [obj.maxSize];

		for (int i = 0; i < obj.maxSize; ++i)
		{
			stk[i] = obj.stk[i];
		}

		maxSize = obj.maxSize;
		stkPtr = obj.stkPtr;
	}


	//Overloaded Assignment Operator
	Stack& operator = (Stack& rhs)
	{
		if(this != &rhs)
		{
			if(stk)
					delete stk;

			stk = new T [rhs.maxSize];

			for (int i = 0; i < rhs.maxSize; ++i)
			{
				stk[i] = rhs.stk[i];
			}

			maxSize = rhs.maxSize;
			stkPtr = rhs.stkPtr;
		}

		return *this;
	}


	void displayFunctions()
	{
		cout << "\nThis class Stack has the following functionality : ";
		cout << "\n1)Push \n2)Pop \n3)Top \n4)IsEmpty \n5)IsFull ";
		cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
	}


	void displayStack()
	{
		T temp;
		cout << "\nThe stack is : ";


		while( !IsEmpty())
		{
			pop(temp);
			cout << endl << temp;
		}
	}

};
//--------------Ended Stack Class---------------------
