#pragma once

#include <iostream>
#include <string>



using namespace std;


int stringToInt(string s) {
	//"12345"->12345
	//int num=0;
	//for (int i = 0; i < s.length(); i++) {
	//	//cout << s[i] << " ";
	//	num = 10 * num + atoi(s[i]);
	//	cout << "num= " << num<<endl;
	//}
	return stoi(s);

}

// dua mang bits ve dang bu 2
void bu2(bool *bits) {
	//bit dau
	bits[0] = 1;
	int flag = 127;

	while (bits[flag] == 0) {
		//cout << "\t" << flag << endl;
		flag--;
	}
	//cout << "flag: " << (flag) << endl;
	for (int i = 1; i < flag; i++) {
		bits[i] = !bits[i];
	}
}



//s='1'->1
int charToInt(char c) {
	return c - 48;
}

string removeHeadZero(string &s) {

	while (s[0] == '0') {
		s = s.substr(1);
	}
	return s;
}




string half(string s, bool &bit) {
	int s_length = s.size();
	if (charToInt(s[s_length - 1]) & 1)
	{
		bit = 1;
	}
	else { bit = 0; };
	string res = "";
	int sobichia = 0, nho = 0;

	for (int i = 0; i < s.size(); i++) {
		sobichia = charToInt(s[i]) + nho;
		char div = (sobichia / 2) + '0';
		res += div;

		if (s[i] & 1) {
			nho = 10;
		}
		else { nho = 0; }
	}
	return removeHeadZero(res);
}

//day bits 
void intStringToBits(string s, bool *bits) {

	bool sign = 0;

	if (s[0] == '-') {
		s = s.substr(1);
		sign = 1;
	}
	else if (s[0] == '+') {
		sign = 0;
		s = s.substr(1);
	}

	string temp;
	bool bit = 0;

	temp = s;
	//int i = 127;
	int i = 127;


	while (temp.size()) {
		temp = half(temp, bit);
		//cout << temp << endl;
		bits[i--] = bit;
		if (i < 0) {
			cout << "\nVuot qua QInt!\n";
			return;
		}
	}

	if (sign) {
		bu2(bits);
	}
}



//vector<int> half(vector<int> n) {
//	//n la vector chua so nhhap tu ban phim
//	//return n/2 (luu dang vector)
//	return ;
//}

//vector<int> half(vector<int> n)
//{
//	int *m = new int[1];
//	int s = sizeof(n);
//	if ((s == 1) & ((n[0] == 0) | (n[0] == 1)))
//	{
//		m[0] = 0;
//		return m;
//	}
//	else
//	{
//		m = new int[s];
//		m[0] = n[0] / 2;
//		for (int i = 1; i < s; i++)
//			m[i] = (((n[i - 1] % 2) * 10) + n[i]) / 2;
//	}
//	if (m[0] == 0)
//	{
//		for (int i = 0; i < s; i++)
//			m[i] = m[i + 1];
//		m[s - 1] = NULL;
//		return m;
//	}
//	else
//		return m;
//	delete[] m;
//}

//Phụ thêm cho hàm nhập (để chia đôi lấy phần dư)
bool getLastBit(int n)
{
	//if (n[sizeof(n) - 1] % 2 == 0)
	//	return 0;
	//else
	//	return 1;

	return n & 1;
}

//bool DecToBin()
//{
//	bool *b = new bool[128];
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 32; j++)
//		{
//			b[j + i * 32] = (x.num[i] >> (31 - j)) & 1;
//			/*cout << b[j + i * 32];*/
//		}
//	return b;
//}

void ScanQInt()
{
	string s;
	bool *b = new bool[128];
	getline(cin, s);

	//isStringValid(s);
	//fixString(s);

	if ((s[0] != '-') & (s[0] != '+'))
	{
		string s1;
		int in = 0;
		for (int i = 0; s[i] == '0'; i++)
			in = i + 1;
		for (int i = in; i < s.length(); i++)
			s1.append(s1, s[i]);
		int *n = new int[s1.length()];
		for (int i = 0; i < s1.length(); i++)
			n[i] = int(s1[i] - 48);
		for (int i = 127; i >= 0; i--)
		{

			b[i] = getLastBit(n[sizeof(n) - 1]);
			//n = half(n);
		}
		//x = BinToDec(b);
		delete[] n;
	}
	else if (s[0] == '+')
	{
		string s1;
		int in = 0;
		for (int i = 1; s[i] == '0'; i++)
			in = i + 1;
		for (int i = in; i < s.length(); i++)
			s1.append(s1, s[i]);
		int *n = new int[s1.length()];
		for (int i = 0; i < s1.length(); i++)
			n[i] = int(s1[i] - 48);

		//n là mảng chứa các số đã nhập vào
		// b là mảng bit của số đã nhập
		for (int i = 127; i >= 0; i--)
		{
			b[i] = getLastBit(n[sizeof(n) - 1]);
			//n = half(n);
		}
		//x = BinToDec(b);
		delete[] n;
	}
	else
	{
		string s1;
		int in = 0;
		for (int i = 1; s[i] == '0'; i++)
			in = i + 1;
		for (int i = in; i < s.length(); i++)
			s1.append(s1, s[i]);
		int *n = new int[s1.length()];
		for (int i = 0; i < s1.length(); i++)
			n[i] = int(s1[i] - 48);
		for (int i = 127; i >= 0; i--)
		{
			b[i] = getLastBit(n[sizeof(n) - 1]);
			//n = half(n);
		}
		int in1 = 127;
		for (int i = 127; b[i] == 0; i--)
			in1 = i - 1;
		for (int i = in1 - 1; i >= 0; i--)
			if (b[i])
				b[i] = 0;
			else
				b[i] = 1;
		//x = BinToDec(b);
		delete[] n;
	}
	delete[] b;
}

int convertBinArrayToDex(bool *bits, int n = 32) {
	int decimal = 0;
	for (int i = 0; i < n; i++)
		decimal = decimal * 2 + bits[i];
	return decimal;
}

//bool* convertDexToBinArray(int num) {
//
//}

//bool *QInt::DecToBin(QInt x)
//{
//	bool *b = new bool[128];
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 32; j++)
//		{
//			b[j + i * 32] = (x.num[i] >> (31 - j)) & 1;
//			/*cout << b[j + i * 32];*/
//		}
//	return b;
//}

//-------------------------
//main process

//int +intnt
//"12346548964"+"34643135468153"
string add2IntString(string s1, string s2) {

	std::string s = std::to_string(stoi(s1) + stoi(s2));

	return s;
}



string multifyStringWithNum(std::string num1, int num2)
{
	int r = 0;
	string q = "";

	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int k = (int)(num1[i] - '0');
		int temp = (k * num2) + r;

		if (temp > 9)
		{
			r = temp / 10;
			temp = temp % 10;
			q = std::to_string(temp) + q;
		}
		else
		{
			q = std::to_string(temp) + q;
			r = 0;
		}
	}
	if (r > 0)
		q = std::to_string(r) + q;

	return q;
}

string twoPowNum(int n) {

	string s = "1";
	for (int i = 0; i < n; i++) {
		s = multifyStringWithNum(s, 2);
	}
	return s;
}


std::string AddTwoIntString(std::string num1, std::string num2)
{
	std::string result = "";
	int reminder = 0;
	int pointerNum1 = num1.length() - 1;
	int pointerNum2 = num2.length() - 1;
	int resultOfAddingTwoNum = 0;

	while (pointerNum1 >= 0 && pointerNum2 >= 0)
	{
		resultOfAddingTwoNum = num1[pointerNum1] + num2[pointerNum2] + reminder - 2 * 48;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;
		pointerNum2--;

	}

	while (pointerNum1 >= 0)
	{
		resultOfAddingTwoNum = num1[pointerNum1] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;
	}

	while (pointerNum2 >= 0)
	{
		resultOfAddingTwoNum = num2[pointerNum2] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum2--;
	}

	if (reminder != 0)
	{
		std::string s = "";
		s += reminder + 48;

		result.insert(0, s);
	}

	return result;
}


string bitsToDex(bool* bits) {
	bool sign = 0;
	if (bits[0] == 1) {
		//cout << "phat hien so am\n";
		bu2(bits);
		sign = 1;
	}

	string res = "0";
	for (int i = 127; i >= 1; i--) {
		if (bits[i]) {
			//cout <<"i= " <<i << endl;
			res = AddTwoIntString(res, twoPowNum(127 - i));
		}

	}

	if (sign) {
		res = '-' + res;
	}
	return res;
}

void bitsintStringToBitsArray(string s, bool* bits) {
	int slength = s.size();
	int i = 0;
	///000111
	//pos=127-6+1
	///00000...[0-122]00111
	while (s[i]) {
		if (s[i] == '1')
			bits[127 - slength + 1 + i] = 1;
		else
		{
			bits[i] = 0;
		}
		i++;
	}
}

string bitsArrayToBitsString(bool* bits) {
	string s = "";
	for (int i = 0; i < 128; i++) {
		if (bits[i])
			s += '1';
		else
			s += '0';
	}
	return s;
}


string dexToBin(int num) {
	string snum = std::to_string(num);
	bool bits[128] = { 0 };
	intStringToBits(snum, bits);
	return bitsArrayToBitsString(bits);
}




//CHO VAO CLASS?


