#include "ll.h"
#include "node.h"
#include <iostream>

using namespace std;

LL::LL()
{
	head = NULL;
}
	
LL::LL(int *arr, int size)
{
	head = NULL;
	for (int i = 0; i < size; i++) {
		insert(arr[i]);
	}
}

LL::~LL()
{
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		delete head;
		head = head->next;
	} 
}

LL::LL(const LL &to_copy)
{
        if (to_copy.head != NULL) {
                Node *temp = to_copy.head;
                Node *copied = new Node;
                copied->value = temp->value;
                copied->next = NULL;
                head = copied;
                temp = temp->next;
                while (temp != NULL) {
                        copied->next = new Node;
                        copied = copied->next;
                        copied->value = temp->value;
                        copied->next = NULL;
                        temp = temp->next;
                }
        }
}


void LL::print()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

bool LL::isEmpty()
{
	return head == NULL;
}

void LL::merge(LL to_merge)
{
    //case 1 beginning
	//case 2: middle
	//case 3: end
	//case4: empty

	if (to_merge.isEmpty()) {
		return;
	} 

	Node* iter = to_merge.head;

	while (iter != NULL) {
		cerr << "if iter != NULL, why does this sf?" << iter->value << endl;
		insert(iter->value);
		iter = iter->next;
	}
}

//inserts in proper order
void LL::insert(int x)
{
	Node* ins = new Node;
	ins->value = x;	
	
	if (head == NULL) {
		//create a new beginning of list
		head = ins;
		ins->next = NULL;
		return;
	}
    else if (x <= head->value) {
    
    	ins->next = head;
    	head = ins;
	
	} else {

		Node* iter1 = head;
		Node* iter2 = head->next;

		while (iter2 != NULL && x > iter2->value) {
			
			iter1 = iter1->next;
			iter2 = iter2->next;
		}

		//insert between iter1 and iter2
		iter1->next = ins;
		ins->next = iter2;
	}
}
