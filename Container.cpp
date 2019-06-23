#include "Container.h"

List::List() : len(0) { }

void List::Clear()
{
	Node *ptr = head, *ptr2;
	for (int i = 0; i <= len-1; i++) {
		if (i != len-1)
			ptr2 = ptr->next;
		delete(ptr);
		ptr = ptr2;
	}
	len = 0;
}

void List::In(ifstream &ifst) {

	while (!ifst.eof()) {
		Node *el = new Node();
		if ((el->data = AbstFactory::In(ifst)) != 0) {
			len++;
		}
		if (len == 1) {
			head = tail = el;
		} else {
			tail->next = el;
			tail = el;
			el->next = nullptr;
		}
	}
}

void List::Out(ofstream &ofst) {

	Node *ptr = head;
	ofst << "List contents " << len << " elements." << endl;
	for (int i = 0; i < len; i++, ptr = ptr->next) {
		ofst << i << ": ";
		ptr->data->Out(ofst);
	}

}
