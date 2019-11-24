#include <iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	try
	{
		QInt pos("55", 10);
		QInt neg("-33", 10);

		cout << "Pos: " << pos << endl;
		cout << "Neg: " << neg << endl;

		//cout << "(Pos & Neg): " << (pos & neg).getBits() << endl;
		//cout << "!Neg: " << (!neg).getBits() << endl;

		//cout << "Shift right: " << (neg >> 5) << endl;
		//cout << "pos[127]: " << pos[pos.getSize()-1] << endl;

		//cout << "Compare: " << (pos>neg) << endl;

		cout << "Sum: "<< (pos + neg).getDecimal() << endl;
		//cout << "Sub: " << (pos - neg).getDecimal() << endl;

		QInt Multi = pos * neg;
		cout << "Muli: " << Multi.getDecimal() << endl;
	
		return 0;

	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
	
}
