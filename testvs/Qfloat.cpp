#include "Qfloat.h"
#include "QInt.h"
#include "utils.h"
#define K 16383

Qfloat::Qfloat() {}

Qfloat::Qfloat(string s) {
	this->ScanQfloat(s);
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
	QInt a;
	string b;
	if (s.find('.') != std::string::npos) {
		a.ScanQInt(s.substr(0, s.find_first_of('.')));
		b = (s.substr(s.find_first_of('.') + 1));
	}
	else {
		a.ScanQInt(s);
		b = "0";
	}

	string num1 = "", num2 = "";
	string res = "";



	//num1=0
	//ex: 0.01
	if (a.isZero()) {

		//0.00, b=0
		if (isIntStringZero(b)) {
			for (int i = 0; i < 16; i++) {
				num[i] = 0;
			}
		}

		//0.01, b!=0
		//1. chuan hoa duoc
		//2. khong chuan hoa duoc
		//3. so vo cung
		//4. so bao loi NAN
		else {
			num2 = decimalPartToBin(b, K + 112);

			int i = 0;
			int p = 0;
			while (num2[i] == '0') {
				i++;
			}

			i = i + 1;

			//khong chuan hoa duoc
			//decimalpart:000000....00000(112's 0)1
			if (i >= K) {
				cout << "khong chuan hoa duoc\n";
				return;
				p = -K;
				string significant = num2.substr(K);
				char dau = sign + '0';
				string exponent = "000000000000000";
				res = dau + exponent + significant;
			}

			else {
				int exp = K - i;

				if (exp == 32767) {
					//số vô cùng
					//Phần mũ toàn bit 1, phần trị = 0
					//=>exp = 32767?????????
					if (isIntStringZero(num2)) {
						cout << "ifinity" << endl;
					}
					else {
						//số báo lỗi
						//Phần mũ toàn bit 1, phần trị != 0
						cout << "NAN" << endl;
					}
				}
				else {
					//chuẩn hoá được 0.1

					int p = -i;
					num2 = decimalPartToBin(b, 112 - p);
					string significant = num2.substr(i);
					int exp = p + K;
					string exponent = IntToBin(exp, 15);
					char dau = sign + '0';
					res = dau + exponent + significant;
				}
			}
		}
	}

	//num1!=0
	//ex: 12.09375
	else {
		num1 = a.shortBin(); //"0"
		int p = 0;
		int num1_length = num1.size();
		p = num1_length - 1; //0
		num2 = decimalPartToBin(b, 112 - p);

		string significant = num1.substr(1) + num2;

		int exp = p + K;
		string exponent = IntToBin(exp, 15);
		char dau = sign + '0';
		res = dau + exponent + significant;
	}

	bool *bits = binStringToBinArray(res);

	bool temp[8] = { 0 };

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			temp[j] = (bits[j + 8 * i]);
		}
		num[i] = BinArrayToInt(temp, 8);
	}

	delete[]bits;
}

//Hàm xuất
void Qfloat::PrintQfloat() {
	cout << this->toString();
}


bool *Qfloat::DecToBin(Qfloat x) {
	string bin = "";

	for (int i = 0; i < 16; i++) {
		{
			bin += IntToBin(x.num[i], 8);
		}
	}
	bool* bits = binStringToBinArray(bin);

	return bits;
}

Qfloat Qfloat::BinToDec(bool *bits) {
	Qfloat q;
	bool temp[8] = { 0 };
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			temp[j] = (bits[j + 8 * i]);
		}
		q.num[i] = BinArrayToInt(temp, 8);

	}

	return q;
}



string Qfloat::toString() {
	//Ý tưởng:
//bit đầu tiên -> '+' nếu là 0, '-' nếu là 1
//15 bit tiếp theo -> exp -> p = exp - K
//Nếu p >= 112 -> không có phần lẻ, phần nguyên gồm bit 1 + phần định trị + (p - 112) bit 0 (theo thứ thự)
//Nếu 0 <= p < 112 -> phân nguyên gồm bit 1 + p bit đầu phần định trị, phần lẻ gồm (112 - p) bit cuối phần định trị
//Nếu p < 0 -> phần nguyên = 0, phần lẻ gồm (|p| - 1) số 0 + bit 1 + phần định trị
//Đổi các dãy bit trên thành số thập phân

	string res = "";
	int exp = 0;
	bool* bits = this->DecToBin(*this);

	string nu = binArrayToBinString(bits);
	if (bits[0] == 1)
		res = "-";


	bool expbits[16] = { 0 };
	for (int i = 1; i < 16; i++)
		expbits[i] = bits[i];

	delete[]bits;
	string exps = binToQInt(expbits, 16);

	exp = stoi(exps);

	if (exp == 32767) {
		if (isBinStringZero(nu.substr(16)))
			return "Infinity!";
		else
			return "Not a number!";
	}

	else
	{
		string inbit = "1";
		string flbit = "";
		string n = "";
		string l = "0";
		int p = exp - K;

		if (p >= 112)

		{

			string temp = "";
			inbit = inbit + nu.substr(16);
			for (int i = 0; i < p - 112; i++)
				temp = temp + '0';
			inbit = inbit + temp;
			bool* in = binStringToBinArray('0' + inbit);
			string n = binToQInt(in, inbit.length() + 1);
			res = n;
			delete[]in;
		}
		else if (p >= 0)
		{
			//inbit = inbit + nu.substr(16, 112 - p);
			inbit = inbit + nu.substr(16, p);
			flbit = nu.substr(16 + p);
			bool* in = binStringToBinArray(inbit);
			string n = QInt::BinToDec(in).toString();

			for (int i = 0; i < flbit.length(); i++)
				if (flbit[i] == '1')
				{
					l = add_two_flt_string(l, half_pow_num(i + 1));
				}

			res = res + n + "." + l;
			delete[]in;
		}
		else
		{
			//tính toán quá lâu!!!
			return "It takes long time to save!";
			string temp = "";
			int e = -p;
			for (int i = 0; i < e - 1; i++)
				temp = temp + '0';
			flbit = temp + "1" + nu.substr(16);
			for (int i = 0; i < flbit.length(); i++)
				if (flbit[i] == '1')
					l = add_two_flt_string(l, half_pow_num(i + 1));
			string zeroAndDot = "0.";
			res = res + zeroAndDot + l;

		}
		return res;
	}
}
