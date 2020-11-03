#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
using namespace std;

//-------QINT 
// dua mang bits ve dang bu 2
void bu2(bool *bits, int n=128);

//s='1'->1
int charToInt(char c);

//hàm chia đôi int string , trả về mảng bits
string half(string s, bool &bit);

//"123" => 101010
void intStringToBits(string s, bool *bits, int n=128);

//"123"*3 ="369"
string multifyStringWithNum(string , int );

//twoPowNum(3)--> "8"
//(2^3 == 8)
string twoPowNum(int n);

//"123"+"654" --> "777"
string AddTwoIntString(string , string );

//[1,1,0,0] --> 12
string binToQInt(bool* bits, int n=128);

//------CONVERT

// "1010"-->[1,0,1,0]
bool* binStringToBinArray(string s);
//[1,0,1,0]-->"1010"
string binArrayToBinString(bool* bits, int n=128);
//[1,0,1,1] => 11
int BinArrayToInt(bool *, int n = 32);
//12 --> "1100"
string IntToBin(int num, int n = 128);

//-----CHUẨN HOÁ CHUỖI

//"000123"-->"123"
string removeHeadZero(string &s);

//Chuẩn hoá string
string standardizeString(string);

//kiểm tra 1 kí tự có phải là digit
bool isDigit(char);
//remove kí tự đặc biệt ex: "12!@3" --> "123"
string remove_non_digits(const string);
//"00000"===0
bool isBinStringZero(string);
//kiểm tra chuỗi digit là 0 (có dấu)
bool isIntStringZero(string);



//-----TÍNH TOÁN VỚI CHUỖI
string multifyIntStringWithChar(string s, char c);

//chuyển phần lẻ số thực về dạng nhị phân
//"03597" --> "00011"
string decimalPartToBin(string, int );

// n=3 --> "125" (2^-3 == 0.125)
string half_pow_num(int n);

//add_two_flt_string("125","0625")-->"1875"
//(2^-3 + 2^-4 == 0.1875)
string add_two_flt_string(string s1, string s2);







#endif