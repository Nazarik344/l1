#pragma once
#include "Matrices.h"

struct Node {
public:
	Node *next;
	Matrices *data;
};

class List {
public:
	int len;
	Node *head, *tail;
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void Clear();
	List();
	~List() { Clear(); }
};