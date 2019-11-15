#include "QIntUtility.h"


void numToRBits(const std::string& num, string& bits)
{
	string _num = ltrim(num, '0');
	if (_num == "")
		return;

	//Chia lấy phần dư
	bits += (num[num.length() - 1] - 48) % 2 + 48;
	//bits.insert(bits.begin(), (num[num.length() - 1] - 48) % 2 + 48);

	//Chia lấy phần nguyên
	bool debt = 0;
	for (int i = 0; i < _num.length(); i++)
	{
		if (debt == 0)
		{
			debt = (_num[i] - 48) % 2;
			_num[i] = (_num[i] - 48) / 2 + 48;
		}
		else
		{
			debt = (_num[i] - 48 + 10) % 2;
			_num[i] = (_num[i] - 48 + 10) / 2 + 48;
		}
	}

	numToRBits(_num, bits);
}

void binaryTwoComplements(bitset<128>& bits)
{
	bits.flip();

	bool tmp = 1;
	size_t i = 0;
	do
	{
		if ((bits[i] ^ tmp) == 1)
		{
			bits[i] = bits[i] ^ tmp;
			tmp = 0;
		}
		else
		{
			bits[i] = bits[i] ^ tmp;
		}
		i++;
	} while (tmp != 0 && i <= bits.count());
}
