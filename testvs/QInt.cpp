#include "QInt.h"
#include "utils.h"
#include <exception>
#include <stdexcept>
#include <sstream>
#include <unordered_map>

//Hàm nhập
void QInt::ScanQInt(string s)
{
	bool bits[128] = { 0 };

	s = standardizeString(s);
	intStringToBits(s, bits);

	bool temp[32] = { 0 };

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 32; i++) {
			temp[i] = bits[i + 32 * j];
		}
		num[j] = BinArrayToInt(temp, 32);
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

	delete[]bits;

	return *this + temp;
}

//TOÁN TỬ NHÂN
QInt QInt::operator * (QInt b) {

	bool sign = this->isNegative() ^ b.isNegative();


	string num1 = this->toString();
	string num2 = b.toString();


	num1 = this->isNegative() ? num1.substr(1) : num1;
	num2 = b.isNegative() ? num2.substr(1) : num2;


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
		res = AddTwoIntString(res, resMulEach);
		i--;
	}

	res = sign ? '-' + res : res;
	QInt num3(res);
	return num3;
}

//TOÁN TỬ CHIA
QInt QInt::operator / (QInt other) {

	QInt q = *this;
	QInt m = other;

	bool sign = (this->isNegative() ^ m.isNegative()) ? 1 : 0;

	QInt zero("0");

	if (this->isNegative()) {
		q = zero - q;
	}

	if (m.isNegative()) {
		m = zero - m;
	}

	string qbin = binArrayToBinString(DecToBin(q));
	string mbin = binArrayToBinString(DecToBin(m));
	string abin = binArrayToBinString(DecToBin(QInt("0")));


	string aq = "";
	QInt mbu2 = zero - m;

	string subResult = "";

	int k = 128;

	for (int i = 0; i < 128; i++) {
		//cout << "aq= " << aq << endl;
		//cout << "abin= " << abin << endl;
		//cout << "qbin= " << qbin << endl;

		aq = abin + qbin;
		aq = aq + '0';
		aq = aq.substr(1);

		abin = aq.substr(0, 128);
		qbin = aq.substr(128, 128);


		QInt a2;
		a2 = BinToDec(binStringToBinArray(abin));
		subResult = binArrayToBinString(DecToBin(a2 + mbu2));

		//cout << "subtract:\n" << subResult << endl;;

		if (subResult[0] == '0') {
			abin = subResult;
			qbin[127] = '1';
		}
		else {
			qbin[127] = '0';
		}
	}
	QInt thuong = BinToDec(binStringToBinArray(qbin));
	return sign ? zero - thuong : thuong;
}
//QInt QInt::operator / (QInt other) {
//
//	QInt a = *this;
//	QInt b = other;
//
//	bool sign = (this->isNegative() ^ b.isNegative()) ? 1 : 0;
//	QInt zero("0");
//	QInt one("1");
//
//	if (this->isNegative()) {
//		a = zero - a;
//	}
//
//	if (b.isNegative()) {
//		b = zero - b;
//	}
//
//	cout << "so bi chia" << a.toString() << endl;
//
//	cout << "so chia" << b.toString() << endl;
//
//	if (b.isZero()) {
//		string str = "Can not devide by zero!!!";
//		throw runtime_error("Math error: Attempted to divide by Zero\n");
//	}
//
//	QInt quotient("0");
//	while (b <= a) {
//		a = a - b;
//		cout << a.toString() << endl;
//		quotient = quotient + one;
//	}
//
//	return sign ? zero - quotient : quotient;
//
//}

//TOÁN TỬ GÁN
QInt& QInt::operator=(const QInt& other) {
	for (int i = 0; i < 4; i++) {
		this->num[i] = other.num[i];
	}
	return *this;
}

//TOÁN TỬ ==
bool QInt::operator==(QInt other) {
	for (int i = 0; i < 4; i++) {
		if (this->num[i] != other.num[i])
			return false;
	}
	return true;
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

//TOÁN TỬ <=
bool QInt::operator<=(QInt other) {
	if (*this < other || *this == other)
		return true;
	return false;
}

//TOÁN TỬ >
bool QInt::operator>(QInt other) {
	return other < *this;
}

//TOÁN TỬ >=
bool QInt::operator>=(QInt other) {
	return other <= *this;
}

//TOÁN TỬ &
QInt QInt::operator&(QInt other) {
	bool* b1 = DecToBin(*this);
	bool* b2 = DecToBin(other);
	bool b[128];
	for (int i = 0; i < 128; i++)
		b[i] = b1[i] & b2[i];
	return BinToDec(b);
}

//TOÁN TỬ |
QInt QInt::operator|(QInt other) {
	bool* b1 = DecToBin(*this);
	bool* b2 = DecToBin(other);
	bool b[128];
	for (int i = 0; i < 128; i++)
		b[i] = b1[i] | b2[i];
	return BinToDec(b);
}

//TOÁN TỬ ^
QInt QInt::operator^(QInt other) {
	bool* b1 = DecToBin(*this);
	bool* b2 = DecToBin(other);
	bool b[128];
	for (int i = 0; i < 128; i++)
		b[i] = b1[i] ^ b2[i];
	return BinToDec(b);
}

//TOÁN TỬ ~
QInt QInt::operator~() {
	bool* b = DecToBin(*this);
	bool res[128];
	for (int i = 0; i < 128; i++)
		res[i] = !b[i];
	return BinToDec(res);
}

//TOÁN TỬ <<
QInt QInt::operator<<(int n) {
	bool* b = DecToBin(*this);
	bool bits[128] = { 0 };
	cout << "\noper<<\n";
	for (int i = n; i < 128; i++) {
		bits[i - n] = b[i];
	}
	cout << "\n bam dau<<\n";
	for (int i = 0; i < 128; i++) {
		cout << b[i];
	}
	cout << "\n operator<<\n";
	for (int i = 0; i < 128; i++) {
		cout << bits[i];
	}
	cout << endl;

	return BinToDec(bits);
}

//TOÁN TỬ >>
QInt QInt::operator>>(int n) {
	bool* b = DecToBin(*this);
	bool bits[128] = { 0 };
	for (int i = 0; i < 128 - n; i++)
		bits[i + n] = b[i];
	return BinToDec(bits);
}

//HÀM ROL
QInt QInt::rol(int n) {

	bool* b = DecToBin(*this);

	bool bits[128] = { 0 };

	for (int i = n; i < 128; i++) {
		bits[i - n] = b[i];
	}

	for (int i = 0; i < n; i++) {
		bits[128 - n + i] = b[i];
	}

	return BinToDec(bits);
}

//HÀM ROR
QInt QInt::ror(int n) {

	bool* b = DecToBin(*this);

	bool bits[128] = { 0 };

	for (int i = 128 - n; i < 128; i++) {
		bits[i - 128 + n] = b[i];
	}

	for (int i = 0; i < 128 - n; i++) {
		bits[n + i] = b[i];
	}


	return BinToDec(bits);
}

//CONVERT FUNCTIONS
//Chuyển đổi từ hệ 10 -> 2
bool* QInt::DecToBin(QInt q, int n) {
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
string QInt::BinToHex(bool* bit) {

	unordered_map<string, char> um;
	string sbin = binArrayToBinString(bit);
	um["0000"] = '0';
	um["0001"] = '1';
	um["0010"] = '2';
	um["0011"] = '3';
	um["0100"] = '4';
	um["0101"] = '5';
	um["0110"] = '6';
	um["0111"] = '7';
	um["1000"] = '8';
	um["1001"] = '9';
	um["1010"] = 'A';
	um["1011"] = 'B';
	um["1100"] = 'C';
	um["1101"] = 'D';
	um["1110"] = 'E';
	um["1111"] = 'F';

	string fourbit = "";
	string res;
	while (sbin.length()) {
		fourbit = sbin.substr(0, 4);
		res += um[fourbit];
		sbin = sbin.substr(4);
	}
	return res;

}

//Chuyển đổi từ 10 -> 16
string QInt::DecToHex(QInt x) {
	bool* b = DecToBin(x);
	string s = BinToHex(b);
	return s;
}

//Chuyển đổi từ 16 -> 10
QInt QInt::HexToDec(string s) {
	bool* bin = HexToBin(s);
	QInt q = BinToDec(bin);
	delete[]bin;
	return q;
}

//Chuyển đổi từ 16 -> 2
bool* QInt::HexToBin(string hexdec) {
	long int i = 0;
	string res = "";
	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
			res += "0000";
			break;
		case '1':
			res += "0001";
			break;
		case '2':
			res += "0010";
			break;
		case '3':
			res += "0011";
			break;
		case '4':
			res += "0100";
			break;
		case '5':
			res += "0101";
			break;
		case '6':
			res += "0110";
			break;
		case '7':
			res += "0111";
			break;
		case '8':
			res += "1000";
			break;
		case '9':
			res += "1001";
			break;
		case 'A':
		case 'a':
			res += "1010";
			break;
		case 'B':
		case 'b':
			res += "1011";
			break;
		case 'C':
		case 'c':
			res += "1100";
			break;
		case 'D':
		case 'd':
			res += "1101";
			break;
		case 'E':
		case 'e':
			res += "1110";
			break;
		case 'F':
		case 'f':
			res += "1111";
			break;
		default:
			cout << "\nInvalid hexadecimal digit "
				<< hexdec[i];
		}
		i++;
	}
	bool *b = binStringToBinArray(res);

	return b;
}




// 123 --> "1111011"
string QInt::shortBin(int nbit) {
	string res = "";

	bool *bits;
	bits = DecToBin(*this);
	res = binArrayToBinString(bits);
	res = removeHeadZero(res);
	while (res.size() < nbit) {
		res = '0' + res;
	}

	delete[]bits;
	return res;

}


string QInt::toString() {
	string sbits = "";
	string temp = "";
	bool sign = 0;
	bool *bits;
	bits = DecToBin(*this);
	if (this->isNegative()) {
		bu2(bits);
		sign = 1;
	}

	string res = binToQInt(bits);
	delete[]bits;
	return  sign ? '-' + res : res;
}


//Kiểm tra một chuỗi ký tự số có âm không
//VD "-123456"
bool QInt::isNegative() {

	return ((this->num[0] >> 31) & 1);
}


bool QInt::isZero() {
	for (int i = 0; i < 4; i++) {
		if (this->num[i] != 0)
			return 0;
	}
	return 1;
}
