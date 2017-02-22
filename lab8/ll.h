#ifndef LL_H
#define LL_H

#include "node.h"

class LL{
	public:
		LL();
		~LL();
		LL(int *arr, int size);
                LL(const LL &to_copy);
		void insert(int x);
		void print();
		void merge(LL to_merge);
		bool isEmpty();
	private:
		Node* head;
};

#endif

