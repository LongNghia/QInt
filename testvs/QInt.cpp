#include "QInt.h"
#include "utils.h"

//hàm nhập
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
	cout << bitsToDex(bits) << endl;
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
		else  {
			remider = 0;
		}
		c[i] = s;
	}
	//xuat
	//cout << endl;

	//for (int i = 0; i < 128; i++) {
	//	cout << c[i] << "";
	//}
	//cout << endl;

	sum = BinToDec(c);
	delete[]b1;
	return 	sum;
}

//TOÁN TỬ TRỪ
QInt QInt::operator- (QInt b)
{
	//if (b < *this) {

	//}
	bool *bits = DecToBin(b);
	bu2(bits);
	b.PrintQInt();
	QInt temp;
	temp = BinToDec(bits);
	temp.PrintQInt();
	delete []bits;

	return *this + temp;
}

//TOÁN TỬ NHÂN
//QInt operator * (QInt b) {
//	return *this;
//}


QInt& QInt::operator=(const QInt& other) {
	for (int i = 0; i < 4; i++) {
		this->num[i] = other.num[i];
	}
	return *this;
}


//CONVERT FUNCTIONS

//Chuyển đổi từ hệ 2 -> 10
bool* QInt::DecToBin(QInt q) {
	bool* b = new bool[128];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 32; j++) {
			b[j + i * 32] = (q.num[i] >> (31 - j)) & 1;
		}
	return b;
}

//Chuyển đổi từ 10 -> 2
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

