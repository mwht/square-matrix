#include "SquareMatrix.hpp"
#include <iostream>

using namespace std;

SquareMatrix::SquareMatrix(unsigned int size,double initvar) {
	data = new double[size*size];
	dim = size;
	for(unsigned int i=0;i<size*size;i++) data[i] = initvar;
}

SquareMatrix::~SquareMatrix() {
	delete[] data;
}

unsigned int SquareMatrix::getDimension() {
	return dim;
}

double SquareMatrix::getMax() {
	double curMax = data[0];
	for(unsigned int i=0;i<dim*dim;i++) 
		if(data[i] > curMax) curMax = data[i];
	return curMax;
}

void SquareMatrix::write(unsigned int row,unsigned int col, double var) {
	data[row*dim+col] = var;
}

void SquareMatrix::print() {
	for(unsigned int i=0;i<dim;i++) {
		cout << "[";
		for(unsigned int j=0;j<dim;j++) {
			cout << data[i*dim+j];
			if(j < dim) cout << " ";
		}
		cout << "]" << endl;
	}
}
