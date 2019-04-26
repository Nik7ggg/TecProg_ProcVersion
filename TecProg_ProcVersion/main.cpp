#include <iostream>
#include <fstream>
#include "Functions.h"
#include "conio.h"

using namespace std;

namespace Big_cars {

	// ��������� ��������� ������� �������
	void Init(Container &c);
	void Clear(Container &c);
	void In(Container &c, ifstream &ifst);
	void Out(Container &c, ofstream &ofst);
	void SortList(Container &obj);
	void OutOnlyTruck(Container &c, ofstream &ofst);
	void MultiMethod(Container s, ofstream &ofst);
}

using namespace Big_cars;

int main(int argc, char* argv[]) {

	/*if (argc != 3) {
	cout << "incorrect command line! "
	"Waited: command infile outfile" << endl;
	exit(1);
	}*/

	string in = "input.txt";
	string out = "output.txt";
	
	ifstream ifst(in);
	ofstream ofst(out);

	if (!ifst.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	if (!ofst.is_open())
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;
	Container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	ofst << endl;

	ofst << "MultyMethod:" << endl;
	MultiMethod(c, ofst);

	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("PAUSE");

	return 0;
}