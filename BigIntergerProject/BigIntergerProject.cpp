#include <iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	QInt pos("10");
	QInt neg("-150");

	cout << "Pos: " << pos.getBits() << endl;
	cout << "Neg: " << neg.getBits() << endl;

	return 0;
}
