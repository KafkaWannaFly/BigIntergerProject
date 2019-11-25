#include<iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	try
	{
		QInt pos("9", 10);
		QInt neg("0", 10);

		cout << "Pos: " << pos << endl;
		cout << "Neg: " << neg << endl;

		//cout << "(Pos & Neg): " << (pos & neg).getBits() << endl;
		//cout << "!Neg: " << (!neg).getBits() << endl;

		//cout << "Shift right: " << (neg >> 5) << endl;
		//cout << "pos[127]: " << pos[pos.getSize()-1] << endl;

		//cout << "Compare: " << (pos>neg) << endl;

		cout << "Sum: "<< (pos + neg).getDecimal() << endl;

		QInt sub = pos - neg;
		cout << "Sub: " << sub.getDecimal() << endl;

		cout << "Muli: " << (pos * neg).getDecimal() << endl;
	
		return 0;

	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
	
}