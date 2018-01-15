#include <iostream>
#include "SquareMatrix.hpp"

using namespace std;

int main() {
	try {
		SquareMatrix sm1(2,5);

		sm1.write(0,0,2.5);
		sm1.print();

		cout << sm1.getDimension() << endl;
		cout << sm1.getMax() << endl;

		SquareMatrix sm2(1,0);
		sm2 = 12-sm1;
		sm2.print();
	} catch(exception& e) {
		cout << "Wystapil wyjatek - " << e.what() << endl;
	} catch(...) {
		cout << "Wystapil nieznany blad." << endl;
	}
	return 0;
}
