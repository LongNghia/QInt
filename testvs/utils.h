#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
using namespace std;

int stringToInt(string s);

// dua mang bits ve dang bu 2
void bu2(bool *bits, int n=128);

//s='1'->1
int charToInt(char c);

//hàm chia đôi int string , trả về mảng bits
string half(string s, bool &bit);

//"123" => 101010
void intStringToBits(string s, bool *bits, int n=128);

bool getLastBit(int n);

//[1,0,1,1] => 11
int convertBinArrayToDex(bool *, int n=32);

//"123"*3 ="369"
string multifyStringWithNum(std::string num1, int num2);

string twoPowNum(int n);

string AddTwoIntString(std::string num1, std::string num2);

string bitsToDex(bool* bits, int n=128);

void bitsintStringToBitsArray(string s, bool* bits);

string bitsArrayToBitsString(bool* bits, int n=128);

string dexToBin(int num, int n = 128);

string removeHeadZero(string &s);

string multifyIntStringWithChar(string s, char c);

bool isStringValid(string s);


#endif