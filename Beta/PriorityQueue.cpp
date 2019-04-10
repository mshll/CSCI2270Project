

#include <stdio.h>
#include "PriorityQueue.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Purpose: constructor
PriorityQueue::PriorityQueue(int queueSize){
    
    maxSize = queueSize;
    currentSize = 0;
    
    queuePointer = new patientNode[queueSize];
    
}

// Purpose: deconstructor
PriorityQueue::~PriorityQueue(){
    
    delete [] queuePointer;
    
    queuePointer = 0;
    maxSize = 0;
    currentSize = 0;
    
}

// Purpose: enqueue
void PriorityQueue::enqueue (std::string name, int esi){
    
    if (isFull()) {
        cout << "Heap full, cannot enqueue" << endl;
        return;
    }
    
    
    patientNode node;
    node.name = name;
    node.esi = esi;
    
    queuePointer[currentSize] = node;
    heapMax(currentSize);
    currentSize++;
    
    
}

//Purpose: dequeue
void PriorityQueue::dequeue(){
    
    if (isEmpty()) {
        cout << "Heap empty, cannot dequeue" << endl;
        return;
    }
    
    queuePointer[0] = queuePointer[currentSize-1];
    heapMin(0);
    currentSize--;
    
}

// return: patient node at the front of the priority queue
patientNode PriorityQueue::peek(){
    
    if (isEmpty()) {
        cout << "Heap empty, nothing to peek" << endl;
    }
    
    return queuePointer[0];
    
}

//return: true if queue is full, false otherwise
bool PriorityQueue::isFull(){
    
    return (currentSize==maxSize);
    
}

// return: true if queue is empty, false otherwise
bool PriorityQueue::isEmpty(){
    
    return (currentSize==0);
    
}



//Private functions:

//Purpose: maintain heap properties by swapping node with parent if necessary
void PriorityQueue::heapMax(int nodeIndex){
    
    while ((hasParent(nodeIndex)) && (queuePointer[getParentIndex(nodeIndex)].esi > queuePointer[nodeIndex].esi))
    {
        
        
        /* SWAPPING */
        int parentIndex = getParentIndex(nodeIndex);
        patientNode temp = queuePointer[parentIndex];
        queuePointer[parentIndex] = queuePointer[nodeIndex];
        queuePointer[nodeIndex] = temp;
        /*          */
        nodeIndex = getParentIndex(nodeIndex);
        
        
    }
    
}

// Purpose: maintain heap properties by swapping node with child if necessary
void PriorityQueue::heapMin(int nodeIndex){
    
    
    
}

