#include "MainProcess.h"
#include "utils.h"

string processQInt(string strIn)
{

	QInt q1, q2, res;
	string p1, p2, num1, oper, num2;
	stringstream stream;
	bool isOperand = false;

	//2 1111100011101010111 + 01101110110111 
	//10 2 8793278316383117319 
	string operand[17] = { "+"," - ","*","/",
		"<",">","<=",">=","==",
		"&","|","^","~",
		"<<",">>","rol","ror" };
	int slength = strIn.length();

	for (int i = 0; i < 17; i++) {
		if (strIn.find(operand[i]) != std::string::npos) {
			isOperand = true;
			break;
		}

	}

	//có toán hạng
	if (isOperand) {

		stream << strIn;
		stream >> p1 >> num1 >> oper >> num2;
		if (p1 == "2") {
			//binary
			bool* b1 = binStringToBinArray(num1);

			bool* b2 = binStringToBinArray(num2);


			q1 = QInt::BinToDec(b1);
			q2 = QInt::BinToDec(b2);

			delete[] b1;
			delete[] b2;


		}
		else if (p1 == "10") {
			if (num1.length() > 0)
				q1 = QInt(num1);
			if (num2.length() > 0)
				q2 = QInt(num2);
		}
		else {
			if (num1.length() > 0)
				q1 = QInt::HexToDec(num1);
			if (num2.length() > 0)
				q2 = QInt::HexToDec(num2);
		}

		if (oper == "~")
		{
			res = (~q1);
		}
		else if (oper == "+")
		{
			res = (q1 + q2);

		}
		else if (oper == "-")
		{
			res = (q1 - q2);

		}
		else if (oper == "*")
		{
			res = (q1 * q2);

		}
		else if (oper == "/")
		{
			//try {
			//	cout << "trying to divide\n";
			//	res = q1 / q2;
			//	cout << "done \n";

			//}
			//catch (runtime_error& e) {
			//	cout << "exception occurred" << endl
			//		<< e.what();
			//}
			res = q1 / q2;
		}
		else if (oper == "&")
		{
			res = (q1&q2);
		}
		else if (oper == "|")
		{

			res = q1 | q2;
		}
		else if (oper == "^")
		{
			res = q1 ^ q2;

		}
		else if (oper == "<<")
		{
			res = q1 << stoi(num2);

		}
		else if (oper == ">>")
		{
			res = q1 >> stoi(num2);
		}
		else if (oper == "rol")
		{
			res = q1.rol(stoi(num2));
		}
		else if (oper == "ror")
		{
			res = q1.ror(stoi(num2));

		}
		else if (oper == "<")
		{
			return (q1 < q2) ? "TRUE" : "FALSE";
		}
		else if (oper == ">")
		{
			return ((q1 > q2) ? "TRUE" : "FALSE");
		}
		else if (oper == "<=")
		{
			return ((q1 <= q2) ? "TRUE" : "FALSE");
		}
		else if (oper == ">=")
		{
			return ((q1 >= q2) ? "TRUE" : "FALSE");
		}
		else if (oper == "==")
		{
			return ((q1 == q2) ? "TRUE" : "FALSE");
		}

		// trả về chuỗi bin, dex hoặc hex
		if (p1 == "2") {
			//binary
			return res.shortBin();

		}
		else if (p1 == "10") {
			return res.toString();
		}
		else {
			string hex = QInt::DecToHex(res);
			return standardizeString(hex);
		}
	}

	else {//phép biến đổi bin, dec, hex

		stream << strIn;
		stream >> p1 >> p2 >> num1;
		int base1 = stoi(p1);
		int base2 = stoi(p2);

		if (base1 == 10) {
			if (base2 == 2) {
				//dectobin
				return QInt(num1).shortBin();
			}
			else if (base2 == 16) {
				//dextohex
				string res = QInt::DecToHex(num1);
				return standardizeString(res);
			}
		}

		else if (base1 == 2) {
			//bintodex
			bool *b=binStringToBinArray(num1);
			if (base2 == 10) {
				string res = QInt::BinToDec(b).toString();
				delete[]b;
				return  res;
			}
			else if (base2 == 16) {
				//bintohex
				string res = QInt::BinToHex(b);
				return standardizeString(res);
			}
		}


		else if (base1 == 16) {
			if (base2 == 10) {
			//HexToDec
				return QInt::HexToDec(num1).toString();
			}

			else if (base2 == 2) {
				//hextobin
				bool* b;
				b = QInt::HexToBin(num1);
				string res = binArrayToBinString(b);
				delete[]b;
				return res;
			}
		}

		return "INPUT ERROR!";
	}

}



string processQFloat(string strIn)
{

	QInt q1, q2;
	string p1, p2, num;
	stringstream stream;
	bool isOperand = false;

	stream << strIn;
	stream >> p1 >> p2 >> num;
	int base1 = stoi(p1);
	int base2 = stoi(p2);

	if (base1 == 10 && base2 == 2) {
		//dectobin
		Qfloat q(num);
		bool *b = Qfloat::DecToBin(q);
		string res = (binArrayToBinString(b));
		delete[]b;
		return standardizeString(res);
	}
	else if(base1 == 2 && base2 == 10) {
		//bintodec
		bool* bits = binStringToBinArray(num);
		string res = Qfloat::BinToDec(bits).toString();
		delete[]bits;
		return res;
	}
}