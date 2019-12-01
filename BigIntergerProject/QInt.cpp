#include"QInt.h"
QInt::QInt()
{
	this->m_bits = 0;
}

QInt::QInt(const QInt& bits)
{
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		this->m_bits[i] = bits.m_bits[i];
	}
}

QInt::QInt(const bitset<128>& bits)
{
	this->m_bits = bits;
}

QInt::QInt(const bool& valueOfAllBits)
{
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		this->m_bits[i] = valueOfAllBits;
	}
}

QInt::QInt(const string& bits)
{
	bitset<128> bit(bits);
	this->m_bits = bit;
}

QInt::QInt(const string& _num, const int& base)
{
	if (base == 2)
	{
		bitset<128> tmp(_num);
		this->m_bits = tmp;
	}
	else if (base == 10)
	{
		//Kiểm tra đầu vào
		for (int i = 0; i < _num.length(); i++)
		{
			if (_num[i] > '9' || _num[i] < '0')
			{
				if (_num[i] != '-')
					throw exception(sExceptionsDictionary[exceptionKey::UNHANDLED_CHARACTER].c_str());
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
	else if (base == 16) //FIX Ở ĐÂY
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
					throw exception(sExceptionsDictionary[exceptionKey::UNHANDLED_CHARACTER].c_str());
				}
			}
		}

		string binNum;	//Xử lý từng chữ số thập lục phân
		for (int i = 0; i < hexNum.length(); i++)
		{
			if (hexNum[i] >= '0' && hexNum[i] <= '9')
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
		throw exception(sExceptionsDictionary[exceptionKey::WRONG_BASE].c_str());
	}
}

void QInt::doTwoComplements()
{
	bitset<128> bits = this->m_bits;
	binaryTwoComplements(bits);
	this->m_bits = bits;
}

string QInt::getBits()
{
	string bits = ltrim(this->m_bits.to_string(), '0');

	if (bits == "")	//Nếu chuỗi toàn 0 thì sẽ bị trim hết
		bits = "0";

	return bits;
}

string QInt::getHexaDecimal()
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

string QInt::getDecimal()
{
	string output;
	Convert_Binary_Decimal(output, this->m_bits.to_string());
	return output;
}

size_t QInt::getSize()
{
	return this->m_bits.size();
}

QInt QInt::getTwoComplements()
{
	bitset<128> bits(this->getBits());
	binaryTwoComplements(bits);
	return QInt(bits);
}

void QInt::rotateLeft(const unsigned int& num)
{
	this->m_bits = (this->m_bits << num) | (this->m_bits >> (128 - num));
}

void QInt::rotateRight(const unsigned int& num)
{
	this->m_bits = (this->m_bits >> num) | (this->m_bits << (128 - num));
}

QInt& QInt::operator=(const QInt& qNum)
{
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		this->m_bits[i] = qNum.m_bits[i];
	}
	return *this;
}

QInt QInt::operator+(const QInt& qNum)
{
	QInt sum;
	bool carry = 0;
	//0110
	//1101
	//0011
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		int tmp = this->m_bits[i] + qNum.m_bits[i] + carry;
		carry = tmp / 2;
		sum.m_bits[i] = tmp % 2;
	}
	return sum;
}

QInt QInt::operator-(const QInt& qNum)
{
	QInt result;

	//if (qNum.m_bits[qNum.m_bits.size() - 1] == 0)
	//{
	//	bitset<128> twoComplement(qNum.m_bits);
	//	binaryTwoComplements(twoComplement);
	//	QInt contrastQNum(twoComplement);
	//	result = *this + contrastQNum;
	//}
	//else
	//{
	//	result = *this + qNum;
	//}

	//bitset<128> twoComplement(qNum.m_bits);
	//binaryTwoComplements(twoComplement);
	QInt contrastQNum = qNum;
	contrastQNum.doTwoComplements();
	result = (*this) + contrastQNum;

	return result;
}

QInt QInt::operator*(QInt& qNum)
{
	QInt sum, n;
	bool carry = 0;
	int k = 0, check1 = 0, check2 = 0;
	if (this->m_bits[127] == 1) //xử lý số âm
	{
		binaryTwoComplements(this->m_bits); //chuyển về số dương
		check1 = 1;
	}
	if (qNum.m_bits[127] == 1) //xử lý số âm
	{
		binaryTwoComplements(qNum.m_bits); //chuyển về số dương
	}
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		//1111
		//1010
		//0000
		//111
		//...
		//Nhân
		if (qNum.m_bits[i] == 1)
		{
			n = *this; 
		}
		else if (qNum.m_bits[i] == 0)
		{
			n.m_bits = 0;
		}
		int j = 0;
		//Cộng
		for (int i = 0; i < this->m_bits.size(); i++)
		{
			if (i >= k)
			{
				int tmp = sum.m_bits[i] + n.m_bits[j] + carry;
				carry = tmp / 2;
				sum.m_bits[i] = tmp % 2;
				j++;
			}
		}
		k++;
	}
	if (check1 == 1 && check2 == 2)
	{
		return sum; //cả 2 cùng âm => return sum dương
	}
	else if (check1 == 1 || check2 == 2)
	{
		binaryTwoComplements(sum.m_bits); //1 trong 2 âm => đổi sum thành âm
	}
	return sum;
}

QInt QInt::operator/(const QInt& qNum)
{
	if (QInt(0) == qNum)
	{
		throw exception(sExceptionsDictionary[exceptionKey::DIVIDE_ZERO].c_str());
	}

	QInt dividend = *this;	//Số bị chia
	QInt divider = qNum;	//Số chia
	/*
	if(dividend > 0)
		surplus = 0000...
	else
		surplus = 1111...
	*/

	//Chuyển về số dương để chia, yu1 chia xong thì lật lại
	int toBeFlipped = 0;
	if (dividend.m_bits[dividend.m_bits.size() - 1] == 1)	//dividend < 0
	{
		dividend.doTwoComplements();
		toBeFlipped++;
	}
	if (divider.m_bits[divider.m_bits.size() - 1] == 1)	//divider < 0
	{
		divider.doTwoComplements();
		toBeFlipped++;
	}

	QInt surplus(dividend.m_bits[this->m_bits.size() - 1]); //Số dư

	int k = dividend.m_bits.size();
	while (k > 0)
	{
		//Coi surplus và dividend như 1 chuỗi bit. Shift trái 1 bit
		surplus = surplus << 1;
		surplus.m_bits[0] = dividend.m_bits[dividend.m_bits.size() - 1];
		dividend = dividend << 1;

		surplus = surplus - divider;
		if (surplus.m_bits[surplus.m_bits.size() - 1] == 1)	//surplus < 0
		{
			dividend.m_bits[0] = 0;
			surplus = surplus + divider;
		}
		else
		{
			dividend.m_bits[0] = 1;
		}
		k--;
	}

	if (toBeFlipped % 2 == 1)
	{
		dividend.doTwoComplements();
	}

	return dividend;
}

QInt QInt::operator&(const QInt& qNum)
{
	return QInt(this->m_bits & qNum.m_bits);
}

QInt QInt::operator|(const QInt& qNum)
{
	return QInt(this->m_bits | qNum.m_bits);
}

QInt QInt::operator^(const QInt& qNum)
{
	return QInt(this->m_bits ^ qNum.m_bits);
}

QInt QInt::operator!()
{
	QInt tmp = *this;
	return tmp.m_bits.flip();
}

QInt QInt::operator<<(const unsigned int& num)
{
	QInt result = this->m_bits << num;
	return result;
}

QInt QInt::operator>>(const unsigned int& num)
{

	if (this->m_bits[this->m_bits.size() - 1] == 0)
	{
		QInt out = this->m_bits >> num;
		return out;
	}
	else
	{
		QInt out = this->m_bits >> num;
		for (int i = m_bits.size() - 1; i >= m_bits.size() - num; i--)
		{
			out.m_bits[i] = 1;
		}
		return out;
	}
}

bool QInt::operator[](const size_t& index)
{
	if (index >= this->m_bits.size())
	{
		throw exception(sExceptionsDictionary[exceptionKey::INDEX_OUT_OF_BOUND].c_str());
	}

	return this->m_bits[index];
}

bool QInt::operator>(const QInt& qNum)
{
	if (this->m_bits[this->m_bits.size() - 1] < qNum.m_bits[this->m_bits.size() - 1])
		return true;
	else if (this->m_bits[this->m_bits.size() - 1] > qNum.m_bits[this->m_bits.size() - 1])
		return false;

	bool switcher = false;
	for (int i = 0; i < this->m_bits.size() - 1; i++)
	{
		if (this->m_bits[i] > qNum.m_bits[i])
			switcher = true;
		else
			switcher = false;
	}
	return switcher;
}

bool QInt::operator<(const QInt& qNum)
{
	if (this->m_bits[this->m_bits.size() - 1] < qNum.m_bits[this->m_bits.size() - 1])
		return false;
	else if (this->m_bits[this->m_bits.size() - 1] > qNum.m_bits[this->m_bits.size() - 1])
		return true;

	bool switcher;
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		if (this->m_bits[i] > qNum.m_bits[i])
			switcher = false;
		else
			switcher = true;
	}
	return switcher;
}

bool QInt::operator!=(const QInt& qNum)
{
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		if (this->m_bits[i] != qNum.m_bits[i])
			return true;
	}
	return false;
}

bool QInt::operator==(const QInt& qNum)
{
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		if (this->m_bits[i] != qNum.m_bits[i])
			return false;
	}
	return true;
}

bool QInt::operator>=(const QInt& qNum)
{
	if (this->m_bits[this->m_bits.size() - 1] < qNum.m_bits[this->m_bits.size() - 1])
		return true;
	else if (this->m_bits[this->m_bits.size() - 1] > qNum.m_bits[this->m_bits.size() - 1])
		return false;

	bool switcher;
	for (int i = 0; i < this->m_bits.size() - 1; i++)
	{
		if (this->m_bits[i] >= qNum.m_bits[i])
			switcher = true;
		else
			switcher = false;
	}
	return switcher;
}

bool QInt::operator<=(const QInt& qNum)
{
	if (this->m_bits[this->m_bits.size() - 1] < qNum.m_bits[this->m_bits.size() - 1])
		return false;
	else if (this->m_bits[this->m_bits.size() - 1] > qNum.m_bits[this->m_bits.size() - 1])
		return true;

	bool switcher;
	for (int i = 0; i < this->m_bits.size(); i++)
	{
		if (this->m_bits[i] >= qNum.m_bits[i])
			switcher = false;
		else
			switcher = true;
	}
	return switcher;
}

ostream& operator<<(ostream& out, const QInt& qNum)
{
	out << qNum.m_bits;
	return out;
}
