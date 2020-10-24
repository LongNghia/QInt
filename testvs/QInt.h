#ifndef _QINT_H_
#define _QINT_H_
#include <iostream>
#include <string>


using namespace std;

class QInt
{
private:
	int num[4];

	//--CONSTRUCTOR-DESTRUCTOR
public:
	QInt() {

	}
	QInt(string s) {
		this->ScanQInt(s);
	}
	QInt(int* numArray) {
		for (int i = 0; i <= 4; i++) {
			num[i] = numArray[i];
		}
	}

	//--NHẬP-XUẤT
public:
	void ScanQInt(string s);
	void PrintQInt();

	//CONVERT
public:
	
	 bool* DecToBin();
	 QInt BinToDec(bool* bit);
	 char* BinToHex(bool* bit);
	 char* DecToHex(QInt x);

	//OPERATOR + - * /
public:
	QInt operator + (QInt b);

	//QInt operater - (Qint b);


	//----OPERATOR =
	QInt& operator=(const QInt& other);

};








#endif










