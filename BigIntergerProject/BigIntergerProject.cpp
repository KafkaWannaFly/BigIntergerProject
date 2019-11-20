#include <iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	try
	{
		QInt pos("1686452", 10);
		QInt neg("-1598047", 10);

		cout << "Pos: " << pos.getBits() << endl;
		cout << "Neg: " << neg.getBits() << endl;

		//cout << "(Pos & Neg): " << (pos & neg).getBits() << endl;
		//cout << "!Neg: " << (!neg).getBits() << endl;

		//cout << "Shift right: " << (neg >> 5) << endl;
		//cout << "pos[127]: " << pos[pos.getSize()-1] << endl;

		cout << "Compare: " << (pos>neg) << endl;

		return 0;

	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
	
}
