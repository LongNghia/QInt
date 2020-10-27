﻿#include "QInt.h"
#include "utils.h"
#include <exception>
#include <stdexcept>
#include <sstream>
//Hàm nhập
void QInt::ScanQInt(string s)
{
	bool bits[128] = { 0 };

	//isStringValid(s);
	//s = validize(s);
	intStringToBits(s, bits);

	bool temp[32] = { 0 };
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 32; i++) {
			temp[i] = bits[i + 32 * j];
		}
		num[j] = convertBinArrayToDex(temp, 32);
	}
}

//Hàm xuất
void QInt::PrintQInt()
{
	cout << this->toString() << endl;
}


//TOÁN TỬ CỘNG
QInt QInt::operator + (QInt b) {
	bool* b1 = DecToBin(*this);
	bool* b2 = DecToBin(b);


	bool m = 0;
	bool c[128];
	QInt sum;
	int remider = 0;
	int s = 0;
	for (int i = 127; i >= 0; i--) {
		s = b1[i] + b2[i] + remider;
		if (s == 2) {
			remider = 1;
			s = 0;
		}
		else if (s == 3) {
			remider = 1;
			s = 1;
		}
		else {
			remider = 0;
		}
		c[i] = s;
	}

	sum = BinToDec(c);
	delete[]b1;
	return 	sum;
}

//TOÁN TỬ TRỪ
QInt QInt::operator- (QInt other)
{


	QInt b = other;

	bool *bits = DecToBin(b);
	bu2(bits);
	QInt temp;
	temp = BinToDec(bits);
	//cout << "bu 2!" << temp.toString()<<endl;
	
	delete[]bits;

	return *this + temp;
}

//TOÁN TỬ NHÂN
QInt QInt::operator * (QInt b) {
	//!!kiểm tra dấu



	bool sign = this->isNegative() ^ b.isNegative();


	string num1 = this->toString();
	string num2 = b.toString();

	num1 = this->isNegative() ? num1.substr(1) : num1;
	num2 = b.isNegative() ? num1.substr(1) : num2;


	int blength = num2.size();


	string resMulEach = "";
	string res = "";
	string pairSum = "";

	int i = blength - 1;
	while (i >= 0) {
		resMulEach = multifyIntStringWithChar(num1, num2[i]);

		for (int j = 0; j < blength - i - 1; j++) {

			resMulEach += '0';
		}
		//cout << resMulEach << endl;
		res = AddTwoIntString(res, resMulEach);
		//cout << "char:\n" << res;
		i--;
	}

	res = sign ? '-' + res : res;
	QInt num3(res);
	return num3;
}

//TOÁN TỬ CHIA
QInt QInt::operator / (QInt other) {

	QInt a = *this;
	QInt b = other;

	bool sign = (this->isNegative() ^ b.isNegative()) ? 1 : 0;
	QInt zero("0");
	QInt one("1");

	if (this->isNegative()) {
		a = zero - a;
	}

	if (b.isNegative()) {
		b = zero - b;
	}


	if (b.isZero()) {
		string str = "Can not devide by zero!!!";
		throw runtime_error("Math error: Attempted to divide by Zero\n");
	}

	QInt quotient("0");
	while (b < a) {
		a = a - b;
		quotient = quotient + one;
	}

	return sign ? zero - quotient: quotient;

}

//TOÁN TỬ GÁN
QInt& QInt::operator=(const QInt& other) {
	for (int i = 0; i < 4; i++) {
		this->num[i] = other.num[i];
	}
	return *this;
}

//TOÁN TỬ <
bool QInt::operator<(QInt other) {

	int count = 0;
	bool* bits1 = DecToBin(*this);
	bool* bits2 = DecToBin(other);

	//bits[0]
	if (bits1[0] < bits2[0]) {
		return false;
	}
	else if (bits1[0] > bits2[0])
		return true;

	else {
		for (int i = 1; i < 128; i++) {
			if (bits2[i] > bits1[i]) {
				return true;
			}
			else if (bits1[i] > bits2[i]) {
				return false;
			}
			else
				count++;
		}
		if (count == 127) {
			return false;
		}
	}
	return true;
}

//CONVERT FUNCTIONS

//Chuyển đổi từ hệ 10 -> 2
bool* QInt::DecToBin(QInt q) {
	bool* b = new bool[128];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 32; j++) {
			b[j + i * 32] = (q.num[i] >> (31 - j)) & 1;
		}
	return b;
}

//Chuyển đổi từ 2 -> 10
QInt QInt::BinToDec(bool* bit) {
	QInt q;
	for (int i = 0; i < 4; i++)
		q.num[i] = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 32; j++)
			q.num[i] = q.num[i] | (bit[j + i * 32] << (31 - j));
	return q;
}

//Chuyển đổi từ 2 -> 16
char* QInt::BinToHex(bool* bit) {
	char* s = new char[32]; int n[32];
	for (int i = 0; i < 32; i++)
		n[i] = 0;
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 4; j++)
			if (bit[j + i * 4] == 1)
				n[i] = n[i] + int(pow(2, j));
	for (int i = 0; i < 32; i++)
		switch (n[i]) {
		case 0:
			s[i] = '0';
			break;
		case 1:
			s[i] = '1';
			break;
		case 2:
			s[i] = '2';
			break;
		case 3:
			s[i] = '3';
			break;
		case 4:
			s[i] = '4';
			break;
		case 5:
			s[i] = '5';
			break;
		case 6:
			s[i] = '6';
			break;
		case 7:
			s[i] = '7';
			break;
		case 8:
			s[i] = '8';
			break;
		case 9:
			s[i] = '9';
			break;
		case 10:
			s[i] = 'A';
			break;
		case 11:
			s[i] = 'B';
			break;
		case 12:
			s[i] = 'C';
			break;
		case 13:
			s[i] = 'D';
			break;
		case 14:
			s[i] = 'E';
			break;
		case 15:
			s[i] = 'F';
			break;
		}
	return s;
}

//Chuyển đổi từ 10 -> 16
char* QInt::DecToHex(QInt x) {
	bool* b = DecToBin(x);
	char* s = BinToHex(b);
	return s;
}

// 123 --> "1111011"
string QInt::shortBin(int nbit) {
	string res = "";

	bool *bits;
	bits = DecToBin(*this);
	res = bitsArrayToBitsString(bits);
	res = removeHeadZero(res);
	while (res.size() < nbit) {
		res = '0' + res;
	}

	delete[]bits;
	return res;

}


string QInt::toString() {
	string sbits = "";
	string res = "";
	string temp = "";
	bool bits[128] = { 0 };

	//cout << endl;
	for (int i = 0; i < 4; i++) {
		temp = dexToBin(num[i]);
		sbits += temp.substr(96);
	}
	//cout << sbits << endl;
	bitsintStringToBitsArray(sbits, bits);
	return bitsToDex(bits);
}

//Kiểm tra một chuỗi ký tự số có âm không
//VD "-123456"
bool QInt::isNegative() {
	return this->num[0] < 0;
}

bool QInt::isZero() {
	for (int i = 0; i < 4; i++) {
		if (this->num[i] != 0)
			return 0;
	}
	return 1;
}
