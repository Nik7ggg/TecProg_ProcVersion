#include <iostream>
#include <fstream>
#include "Functions.h"
#include "conio.h"
using namespace std;
namespace Big_cars {
	// ��������� ��������� ������� �������
	void Init(container &c);
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void SortList(container &obj);
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
	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	SortList(c);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("PAUSE");
	return 0;
}