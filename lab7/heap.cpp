#include "heap.h"

Heap::Heap()
{
    
    heap = new string[INIT_SIZE];
	heapSize = 0;
}


Heap::Heap(string list[], int listSize)
{
    
    heap = new string[listSize+1];

	//remember our implementation of a
    //heap starts at 1 not zero, so
    //we store a sentinal value at 0
    //this is not ideal as we could support
    //the null string, so it is best to
    //remember index 0 is not used
	heap[0]="";

    
    //copy the unsorted list over
	for(int i=0; i < listSize; i++)
	{
		heap[i+1] = list[i];
	}
	
	heapSize = listSize;

    //use the build heap function
    //to make it a heap
	buildHeap();

}

//doesn't really work
//as the upHeap function
//is not implemented as it
//is nearly the same as the
//down heap funciton

void Heap::insert(string x)
{
    
    if(heapSize >= maxCapacity)
    {
        expand();
    }
    
	//location to insert is heapSize+1 
	//(Recall, 0th location not used)
	heap[heapSize+1] = x;
	heapSize++;
    
	//heapsize points to index of last element now
	//reheap or upHeap to fix
	upHeap(heapSize);

}

string Heap::removeMin()
{
   string min = heap[1]; 
   heap[1] = heap[heapSize];
   heapSize--;

   downHeap(1);	//downheap from root
   return min;
}

int Heap::size()
{
	return heapSize;
}



void Heap::downHeap(int location)
{
    string temp = heap[location];
    int left = leftChild(location);
    int right = rightChild(location);

    if (heapSize < left) {
    	return;
   
    } else if ((heapSize == left) &&
    	       (heap[location] > heap[left]) ){
    	
    	//swap left and parent
		heap[location] = heap[left];
		heap[left] = temp; 

		downHeap(left);  //recurse!
    
    } else if ( (heapSize >= right) &&
			  ( (heap[location] > heap[left]) ||
			    (heap[location] > heap[right]) ) ) {

		if (heap[right] > heap[left]) {
		
			//swap left and parent
			heap[location] = heap[left];
			heap[left] = temp; 

			downHeap(left);  //recurse!
		
		} else {
			
			//swap right child and parent
			heap[location] = heap[right];
			heap[right] = temp;

			downHeap(right);	 //recurse!			
		}
	}
}

void Heap::upHeap(int location)
{
	string temp;

	if ((location <= heapSize) &&
        (heap[location] < heap[parent(location)])) {
		
		//swap child and parent
		temp = heap[location];
		heap[location] = heap[parent(location)];
		heap[parent(location)] = temp;

		upHeap(parent(location)); //recurse
	}
}	

void Heap::buildHeap()
{
    for (int i = heapSize/2; i > 0; i--) {
    	downHeap(i);
    }
}

int Heap::leftChild(int index)
{
	return index*2;
}
int Heap::rightChild(int index)
{
	return index*2+1;

}
int Heap::parent(int index)
{
	return index/2;
}


//same old expand funciton, copying
//each element preserves the heap property
void Heap::expand()
{
    string *temp = new string[maxCapacity*2];
    
    for (int i = 0; i < heapSize+1; i++) {
        temp[i] = heap[i];
    }
    maxCapacity = maxCapacity*2;
    
    delete[] heap;
    heap = temp;
}

