#include "Diag.h"

void Diag::InData(ifstream &ifst) {
	ifst >> amountofelements;
	a = new int[amountofelements];
	for (int i = 0; i < amountofelements; i++) {
		ifst >> a[i];
	}
}

void Diag::Out(ofstream &ofst) {
	ofst << "This is a Diag Matrix with " << amountofelements << " non-zero elements: \n";
	for (int i = 0; i < amountofelements; i++) {
		for (int j = 0; j < i; j++) {
			ofst << "0 ";
		}
		ofst << a[i] << " ";
		for (int j = i + 1; j < amountofelements; j++) {
			ofst << "0 ";
		}
		ofst << endl;
	}
}

namespace {
	DiagFactory df;
}
