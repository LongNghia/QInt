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
string multifyStringWithNum(string , int );

string twoPowNum(int n);

string AddTwoIntString(string , string );

string bitsToDex(bool* bits, int n=128);

void bitsintStringToBitsArray(string s, bool* bits);

string bitsArrayToBitsString(bool* bits, int n=128);

string dexToBin(int num, int n = 128);

string removeHeadZero(string &s);

string multifyIntStringWithChar(string s, char c);

string doubleflt(string, int );

bool isBinStringZero(string);

// Chuẩn hoá string
string standardizeString(string);

//kiểm tra 1 kí tự có phải là digit
bool isDigit(char);

//remove kí tự đặc biệt ex: "12!@3" --> "123"
string remove_non_digits(const string);

//kiểm tra chuỗi digit là 0
bool isIntStringZero(string);

#endif