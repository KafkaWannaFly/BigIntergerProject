#include <string>
#include "Misc.h"
#include "QInt.h"
#include "QFile.h"

using namespace std;

int main(int argu, char** path)
{
	try
	{
		if (argu < 2)
		{	
			throw exception(sExceptionsDictionary[exceptionKey::CANT_OPEN_FILE].c_str());
		}

		QFile file;
		file.readInputTXT(path[1]);
		file.saveOutputTXT(path[2]);

		/*QInt pos("51020811559739511523931749439", 10);
		QInt neg("-2648426894534587", 10);

		cout << "v1 = " << pos << endl;
		cout << "v2 = " << neg << endl;

		cout << ">DECIMAL" << endl;
		cout << "v1 = " << pos.getDecimal() << endl;
		cout << "v2 = " << neg.getDecimal() << endl;

		cout << ">HEXA-DECIMAL" << endl;
		cout << "v1 = " << pos.getHexaDecimal() << endl;
		cout << "v2 = " << neg.getHexaDecimal() << endl;*/

		/*pos.rotateRight(1);
		cout << "v1 ror 1 = \n   " << pos << endl;
		neg.rotateLeft(1);
		cout << "v2 rol 1 = \n   " << neg << endl;*/

		/*cout << "v1 SHL 5:\n   " << (pos << 5).getBits() << endl;
		cout << "v1 SHR 5:\n   " << (pos >> 5).getBits() << endl;

		cout << "v2 SHL 5:\n   " << (neg << 5).getBits() << endl;
		cout << "v2 SHR 5:\n   " << (neg >> 5).getBits() << endl;*/

		/*cout << "(v1 AND v2) = \n   " << (pos & neg).getBits() << endl;
		cout << "(v1 OR v2) = \n   " << (pos | neg).getBits() << endl;
		cout << "(v1 XOR v2) = \n   " << (pos ^ neg).getBits() << endl;

		cout << "(NOT v1) = \n   " << (!pos).getBits() << endl;
		pos.doTwoComplements();
		cout << "v1 two complements = \n   " << pos.getBits() << endl;

		cout << "(NOT v2) = \n   " << (!neg).getBits() << endl;
		neg.doTwoComplements();
		cout << "v2 two complements = \n   " << neg.getBits() << endl;*/

		//QInt sum = pos + neg;
		//QInt sub = pos - neg;
		//QInt divide = pos / neg;

		//cout << "Sum: " << sum.getDecimal() << endl;
		//cout << "Sub: " << sub.getDecimal() << endl;
		////cout << "Muli: " << (pos*neg).getDecimal() << endl;
		//cout << "Divide: " << divide.getDecimal() << endl;


		//cout << "(Pos & Neg): " << (pos & neg).getBits() << endl;
		//cout << "!Neg: " << (!neg).getBits() << endl;

		//cout << "Shift right: " << (neg >> 5) << endl;
		//cout << "pos[127]: " << pos[pos.getSize()-1] << endl;

		//cout << "Compare: " << (pos>neg) << endl;

		//string tmp = QFile::processRecord(file[92]);
		return 0;

	}
	catch (const std::exception & e)
	{
		cout << e.what();
	}

}
