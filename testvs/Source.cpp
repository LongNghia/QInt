#include"utils.h"
#include "QInt.h"
#include "Qfloat.h"
#include "MainProcess.h"
#include <fstream>
#include <unordered_map>

//SỬA
//-0
//sai dòng 6 trừ hex


int main(int argc, char** argv)
{
	string inPath, outPath, mode;

	argc = 4;


	if (argc < 4)
		cout << "Du lieu khong hop le!";
	else
	{
		//inPath = string(argv[1]);
		//outPath = string(argv[2]);
		//mode = string(argv[3]);

		inPath = "input1.txt";
		outPath = "output1.txt";
		mode = "1";

		ifstream myfile(inPath);
		ofstream out(outPath);

		if (myfile.is_open())
		{
			string line;
			int i = 1;
			while (getline(myfile, line))
			{
				cout << "line " << i++ << endl;
				if (mode == "2") {
					cout << processQFloat(line) << endl;
					out << processQFloat(line) << endl;

				}
				else if (mode == "1") {
					cout << processQInt(line) << endl;
					out << processQInt(line) << endl;
				}
			}
			myfile.close();
			out.close();
		}

		else cout << "Unable to open file";
	}

	return 0;
}

int main2(){
	QInt a("345698463159486315206");
	QInt b("23");
	QInt res = a / b;
	cout<<res.toString();
	return 0;
}