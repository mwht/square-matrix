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
	public:
		SquareMatrix();
		SquareMatrix(unsigned int,double);
		~SquareMatrix();
		unsigned int getDimension();
		double getMax();
		void write(unsigned int,unsigned int,double);
		void print();
};

#endif // __SquareMatrix_hpp__
