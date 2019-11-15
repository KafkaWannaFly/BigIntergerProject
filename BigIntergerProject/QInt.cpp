#include "QInt.h"

QInt::QInt()
{
	this->m_bits = 0;
}

QInt::QInt(const string& decimalNum)
{
	if (decimalNum[0] != '-')	//Posstive 
	{
		string bits;
		numToRBits(decimalNum, bits);
		
		for (int i = 0; i < bits.length(); i++)
		{
			this->m_bits[i] = bits[i] - 48;
		}
	}
	else	//Negative
	{
		string subNum = decimalNum.substr(1, decimalNum.length() - 1);
		string bits;
		numToRBits(subNum, bits);
		reverse(bits.begin(), bits.end());	//Bit 0 nằm ở bên trái nên phải đảo lại

		bitset<128> tmp(bits);
		binaryTwoComplements(tmp);

		this->m_bits = tmp;
	}
}

string QInt::getBits()
{
	string bits = ltrim(this->m_bits.to_string(), '0');

	if (bits == "")	//Nếu chuỗi toàn 0 thì sẽ bị trim hết
		bits = "0";

	return bits;
}
