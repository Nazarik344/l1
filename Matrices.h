#pragma once
#include <fstream>

using namespace std;

class Matrices {
public:
	virtual void InData(ifstream &ifst) = 0;
	virtual void Out(ofstream &ofst) = 0;
	virtual ~Matrices() {}
	int mark, amountofelements;
};

class AbstFactory {
public:
	AbstFactory(int m);
	static Matrices* Make(int key);
	static Matrices* In(ifstream &ifst);
	virtual Matrices* Create(int key) = 0;
	static AbstFactory* top;
	AbstFactory* next;
protected:
	int mark;
};