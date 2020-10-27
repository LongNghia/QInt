#include"utils.h"
#include "QInt.h"
#include "Qfloat.h"

//SỬA
//-0
//nhân 2 số âm
//trừ với số âm

int main() {

	QInt a("14");
	//QInt b("24");
	QInt b("-3");

	try {

		QInt res = a / b;
		res.PrintQInt();
	}
	catch (runtime_error& e) {
		cout << "exception occurred" << endl
			<< e.what();
	}
	return 0;
}



