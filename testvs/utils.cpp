#include "utils.h"

#include <string>




//Đưa mảng bit (dương) về dạng bù 2
void bu2(bool *bits, int n) {
	//bit dau
	bits[0] = !bits[0];
	int flag = n - 1;

	while (bits[flag] == 0) {
		flag--;
	}
	for (int i = 1; i < flag; i++) {
		bits[i] = !bits[i];
	}
}



//s='1'->1
int charToInt(char c) {
	return c - 48;
}



//chia đôi lấy phần dư để tìm dãy nhị phân
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
void intStringToBits(string s, bool *bits, int n) {

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
	int i = n - 1;


	while (temp.length()) {
		temp = half(temp, bit);
		bits[i--] = bit;
		if (i < 0) {
			break;
		}
	}

	if (sign) {
		bu2(bits);
	}
}



int BinArrayToInt(bool *bits, int n) {
	int decimal = 0;
	for (int i = 0; i < n; i++)
		decimal = decimal * 2 + bits[i];
	return decimal;
}


//"12345" * 1 = "12345" 
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

//2^3="8"
string twoPowNum(int n) {

	string s = "1";
	for (int i = 0; i < n; i++) {
		s = multifyStringWithNum(s, 2);
	}
	return s;
}


//"12"+"12" ="24"
string AddTwoIntString(string num1, string num2)
{
	string result = "";
	int reminder = 0;
	int n1 = num1.length() - 1;
	int n2 = num2.length() - 1;
	int resultOfAddingTwoNum = 0;

	while (n1 >= 0 && n2 >= 0)
	{
		resultOfAddingTwoNum = num1[n1] + num2[n2] + reminder - 2 * 48;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		n1--;
		n2--;

	}

	while (n1 >= 0)
	{
		resultOfAddingTwoNum = num1[n1] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		n1--;
	}

	while (n2 >= 0)
	{
		resultOfAddingTwoNum = num2[n2] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		n2--;
	}

	if (reminder != 0)
	{
		string s = "";
		s += reminder + 48;

		result.insert(0, s);
	}

	return result;
}

//chỉ áp dụng cho số dương, số âm lấy phần bù và thêm '-'
string binToQInt(bool* bits, int n) {
	bool sign = 0;

	if (bits[0] == 1) {
		bu2(bits);
		sign = 1;
	}

	string res = "0";
	for (int i = n - 1; i >= 1; i--) {
		if (bits[i]) {
			res = AddTwoIntString(res, twoPowNum(n - 1 - i));
		}

	}

	if (sign) {
		res = '-' + res;
	}
	return res;
}

//void binStringToBinArray(string s, bool* bits) {
//	int slength = s.size();
//	int i = 0;
//
//	for (int i = 0; i < 128; i++) {
//		bits[i] = 0;
//	}
//
//	while (s[i]) {
//		if (s[i] == '1')
//			bits[127 - slength + 1 + i] = 1;
//		else
//		{
//			bits[i] = 0;
//		}
//		i++;
//	}
//}

bool* binStringToBinArray(string s) {
	bool* bits = new bool[128];

	int slength = s.size();

	for (int i = 0; i < 128; i++) {
		bits[i] = 0;
	}

	int i = 0;
	while (s[i]) {
		if (s[i] == '1')
			bits[127 - slength + 1 + i] = 1;
		else
		{
			bits[i] = 0;
		}
		i++;
	}
	return bits;
}

string binArrayToBinString(bool* bits, int n) {
	string s = "";
	for (int i = 0; i < n; i++) {
		if (bits[i])
			s += '1';
		else
			s += '0';
	}
	return s;
}


string IntToBin(int num, int n) {
	string snum = std::to_string(num);
	bool bits[128] = { 0 };
	intStringToBits(snum, bits, n);
	return binArrayToBinString(bits, n);
}


string removeHeadZero(string &s) {

	while (s[0] == '0') {
		s = s.substr(1);
	}
	if (s.length())
		return s;
	else 
		return "0";
}


// "12345" * '6'
string multifyIntStringWithChar(string s, char c) {
	int slength = s.size();
	string res = "";
	int reminder = 0;
	int i = slength - 1;

	int top = 0, down = c - '0';
	int temp = 0;
	char r; //
	while (i >= 0) {
		top = s[i] - '0';
		temp = top * down + reminder;
		reminder = temp / 10;
		r = temp % 10 + '0';
		res = r + res;
		i--;
	}
	if (reminder > 0) {
		r = reminder + '0';
		res = r + res;
	}
	return res;
}


//s là string thập phân, n là độ dài dãy bit
string decimalPartToBin(string s, int n) {
	int s_length = s.length();

	string res = "";
	string temp = s;

	for (int i = 0; i < n; i++) {

		temp = multifyIntStringWithChar(temp, '2');
		if (temp.length() > s_length) {
			res += '1';
			temp = temp.substr(1);
		}
		else {
			res += '0';
		}
	}
	return res;

}

//"000000"==0
bool isBinStringZero(string s) {

	int length = s.size();
	int i = 0;
	while (i < length)
	{
		if (s[i++] == '1')
			return 0;
	}
	return 1;
}

bool isIntStringZero(string s) {

	if (s[0] == '+' || s[0] == '-')
		s = s.substr(1);

	int length = s.size();
	int i = 0;
	while (i < length)
	{
		if (s[i++] != '0')
			return false;
	}
	return true;
}



bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}


string remove_non_digits(const string str) {
	string s = str;
	string result = "";
	if (s[0] != '+' && s[0] != '-' && !isDigit(s[0]))
		s = s.substr(1);
	else
		result += s[0];
	for (int i = 1; i < s.length(); i++) {
		if (isDigit(s[i]))
			result += s[i];
	}
	return result;
}


string standardizeString(string s) {
	if (isIntStringZero(s))
		return "0";
	return remove_non_digits(s);
}



string half_pow_num(int n) {
	string res = "1";
	for (int i = 0; i < n; i++)
		res = multifyIntStringWithChar(res, '5');
	if (res.length() < n)
	{
		string temp = "";
		for (int i = 0; i < n - res.length(); i++)
			temp = temp + '0';
		res = temp + res;
	}
	return res;
}


string add_two_flt_string(string s1, string s2) {
	int dif; string temp = ""; string s3 = "", res = "";
	if (s1.length() >= s2.length())
		dif = s1.length() - s2.length();
	else
		dif = s2.length() - s1.length();
	for (int i = 0; i < dif; i++)
	{
		temp = temp + '0';
		if (s1.length() > s2.length()) {
			s3 = s2 + temp;
			res = AddTwoIntString(s3, s1);
		}
		else {
			s3 = s1 + temp;
			res = AddTwoIntString(s3, s2);
		}
	}
	if (res.length() > s3.length())
		res = res.substr(1);
	return res;
}
