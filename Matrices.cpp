#include "Matrices.h"

AbstFactory *AbstFactory::top = nullptr;

AbstFactory::AbstFactory(int m) : mark(m) {
	this->next = top;
	top = this;
}

Matrices* AbstFactory::Make(int key) {

	Matrices* f = nullptr;
	AbstFactory* tmp = top;

	while (tmp) {
		f = tmp->Create(key);
		if (f) {
			f->mark = key;
			return f;
		}
		tmp = tmp->next;
	}
	return nullptr;

}

Matrices* AbstFactory::In(ifstream &ifst) {

	Matrices *ptr = nullptr;
	int k;
	ifst >> k;
	ptr = Make(k);
	if (ptr)
		ptr->InData(ifst);
	return ptr;

}
