#include "Qfloat.h"
#include "QInt.h"
#include "utils.h"
#define K 16383

Qfloat::Qfloat(){}

Qfloat::Qfloat(string s) {
	Qfloat q;
	q.ScanQfloat(s);
}

//Hàm Nhập Qfloat
void Qfloat::ScanQfloat(string s) {
	//1.Lấy phần nguyên a, phần thực b
	//2.Đưa a,b về nhị phân
	//3.chuẩn hoá về dạng 1.f*e^e
		//	tính e+k=15bits+ lưu sign = 1bits => 2bytes
		//	
		//	lưu phần signification+"0000"=112bits => 14bytes
//isStringValid();

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

	num1 = a.shortBin();
	num2 = b.shortBin();


	cout << num1 << endl << num2 << endl;

	bool bits[128] = { 0 };


	int exp = 0;
	int num1_length = num1.size();

	//cout << "num1 length: " << num1_length << endl;
	if (sign) {
		exp = K + num1_length - 1;
	}
	else {
		exp = K - (num1_length - 1);
	}

	QInt Qexp(to_string(exp));
	//bool binexp;

	string expbin = Qexp.shortBin(15);
	//cout << expbin;




	bits[0] = sign;
	for (int i = 0; i < 16; i++) {
		if (expbin[i]) {
			bits[i + 1] = expbin[i] - '0';
		}
	}

	//significant
	string sigbin = num1.substr(1) + b.shortBin();

	while (sigbin.size() < 112) {
		sigbin = '0' + sigbin;
	}
	//cout << "signbin:" << sigbin << endl;;

	for (int i = 16; i < 128; i++) {
		bits[i] = sigbin[i - 16] - '0';
	}

	//for (int i = 0; i < 128; i++) {
	//	cout << bits[i];
	//}
	//cout << endl;
	bool temp[8] = { 0 };
	//cout << endl;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			temp[j] = (bits[j + 8 * i]);
		}
		num[i] = convertBinArrayToDex(temp, 8);
		//cout << num[i] << endl;
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

	string le = "";

	cout << "\nday bit nguyen :" << endl;

	bool binle[112] = { 0 };
	for (int i = 16; i < 128; i++) {
		binle[i-16] = bits[i];
	}
	
	le = bitsToDex(binle, 112);
	cout << "\phan le" << le << endl;

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
		//cout << num[i] << endl;
	}
	return q;
}