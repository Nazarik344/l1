#include "TwoD.h"

void TwoD::InData(ifstream &ifst) {
	ifst >> n >> m;
	amountofelements = n*m;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ifst >> a[i][j];
		}
	}
}

void TwoD::Out(ofstream &ofst) {
	ofst << "This is a TwoD Matrix with " << amountofelements << " elements: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ofst << a[i][j] << " ";
		}
		ofst << "\n";
	}
}

namespace {
	TwoDFactory twodf;
}
