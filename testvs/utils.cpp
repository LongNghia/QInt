#include "utils.h"

#include <string>




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
void bu2(bool *bits, int n) {
	//bit dau
	bits[0] = 1;
	int flag = n-1;

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
	//int i = 127;
	int i = n-1;


	while (temp.size()) {
		temp = half(temp, bit);
		//cout << temp << endl;
		bits[i--] = bit;
		if (i < 0) {
			//cout << "\nVuot qua QInt!\n";
			return;
		}
	}

	if (sign) {
		bu2(bits);
	}
}


bool getLastBit(int n)
{
	return n & 1;
}



int convertBinArrayToDex(bool *bits, int n) {
	int decimal = 0;
	for (int i = 0; i < n; i++)
		decimal = decimal * 2 + bits[i];
	return decimal;
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


string AddTwoIntString(string num1, string num2)
{
	string result = "";
	int reminder = 0;
	int pointerNum1 = num1.length() - 1;
	int pointerNum2 = num2.length() - 1;
	int resultOfAddingTwoNum = 0;

	while (pointerNum1 >= 0 && pointerNum2 >= 0)
	{
		resultOfAddingTwoNum = num1[pointerNum1] + num2[pointerNum2] + reminder - 2 * 48;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		string s = "";
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

		string s = "";
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

		string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum2--;
	}

	if (reminder != 0)
	{
		string s = "";
		s += reminder + 48;

		result.insert(0, s);
	}

	return result;
}


string bitsToDex(bool* bits, int n) {
	bool sign = 0;
	if (bits[0] == 1) {
		//cout << "phat hien so am\n";
		bu2(bits);
		sign = 1;
	}

	string res = "0";
	for (int i = n-1; i >= 1; i--) {
		if (bits[i]) {
			//cout <<"i= " <<i << endl;
			res = AddTwoIntString(res, twoPowNum(n-1 - i));
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

string bitsArrayToBitsString(bool* bits, int n) {
	string s = "";
	for (int i = 0; i < n; i++) {
		if (bits[i])
			s += '1';
		else
			s += '0';
	}
	return s;
}


string dexToBin(int num, int n) {
	string snum = std::to_string(num);
	bool bits[128] = { 0 };
	intStringToBits(snum, bits,n);
	return bitsArrayToBitsString(bits,n);
}


string removeHeadZero(string &s) {

	while (s[0] == '0') {
		s = s.substr(1);
	}
	return s;
}


// "12345" * '6'
string multifyIntStringWithChar(string s, char c) {
	int slength = s.size();
	string res = "";
	int reminder = 0;
	int i = slength - 1;

	int top = 0, down=c-'0';
	int temp = 0;
	char r; //
	while (i>=0) {
		top = s[i] - '0';
		temp = top * down+reminder;
		reminder = temp / 10;
		r = temp % 10 + '0';
		//cout << "temp: " << temp << "remider: " << reminder << endl;
		res = r+ res;
		i--;
	}
	if (reminder > 0) {
		r = reminder + '0';
		res = r + res;
	}
	return res;
}

bool isStringValid(string s) {
	if (s.length > 40)
		return 0;

	return 1;
}