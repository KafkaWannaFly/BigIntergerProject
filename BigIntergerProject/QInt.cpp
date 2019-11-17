#include "QInt.h"

QInt::QInt()
{
	this->m_bits = 0;
}

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
					throw exception(s_ExceptionsDictionary[exceptionKey::UNHANDLED_CHARACTER].c_str());
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
		//Kiểm tra đầu vào
		string hexNum = _num;
		stringUpper(hexNum);
		for (int i = 0; i < hexNum.length(); i++)
		{
			if (hexNum[i] < '0' || hexNum[i] > '9')
			{
				if (hexNum[i] < 'A' || hexNum[i] > 'F')
				{
					throw exception(s_ExceptionsDictionary[exceptionKey::UNHANDLED_CHARACTER].c_str());
				}
			}
		}

		string binNum;	//Xử lý từng chữ số thập lục phân
		for (int i = 0; i < hexNum.length(); i++)
		{
			if (hexNum[i] > '0' && hexNum[i] < '9')
			{
				//Nếu char từ '0' -> '9' thì trừ 48 để có giá trị int phù hợp
				bitset<4> tmp(hexNum[i] - 48);	
				binNum += tmp.to_string();
			}
			else
			{
				//Nếu char từ 'A' -> 'F' thì trừ 55 để có giá trị int phù hợp
				//Vì ở trên đã kiểm tra đầu vào nên sẽ chỉ có 2 trường hợp này thôi
				bitset<4> tmp(hexNum[i] - 55);
				binNum += tmp.to_string();
			}
		}

		//std::reverse(binNum.begin(), binNum.end());
		this->m_bits = bitset<128>(binNum);
	}
	else
	{
		throw exception(s_ExceptionsDictionary[exceptionKey::WRONG_BASE].c_str());
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
