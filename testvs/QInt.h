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
	QInt(string num) {
		this->ScanQInt(num);
	}
	QInt(int* numArray) {
		for (int i = 0; i <= 4; i++) {
			num[i] = numArray[i];
		}
	}

public:

	//--NHẬP-XUẤT
public:
	void ScanQInt(string s);
	void PrintQInt();

	//CONVERT
public:

	static bool* DecToBin(QInt x);
	static QInt BinToDec(bool* bit);
	static string BinToHex(bool* bit);
	static string DecToHex(QInt x);
	static QInt HexToDec(string hex);
	static bool* HexToBin(string hex);


	//OPERATOR + - * /
public:
	QInt operator + (QInt b);
	QInt operator - (QInt b);
	QInt operator * (QInt b);
	QInt operator / (QInt b);


	//----OPERATOR SO SÁNH
	bool operator < (QInt b);
	bool operator > (QInt b);
	bool operator <= (QInt b);
	bool operator >= (QInt b);
	bool operator == (QInt b);


	//---OPERATOR & | ^ ~
	QInt operator&(QInt);
	QInt operator|(QInt);
	QInt operator^(QInt);
	QInt operator~();
	QInt operator<<(int);
	QInt operator>>(int);
	QInt rol(int);
	QInt ror(int);

	//OPERATOR GÁN
	QInt& operator=(const QInt& other);

	//------FUNCTIONAL
public:
	//QInt --> "12345"
	string toString();
	//QInt --> "11010101"
	string shortBin(int nbis = 0);
	//true if Qint is negative
	bool isNegative();
	//true if Qint is equal to 0
	bool isZero();
};


#endif










