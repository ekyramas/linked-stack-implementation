#ifndef STACK_H
#define STACK_H

// forward declaration
template <typename NODE_TYPE> class Stack;

template <typename NODE_TYPE>  class StackNode{
	friend class Stack<NODE_TYPE>;
	public:
		StackNode(const NODE_TYPE &);
		NODE_TYPE getData()const;
	private:
		NODE_TYPE data;
		StackNode<NODE_TYPE> *next;
};
 
template <typename NODE_TYPE>  class Stack{
	public:
		Stack();
		~Stack();
		bool push(const NODE_TYPE &);
		bool pop(NODE_TYPE &);
		bool isEmpty()const;
		bool getTop(NODE_TYPE &)const;
	private:
		StackNode<NODE_TYPE> *top;
		// utility function to allocate new node	
		StackNode<NODE_TYPE>* getNewNode(const NODE_TYPE &); 
};

#endif
