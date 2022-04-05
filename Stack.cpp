#include "Stack.h"

// StackNode class Implementation

template <typename NODE_TYPE> 
StackNode<NODE_TYPE>::StackNode(const NODE_TYPE &info)
	:data(info), next(0)
{
	
}

template <typename NODE_TYPE> 
NODE_TYPE StackNode<NODE_TYPE>::getData()const
{
	return data;
}


// Stack class Implementation

template <typename NODE_TYPE> 
Stack<NODE_TYPE>::Stack()
	:top(0)
{
	
}

template <typename NODE_TYPE> 
Stack<NODE_TYPE>::~Stack()
{
	if(!isEmpty()){
		StackNode<NODE_TYPE> *currentPtr = top;
		StackNode<NODE_TYPE> *tempPtr;
		while(currentPtr){
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		
		}		
	}
}	

template <typename NODE_TYPE> 
bool Stack<NODE_TYPE>::push(const NODE_TYPE &value)
{
	StackNode<NODE_TYPE> *newNodePtr = getNewNode(value);

	if (newNodePtr){
		newNodePtr->next = top;
		top = newNodePtr;
		return true;
	}
	return false;	
}

template <typename NODE_TYPE> 
bool Stack<NODE_TYPE>::pop(NODE_TYPE &value)
{
	
	if (!isEmpty()){
		StackNode<NODE_TYPE> *tempPtr = top;
		value = top->data;
		top = top->next;
		delete tempPtr;
		return true;
	}
	return false;	
}

template <typename NODE_TYPE> 
bool Stack<NODE_TYPE>::isEmpty()const
{ 
	return (top == 0);	
}

template <typename NODE_TYPE> 
bool Stack<NODE_TYPE>::getTop(NODE_TYPE &value)const
{ 
	bool notEmptyStack = !isEmpty();
	
	if (!isEmpty()){
		value = top->data;
		return true;
	}
	return false;	
}

template <typename NODE_TYPE>
StackNode<NODE_TYPE>* Stack<NODE_TYPE>::getNewNode(const NODE_TYPE &value)
{
	return new StackNode<NODE_TYPE>(value);
}
