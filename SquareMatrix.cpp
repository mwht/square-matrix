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

double SquareMatrix::read(unsigned int row,unsigned int col) {
	check(row,col);
	return data[row*dim+col];
}

void SquareMatrix::write(unsigned int row,unsigned int col, double var) {
	if(!check(row,col)) return;
	data[row*dim+col] = var;
}

bool SquareMatrix::check(unsigned int row,unsigned int col) {
	if(row < 0 || row > dim-1 || col < 0 || col > dim-1) {
		throw out_of_range();
	}
	return true;
}

void SquareMatrix::print() {
	for(unsigned int i=0;i<dim;i++) {
		cout << "[";
		for(unsigned int j=0;j<dim;j++) {
			cout << data[i*dim+j];
			if(j < dim-1) cout << " ";
		}
		cout << "]" << endl;
	}
}

SquareMatrix& SquareMatrix::operator= (const SquareMatrix& sq) {
	if(this == &sq) return *this;
	delete[] data;
	data = new double[sq.dim*sq.dim];
	dim = sq.dim;
	for(unsigned int i=0;i<dim;i++) {
		for(unsigned int j=0;j<dim;j++) {
			data[i*dim+j] = sq.data[i*dim+j];
		}
	}	
	return *this;
}

SquareMatrix operator- (double d,SquareMatrix& sm) {
	SquareMatrix sq(sm.getDimension(),d);
	for(unsigned int i=0;i<sm.getDimension();i++) {
		for(unsigned int j=0;j<sm.getDimension();j++) {
			sq.write(i,j,d-sm.read(i,j));
		}
	}
	return sq;
}
