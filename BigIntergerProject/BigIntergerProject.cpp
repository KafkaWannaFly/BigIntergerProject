#include <iostream>
#include <string>
#include "Misc.h"
#include "QInt.h"

using namespace std;

int main()
{
	try
	{
		/*QInt pos("1686452", 10);
		QInt neg("-1598047", 10);

		cout << "Pos: " << pos.getHexa() << endl;
		cout << "Neg: " << neg.getHexa() << endl;*/

		QInt hex("3D4Y", 169);
		cout << hex.getBits();

		return 0;

	}
	catch (const std::exception&e)
	{
		cout << e.what();
	}
	
}
