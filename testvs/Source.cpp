#include"utils.h"
#include "QInt.h"
#include "Qfloat.h"

//SỬA
//trừ với số âm

int main() {


	QInt a("64153264155263984615398461");
	//QInt b("32");


	QInt res = (a.rol(100));
	res.PrintQInt();




	//try {

	//	QInt res = a / b;
	//	res.PrintQInt();
	//}
	//catch (runtime_error& e) {
	//	cout << "exception occurred" << endl
	//		<< e.what();
	//}


	//cout << "(a < b): " << (a < b) << endl << "(a > b): " << (a > b) << endl;;
	//cout << "(a <= b): " << (a <= b) << endl << "(a >= b): " << (a >= b) << endl;



	return 0;
}



