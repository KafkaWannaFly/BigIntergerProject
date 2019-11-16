#include <iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	QInt pos("1686452", 10);
	QInt neg("-1598047", 10);

	cout << "Pos: " << pos.getHexa() << endl;
	cout << "Neg: " << neg.getHexa() << endl;

	return 0;
}
