#pragma once

class Qfloat {
private:
	char num[16];
public:
	//Hàm Nhập
	void ScanQfloat(Qfloat &x);
	//Hàm xuất
	void PrintQfloat(Qfloat x);

	// Hàm chuyển đổi số Qfloat nhị phân sang thập phân
		Qfloat BinToDec(bool *bit);
	//Hàm chuyển đổi số Qfloat thập phân sang nhị phân
	bool *DecToBin(Qfloat x);
};