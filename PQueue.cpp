/** CS515 10P
 File: PQueue.cpp
 Name: Theodore Belanger
 Section: 1
 Date: 11/21/2014
*/ 
#include <cstdlib>
#include <cassert>

using namespace std;

/**
 * private:
    int _size; // number of queue elements
    T _array[MAX_SIZE+1]; // the heap array, items are stored starting at index 1
    void buildHeap(); // linear heap construction
 */ 
 
// default constructor, construct an empty heap				            //This is done 
template< class T, int MAX_SIZE >
PQueue< T, MAX_SIZE >::PQueue()  
{
	_size = 0; 
}

// construct a heap from an array of elements;
template< class T, int MAX_SIZE >
PQueue< T, MAX_SIZE >::PQueue(T* items, int size) 
{
	_size = 0;
	for( int i = 1; i <= size; i++ )
	{
		_size++;
		_array[i] =  items[i-1];
	} 
	buildHeap();
}

// insert an item; duplicates are allowed.
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::insert(T t) 
{
	//==-=-=-=-= check max =-=-=--=-
	if( _size == 100 )
	{
		cout<<"Error: There is no more space to add things."<<endl;
		return; 
	}
	//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	_size++;
	
	_array[ _size ] = t;
	moveUp();
}
	//=-==-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=
	
	//=-=-=- For Testing =-=-=-=-=-
    //cout<<"Testing B4 MU: inside pQueue insert-> dumping PQ"<<endl;
    //for( int i = 1; i <= _size; i++ )
	//    cout<< _array[i].freq<< " : ";
	// cout<<endl;
	////=-=-=-=-=-==-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-
	
	//=-==-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-
	//=-=-=- For Testing =-=-=-=-=-
    //cout<<endl;
    //cout<<endl;
    //cout<<"Testing AF MU: inside pQueue insert-> dumping PQ"<<endl;
    //for( int i = 1; i <= _size; i++ )
    //{
		 //if( _array[ i].data != '\0' )
		 //{
		 //	  cout<< _array[i].data<< " : ";
		 //}
		 //else
		 //{
			// cout<< _array[i].freq<< " ; "; 
	     //}
	//}
	//cout<<endl;
	//=-=-=-=-=-==-=-=-=-=-=-=-=--=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-=-=-=-

// return the smallest item from the queue
template< class T, int MAX_SIZE >
T PQueue< T, MAX_SIZE >::findMin() 
{
	//cout<< "Inside PQ: Find min " << _array[1].freq <<endl;
	return _array[1];
}

// remove the smallest item from the queue
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::deleteMin() 
{
	//=-==-=- if empty ==-=-=--
	if( _size == 0 )
	{
		cout<<"There is nothing left to delete"<<endl; 
		return;
	}
	//=-=-=-=- else -=-=-=-=-=-
	
	_array[1] = _array[_size];
	_size--;
	if( _size > 1 )
	{
		moveDown( 1 );
	}
}

// test if the priority queue is logically empty
template< class T, int MAX_SIZE >
bool PQueue< T, MAX_SIZE >::isEmpty() 
{
	if( _size == 0 )
		return true;
	
	return false;
}

// return queue size
template< class T, int MAX_SIZE >
int PQueue< T, MAX_SIZE >::size()  
{
	return _size;
}

// linear heap construction	
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::buildHeap() 
{
	for(int i = _size; i > 0; i--)
	{
		moveDown( i );
	}
}

// move down element at given index
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::moveDown(int i)  
{
	int leftChild = i*2;
	int rightChild = i*2+1;
	
	
	//=-=-=-= Base Case =-=-=-=-
	if( leftChild >= _size+1 )
		return;
	//=-=-=-=-=-=-=-=-=-=-=-=-=
	
	if( _array[i] > _array[leftChild] )
	{
		if( rightChild < _size+1 &&  _array[leftChild] > _array[rightChild] )
		{
			T locSave = _array[i];
			_array[i] = _array[rightChild]; 
			_array[rightChild] = locSave;
			moveDown(rightChild); 
		}
		else
		{
			T locSave = _array[i];
			_array[i] = _array[leftChild]; 
			_array[leftChild] = locSave;
			moveDown(leftChild); 
		}
	}
	else if( rightChild < _size+1 &&  _array[ i ] > _array[rightChild] )
	{
			T locSave = _array[i];
			_array[i] = _array[rightChild]; 
			_array[rightChild] = locSave;
			moveDown(rightChild); 
	}
}

// move up the last element in the heap array
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::moveUp() 
{
	int place = _size;
	int parent = _size/2;
	T hold = _array[ 1 ];
	while( place > 1 && _array[parent] > _array[place] )
	{
		hold = _array[parent];
		_array[parent] = _array[place];
		_array[place] = hold;
		place = parent;
		parent = place/2; 
	}
}
