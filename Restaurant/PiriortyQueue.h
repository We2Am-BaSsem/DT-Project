#pragma once
#include "PirorityNode.h"

template <typename Type>
class PiriorityQueue
{
private:
	//Data Members :
	PirorityNode <Type>* Front;

public:
	PiriorityQueue();
	bool enqueue(const Type& newEntry, int priority);
	bool dequeue(Type& Entry);
	bool IsEmpty()const;
	bool peekFront(Type& frntEntry)const;
	Type* ToArray(int& count);
	~PiriorityQueue();

};

//////////////////////////////////////////////////////////////////////////////////////////////

//Functions Implementations :


// i-Constructor (For intializing the front pointer to NULL

template <typename Type>
PiriorityQueue<Type>::PiriorityQueue()
{
	Front = nullptr;
}


// ii-enqueue : bool Function as an indication that the proccess happens successfully 

template <typename Type>
bool PiriorityQueue<Type>::enqueue(const Type& newEntry, int priority)
{
	PirorityNode<Type>* Temp, * Q;
	Temp = new PirorityNode<Type>(newEntry, priority);

	if (Front == nullptr || priority > Front->GetPiriorty())
	{
		Temp->SetNode(Front);
		Front = Temp;
	}
	else
	{
		Q = Front;
		while (Q->GetNext() != nullptr && Q->GetNext()->GetPiriorty() >= priority)
			Q = Q->GetNext();
		Temp->SetNode(Q->GetNext());
		Q->SetNode(Temp);
	}
	return true;
}


// iii-dequeue (Send tha data to a parameter and then delete the Node) "Pop"

template <typename Type>
bool PiriorityQueue<Type>::dequeue(Type& Entry)
{
	PirorityNode<Type>* Temp;
	if (Front == nullptr)
		return false;
	Temp = Front;
	Entry = Temp->GetData();
	Front = Front->GetNext();
	delete Temp;
	return true;
}


// iv- Is Empty function : 

template <typename Type>
bool PiriorityQueue<Type>::IsEmpty()const
{
	if (Front) return false;
	return true;
}


//v-peekFront:

template <typename Type>
bool PiriorityQueue<Type>::peekFront(Type& frntEntry) const
{
	if (IsEmpty())
		return false;

	frntEntry = Front->GetData();
	return true;

}

// vi- To Array :

template <typename T>
T* PiriorityQueue<T>::ToArray(int& count)
{
	count = 0;

	if (!Front)
		return nullptr;
	//counting the no. of items in the Queue
	PirorityNode<T>* p = Front;
	while (p)
	{
		count++;
		p = p->GetNext();
	}


	T* Arr = new T[count];
	p = Front;
	for (int i = 0; i < count; i++)
	{
		Arr[i] = p->GetData();
		p = p->GetNext();
	}
	return Arr;
}

template<typename Type>
inline PiriorityQueue<Type>::~PiriorityQueue()
{

}
