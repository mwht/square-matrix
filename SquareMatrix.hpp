#ifndef __SquareMatrix_hpp__
#define __SquareMatrix_hpp__
#include <exception>

using namespace std;

class out_of_range : public exception {
  virtual const char* what() const throw() { return "probowano indeksowac poza zakres"; }
};


class SquareMatrix {
	private:
		double* data;
		unsigned int dim;
		bool check(unsigned int,unsigned int);
	public:
		SquareMatrix();
		SquareMatrix(unsigned int,double);
		~SquareMatrix();
		unsigned int getDimension();
		double getMax();
		void write(unsigned int,unsigned int,double);
		double read(unsigned int,unsigned int);
		void print();
		SquareMatrix& operator= (const SquareMatrix& sq);
};

SquareMatrix operator- (double d,SquareMatrix& sm);

#endif // __SquareMatrix_hpp__
