#include "Qfloat.h"
#include "QInt.h"
#include "utils.h"
#define K 16383

Qfloat::Qfloat() {}

Qfloat::Qfloat(string s) {
	Qfloat q;
	q.ScanQfloat(s);
}

Qfloat::Qfloat(char* q) {
	for (int i = 0; i < 16; i++) {
		num[i] = q[i];
	}
}


//Hàm Nhập Qfloat
void Qfloat::ScanQfloat(string s) {
	bool sign = 0;
	if (s[0] == '-') {
		sign = 1;
		s = s.substr(1);
	}

	QInt a(s.substr(0, s.find_first_of('.')));
	QInt b(s.substr(s.find_first_of('.') + 1));

	a.PrintQInt();
	b.PrintQInt();


	string num1 = "", num2 = "";
	string res = "";

	cout << "num1=0: " << num1 << endl;
	//num1=0
	if (a.isZero()) {

		num2 = doubleflt(b.toString(), K + 112);

		int i = 0;
		int p = 0;
		while (num2[i] == '0') {
			i++;
		}

		i = i + 1;

		//khong chuan hoa duoc
		if (i >= K) {
			p = -K;
			cout << "khog chuan hoa!" << endl;
		}
		else {
			int p = -i;

		}
		cout << "i=: " << i << endl;
		num2 = doubleflt(b.toString(), 112 - p);
		string significant = num2.substr(i);
		int exp = p + K;
		cout << "exp= " << exp << endl;
		string exponent = dexToBin(exp, 15);
		char dau = sign + '0';
		res = dau + exponent + significant;
		cout << res;
	}

	//num1!=0
	else {
		num1 = a.shortBin(); //"0"

		int p = 0;
		int num1_length = num1.size();
		p = num1_length - 1; //0
		num2 = doubleflt(b.toString(), 112 - p);

		//cout << "num2\n" << num2 << endl;
		string significant = num1.substr(1) + num2;

		int exp = p + K;
		cout << "exp= " << exp << endl;
		string exponent = dexToBin(exp, 15);
		char dau = sign + '0';
		res = dau + exponent + significant;
		cout << res;
	}

	bool bits[128] = { 0 };
	bitsintStringToBitsArray(res, bits);

	bool temp[8] = { 0 };
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			temp[j] = (bits[j + 8 * i]);
		}
		num[i] = convertBinArrayToDex(temp, 8);
	}


}

//Hàm xuất
void Qfloat::PrintQfloat() {
	//chuyển về bit[128]
	//lấy bit dấu = 1bit => '+' '-';
	//15 bit exp; = > 2 ^ n = > dời qua phải nbit;
	//
	//112 bit sig = > 112 bit phần lẻ=> số lẻ (2^âm);

	//xuất dấu + phần nguyên + phần lẻ;
	//kiểm tra số âm, số 0;
	cout << "--------------PRINT-----------------\n";
	bool* bits;
	bits = DecToBin(*this);

	cout << "day bit :" << endl;
	for (int i = 0; i < 128; i++) { cout << bits[i]; }
	cout << "\nday bit :" << endl;

	char sign = bits[0] ? '-' : '+';


	bool expbin[15] = { 0 };
	for (int i = 1; i < 16; i++) {
		expbin[i - 1] = bits[i];

	}

	string expNum = bitsToDex(expbin, 15);

	int exp = abs(stoi(expNum) - K);
	cout << "exp=\n" << exp << endl;;


	//tìm phần nguyên
	string interger = "1";

	for (int i = 16; i < 16 + exp; i++) {
		interger += bits[i] + '0';
	}
	cout << endl;
	cout << interger;





	//string le = "";

	//cout << "\nday bit nguyen :" << endl;

	//bool binle[112] = { 0 };
	//for (int i = 16; i < 128; i++) {
	//	binle[i-16] = bits[i];
	//}
	//
	//le = bitsToDex(binle, 112);
	//cout << "\phan le" << le << endl;

	//cout <<" nguyeen: \n:" <<nguyen;

	delete[]bits;
}

// Hàm chuyển đổi số Qfloat nhị phân sang thập phân
//Qfloat Qfloat::BinToDec(bool *bit) {
//
//}
////Hàm chuyển đổi số Qfloat thập phân sang nhị phân
bool *Qfloat::DecToBin(Qfloat x) {
	bool* bits = new bool[128];
	string bin = "";
	for (int i = 0; i < 16; i++) {
		{
			bin += dexToBin(num[i], 8);
		}
	}

	cout << "\nbin stirng:\n" << bin << endl;

	bitsintStringToBitsArray(bin, bits);
	//
	//cout << endl;
	//for (int i = 0; i < 128; i++) {
	//	cout << bits[i];
	//}
	//cout << endl;

	return bits;
}

Qfloat Qfloat::BinToDec(bool *bits) {
	Qfloat q;
	bool temp[8] = { 0 };

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			temp[j] = (bits[j + 8 * i]);
		}
		q.num[i] = convertBinArrayToDex(temp, 8);
	}
	return q;
}