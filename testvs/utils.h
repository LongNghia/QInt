#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
using namespace std;

int stringToInt(string s);

// dua mang bits ve dang bu 2
void bu2(bool *bits);

//s='1'->1
int charToInt(char c);

//hàm chia đôi int string , trả về mảng bits
string half(string s, bool &bit);

//"123" => 101010
void intStringToBits(string s, bool *bits);

bool getLastBit(int n);

//[1,0,1,1] => 11
int convertBinArrayToDex(bool *, int);

//"123"*3 ="369"
string multifyStringWithNum(std::string num1, int num2);

string twoPowNum(int n);

string AddTwoIntString(std::string num1, std::string num2);

string bitsToDex(bool* bits);

void bitsintStringToBitsArray(string s, bool* bits);

string bitsArrayToBitsString(bool* bits);

string dexToBin(int num);

#endif
