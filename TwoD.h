#pragma once
#include "Matrices.h"

using namespace std;

class TwoD : public Matrices {
public:
	int **a, n, m;
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
};

class TwoDFactory : public AbstFactory {
public:
	TwoDFactory() : AbstFactory(1) { }

	Matrices* Create(int key) {
		if (key == mark)
			return new TwoD;
		else
			return nullptr;
	}
};