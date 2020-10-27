#pragma once
#include <iostream>
#include <string>
using namespace std;


class Qfloat {
private:
	char num[16];
public:
	Qfloat();
	Qfloat(string);
	Qfloat(char* );
public:
	

	//Hàm Nhập
	void ScanQfloat(string s);
	//Hàm xuất
	void PrintQfloat();

	// Hàm chuyển đổi số Qfloat nhị phân sang thập phân
	Qfloat BinToDec(bool *bit);
	//Hàm chuyển đổi số Qfloat thập phân sang nhị phân
	bool *DecToBin(Qfloat x);
};