#include "QInt.h"

QInt::QInt()
{
	this->m_bits = 0;
}

//QInt::QInt(const string& _num)
//{
//	//Kiểm tra đầu vào
//	for (int i = 0; i<_num.length(); i++)
//	{
//		if (_num[i] > '9' || _num[i] < '0')
//		{
//			if(_num[i] != '-')
//				throw new exception("QInt::QInt(const string&): Can't initialize number which has letter " + _num[i]);
//		}
//	}
//
//	if (_num[0] != '-')	//Posstive 
//	{
//		string bits;
//		numToRBits(_num, bits);
//		
//		for (int i = 0; i < bits.length(); i++)
//		{
//			this->m_bits[i] = bits[i] - 48;
//		}
//	}
//	else	//Negative
//	{
//		string subNum = _num.substr(1, _num.length() - 1);
//		string bits;
//		numToRBits(subNum, bits);
//		reverse(bits.begin(), bits.end());	//Bit 0 nằm ở bên trái nên phải đảo lại
//
//		bitset<128> tmp(bits);
//		binaryTwoComplements(tmp);
//
//		this->m_bits = tmp;
//	}
//}

QInt::QInt(const string& _num, const int& base)
{
	if (base == 2)
	{
		cout << "Is on construction" << endl;
	}
	else if (base == 10)
	{
		//Kiểm tra đầu vào
		for (int i = 0; i < _num.length(); i++)
		{
			if (_num[i] > '9' || _num[i] < '0')
			{
				if (_num[i] != '-')
					throw new exception("QInt::QInt(const string&, const int& base): Can't initialize number which has letter " + _num[i]);
			}
		}

		if (_num[0] != '-')	//Posstive 
		{
			string bits;
			numToRBits(_num, bits);

			for (int i = 0; i < bits.length(); i++)
			{
				this->m_bits[i] = bits[i] - 48;
			}
		}
		else	//Negative
		{
			string subNum = _num.substr(1, _num.length() - 1);
			string bits;
			numToRBits(subNum, bits);
			reverse(bits.begin(), bits.end());	//Bit 0 nằm ở bên trái nên phải đảo lại

			bitset<128> tmp(bits);
			binaryTwoComplements(tmp);

			this->m_bits = tmp;
		}
	}
	else if (base == 16)
	{
		cout << "Is on construction" << endl;
	}
	else
	{
		throw new exception("QInt::QInt(const string&, const int& base): Can't process base " + base);
	}
}

string QInt::getBits()
{
	string bits = ltrim(this->m_bits.to_string(), '0');

	if (bits == "")	//Nếu chuỗi toàn 0 thì sẽ bị trim hết
		bits = "0";

	return bits;
}

string QInt::getHexa()
{
	stringstream ss;
	ss << std::hex;

	for (int i = 0; i < this->m_bits.size(); i += 4)
	{
		bitset<4> tmp;
		for (int j = 0; j < 4; j++)
		{
			tmp[j] = this->m_bits[i + j];
		}
		ss << tmp.to_ulong();
	}

	string output = ss.str();
	stringUpper(output);
	std::reverse(output.begin(), output.end());
	output = ltrim(output, '0');
	return output;
}
