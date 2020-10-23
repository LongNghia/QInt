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
		num[j] = convertBinArrayToDex(temp);
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



QInt QInt::operator + (QInt b) {
	bool* b1 = this->DecToBin();
	bool* b2 = b.DecToBin(), m = 0;
	bool c[128];
	QInt sum;
	for (int i = 127; i >= 0; i--)
	{
		bool k = (b1[i] ^ b2[i]) ^ m;
		c[i] = k;
		if (k == 0)
			if (b1[i] == b2[i])
				m = b1[i];
			else
				m = 1;
		else m = 0;
	}
	sum = BinToDec(c);
	return 	sum;
}


//QInt QInt::operater - (Qint b)
//{
//	return *this + (-b);
//}





//CONVERT FUNCTIONS

//Chuyển đổi từ hệ 2 -> 10
bool* QInt::DecToBin() {
	bool* b = new bool[128];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 32; j++) {
			b[j + i * 32] = (this->num[i] >> (31 - j)) & 1;
			/*cout << b[j + i * 32];*/
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
	bool* b = x.DecToBin();
	char* s = BinToHex(b);
	return s;
}

