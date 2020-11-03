#include"utils.h"
#include "QInt.h"
#include "Qfloat.h"
#include "MainProcess.h"
#include <fstream>
#include <unordered_map>


int main(int argc, char** argv)
{
	string inPath, outPath, mode;

	argc = 4;


	if (argc < 4) {
		cout << "Require 4 arguments!\n";
		cout << "ex: 18120479_18120491_18120525.exe input.txt output.txt 2\n";
	}

	else
	{
		inPath = string(argv[1]);
		outPath = string(argv[2]);
		mode = string(argv[3]);

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

	getch();
	return 0;
}


int main2(){
	//Qfloat a = Qfloat::BinToDec(binStringToBinArray("01000000000000111010011111111111111111111111110001110000010011001111000101010111010000101111011101000101010110001011100100010100"));
	//a.PrintQfloat();

	Qfloat a("s");
	cout << binArrayToBinString(Qfloat::DecToBin(a));
	return 0;
}