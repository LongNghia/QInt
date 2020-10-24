#include"utils.h"
#include "QInt.h"

//cout << SubTwoIntString("12321", "9099");=32222

//string SubTwoIntString(string num1, string num2) {
//
//	string result = "";
//	int reminder = 0;
//	int pointerNum1 = num1.length() - 1;
//	int pointerNum2 = num2.length() - 1;
//	int sub = 0;
//	for (int i = 0; i < pointerNum1 - pointerNum2; i++) {
//		num2 = '0' + num2;
//	}
//	cout << "\ns1=" << num1 << endl;
//	cout << "\ns2=" << num2 << endl;
//
//	bool first = false;
//	int temp = 0;
//	while(te)
//	while (pointerNum1) {
//		//if (pointerNum2 < 0)
//
//		if (num1[pointerNum1] < num2[pointerNum2] + reminder) {
//			reminder = 1;
//		}
//		else {
//
//			reminder = 0;
//
//		}
//		sub = num1[pointerNum1] + 10 * reminder - num2[pointerNum2];
//
//
//		pointerNum1--;
//		pointerNum2--;
//		result += sub + '0';
//		cout << "res=" << sub << "\n";
//	}
//
//	return result;
//}


int main() {
	//
	//truong hop -0
	//QInt q;
	//cout << "nhap chuoi: ";

	//string s;
	//getline(cin, s);
	//cout << "\nxuat chuoi: \n";
	//q.ScanQInt(s);
	//q.PrintQInt();

	//QInt q("12345");
	//QInt p("65432");
	//p.PrintQInt();
	//q.PrintQInt();

	//QInt c = q;
	//c.PrintQInt();


	////phép cộng chạy chưa đúng!!!
	//QInt Sum = q + p;
	//Sum.PrintQInt();


	///-----TEST Ở ĐÂY


	//cout<<AddTwoIntString("123456789123456789", "123165135132155");


	QInt q ("123456");
	q.PrintQInt();

	




















	//-----------------





	//dex to bin string
//	int num = 123;
//	string snum = std::to_string(num);
//	bool bits[128] = { 0 };
//	intStringToBits(snum, bits);
//	for (int i = 0; i < 128; i++) {
//		cout << bits[i] << "";
//}
//	cout << endl << bitsArrayToBitsString(bits) << endl;;

	//--------bits array to dex
	//bool bits[128] = {0};
	//string s2 = "01010110";
	//bitsintStringToBitsArray(s2, bits);
	//cout << endl << "bits to dex: " << bitsToDex(bits) << endl;

	//-------string to bits array
	//string snum = "23";
	//bool b[128] = {0};
	//intStringToBits(snum, b);
	//for (int i = 0; i < 128; i++) {
	//	cout << b[i] << "";
	//}



//	----------bitsintStringToBitsArray(sbits, bits);
	//bool bits[128] = {0};
	//string s2 = "000000000010110011001011100100101100110001011010011001";
	//bitsintStringToBitsArray(s2, bits);
	//for (int i = 0; i < 128; i++) {
	//	cout << bits[i] << " ";
	//}



	//---------------bitarray to string
	//bool b[128] = { 1,0,1,0,1,0 };
	//cout << bitsArrayToBitsString(b);

	//bits to dex
	//string s = "101010101";
	//bool bitts[128] = {0};
	//bitsintStringToBitsArray(s, bitts);
	//cout << endl;
	//for (int i = 0; i < 128; i++) {
	//	cout << bitts[i] << " ";
	//}
	//cout << endl;

	//cout << bitsToDex(bitts);


	//string num = "2";
	//cout << "2 mu n: \n" << twoPowNum(64);

	//string s1 = "123";
	//string s2 = "234";
	//cout << AddTwoIntString(s1, s2);



	//bits
	//int b = 6 & 5;
	//cout << "6&5: " << b;

	//cout << add2IntString("12345", "54321");

	//cout << getBit_i(25, 3);
	//int n = 25;
	//OneOn(n, 30);
	//cout << n;

	//string s;
	//getline(cin, s);
	//cout << s;
	//cin >> n;
	//cout << n;
	//return 0;
	//
	//cout << "size of n: \n" << sizeof(n)/sizeof(int)<<"\n";
	//cout << "size of n: \n" << n.size() << "\n";

	//displayArray(n);
	//int *m;
	//m = half(n);
	//displayArray(n);
	//cout<<stringToInt("12345");

	//string s = "hello this is nghia";
	//cout << s.substr(0, 4)<<endl;

	//chia doi
//	string s = "0000000";
//	bool bits[128] = { 0 };
//	bool bit;
//	intStringToBits(s, bits);
//	string temp;
//
//	cout << "Day bit:" << endl;
//for (int i = 0; i < 128; i++) {
//	cout << bits[i] << " ";
//}

	//bu 2
	//bool bitts[128] = { 0,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0 };
	//bu2(bitts);

	//for (int i = 0; i < 128; i++) {
	//	cout << bitts[i] << " ";
	//}


	//array of bits
	//temp = s;
	//int i = 0;

	//while (temp.size()) {
	//	temp = half(temp, bit);
	//	cout << temp << endl;
	//	bits[i++] = bit;
	//}

	//cout << "Day bit:" << endl;
	//for (i = 0; i < 128; i++) {
	//	cout << bits[i] << " ";
	//}
	//toReBits(s, bits);
	//cout << "Day bit:" << endl;
	//for (int i = 0; i < 128; i++) {
	//	cout << bits[i];
	//}

	//dao bit
	//bool a = 1;
	//cout <<"dao bit"<< !a << " "<<!!a;

	//'7'-> '6'
	//s[6] -= 1;
	//cout << s;


	//s[5] = '2'; 
	//cout<<"size: "<<s.size();
	//string s2 = "1";
	//cout << stoi(s2.append(s)) + 1;
	//cout << charToInt('5');

	//string a="";
	//a += '0';
	//a += '1';
	//a += '2';
	//a += '3';

	//cout << a;

	//remove head's zeroes
	//string q = "13211";
	//cout << "susstring: "<<q.substr(1);
	//cout << "removed: " << removeHeadZero(q);


	//he so nguyen tong quat
	//bool bits[32] = { 0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	//cout << "ket qua"<< convertBinArrayToDex(bits);


	return 0;
}

