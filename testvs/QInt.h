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
	//--GETTER
public:
	int* getNum() {
		int* num = new int[4];
		for (int i = 0; i < 4; i++) {
			num[i] = this->num[i];
		}
		return num;
	}

	//--NHẬP-XUẤT
public:
	void ScanQInt(string s);
	void PrintQInt();

	//CONVERT
public:
	
	 static bool* DecToBin(QInt x);
	 static QInt BinToDec(bool* bit);
	 static char* BinToHex(bool* bit);
	 static char* DecToHex(QInt x);

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
	QInt operator&(QInt );
	QInt operator|(QInt );
	QInt operator^(QInt );
	QInt operator~();
	QInt operator<<(int );
	QInt operator>>(int);
	QInt rol(int);
	QInt ror(int);





	//OPERATOR GÁN
	QInt& operator=(const QInt& other);


	// ------TEST
public:
	void tobin() {
		bool *b = DecToBin(*this);

		for (int i = 0; i < 128; i++) {
			cout << b[i] << "";
		}
		cout << endl;

		delete[]b;
	}



	//------FUNCTIONAL
public:
	string toString();
	string shortBin(int nbis = 0);
	bool isNegative();
	bool isZero();
};








#endif










