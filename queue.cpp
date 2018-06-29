#include <iostream>
#include "stack.cpp"

using namespace std;


template <typename T>
class Queue
{
private:
	Stack<T>  stack1;
	Stack<T>  stack2;

public:

	//Constructor with Default Parameters
	Queue( int s = 10 ): stack1(s),stack2(s)
	{

	}


	//Destructor
	~Queue()
	{
	}


	//To check whether the queue is empty
	bool IsEmpty()
	{
		return (stack1.IsEmpty() && stack2.IsEmpty());
	}


	//To check whether the queue is full
	bool IsFull()
	{
		return (stack1.IsFull());
	}


	//Copy Constructor
	Queue(Queue& obj)
	{
		stack1 = obj.stack1;
		stack2 = obj.stack2;
	}


	//Overloaded Assignment operator
	Queue& operator = (Queue& rhs)
	{
		if(this != &rhs)
		{
			stack1 = rhs.stack1;
			stack2 = rhs.stack2;
		}

		return *this;
	}


	/*Only Stack 1 is used to take the inputs. It will store all the inputs. Each element
	  is pushed into Stack 1. Its acting like an inbox.*/
	bool Enqueue(T& data)
	{
		if(!IsFull())
		{
			stack1.Push(data);
			return true;
		}

		return false;
	}


	/*If stack2 is empty then pop all elements from stack 1 and push them in
	  stack 2. Then pop the head the stack2. This will perform one dequeue operation.
	  Now if stack2 contains some elements so if the user calls for dequeue then simply
	  the head of stack2 will be popped. This will continue until the stack 2 becomes empty.
	  After it becomes empty then again all the elements from stack 1 are copied to stack 2.
	  And the same process is repeated.*/
	bool Dequeue(T& data)
	{
		T temp;

		if(!IsEmpty())
		{
			if(stack2.IsEmpty())
			{
				while(!stack1.IsEmpty())
				{
					stack1.Pop  (temp);
					stack2.Push(temp);
				}
			}

            stack2.Pop(data);
            return true;
		}

		return false;
	}


	void displayFunctions()
	{
		cout << "\n\nThe class Queue has the following functions : ";
		cout << "\n1)Enqueue \n2)Dequeue \n3)IsEmpty \n4)IsFull ";
	    cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
	}

	void displayQueue()
	{
		T temp;
		cout << "\n\nThe queue is : ";


		while( !IsEmpty())
		{
			Dequeue(temp);
			cout << endl << temp;
		}
	}
};

//-------------Class Ended--------------------------------


void driver()
{
	int size;
	cout << "Enter the maxsize of the queue : ";
	cin >> size;
	Queue<int> que1(size);

	int userInput = 0;
	int data;

	while (userInput != -1)
	{
		que1.displayFunctions();
		cin >> userInput;

		if (userInput == 1)
		{
			cout << "\nEnter the data to insert into the queue : ";
			cin  >> data;

			if ( que1.Enqueue(data) )
				cout << "\nEnqueue Successful.";
			else
				cout << "\nEnqueue Unsuccessful.";
		}

		else if (userInput == 2)
		{
			if( que1.Dequeue(data) )
				cout << "\nThe Dequeued data item is : " << data;
			else
				cout << "\nDequeue Unsuccessful.";
		}

		else if (userInput == 3)
		{
			if (que1.IsEmpty())
				cout << "\nThe queue is empty.";
			else
				cout << "\nThe queue isn't empty.";
		}

		else if (userInput == 4)
		{
			if (que1.IsFull())
				cout << "\nThe queue is full.";
			else
				cout << "\nThe queue isn't full.";
		}
	}


	cout << "\nTesting the copy constructor :";
	Queue<int> que2 = que1;

	cout << "\nqueue 2 is a copy of queue 1 constructed through Copy Constructor.";

	if(! que1.IsEmpty() )
		que1.displayQueue();
	else
		cout << "\nqueue 1 is empty.";

	if(! que2.IsEmpty() )
		que2.displayQueue();
	else
		cout << "\nqueue 2 is empty.";

	cout << "\n\nSimilarly the overloaded assignment operator can be tested. " << endl;
}




int main ()
{
	driver();
	return 0;
}
