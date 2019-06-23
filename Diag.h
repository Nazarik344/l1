#pragma once
#include "Matrices.h"

using namespace std;

class Diag : public Matrices {
public:
	int *a;
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
};

class DiagFactory : public AbstFactory {
public:
	DiagFactory() : AbstFactory(2) { }

	Matrices* Create(int key) {
		if (key == mark)
			return new Diag;
		else
			return nullptr;
	}
};