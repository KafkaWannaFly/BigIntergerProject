
#include"QIntUtility.h"

//Chuyển từ hệ 10 sang 2
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

//Lấy bù 2
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
	} while (tmp != 0 && i <= bits.size());
}


void CutDecimal(string& S)
{
	//Cắt số 0 sau đấu phẩy ..,0000000
	string S_temp;
	for (int i = 0; i < (S.length() - 7); i++)
	{
		S_temp += S[i];
	}
	S = S_temp;
}

void Split_String(vector<string>& S, const string& Bits)
{
	//Thực hiện phép chuyển từ nhị phân sang thập phân
	//1010 = 1*2^1 + 1*2^3
	int check = 0;
	string s_temp;
	int j = 0;
	for (int i = Bits.size() - 1; i >= 0; i--)
	{
		int check = 0;
		if (Bits[i] == '1')
		{
			check = 1;
		}
		s_temp = to_string(check * pow(2, j));
		CutDecimal(s_temp); //Cắt số 0 sau dấu phẩy
		S.push_back(s_temp);
		j++;
	}
}

void Push_String(string& s1, string& s2)
{
	//Thêm 0 để 2 chuỗi thành cùng độ dài
	if (s1.length() > s2.length())
	{
		int value = s1.length() - s2.length();
		for (int i = 1; i <= value; i++)
		{
			s2.insert(0, "0");
		}
	}
	else if (s2.length() > s1.length())
	{
		int value = s2.length() - s1.length();
		for (int i = 1; i <= value; i++)
		{
			s1.insert(0, "0");
		}
	}
}
void Sum_String(string& sum, string s2)
{
	Push_String(sum, s2); //cân bằng độ dài 2 chuỗi
	int sur = 0;
	int res = 0;
	int index = 0;
	//tính tổng
	for (int i = sum.length() - 1; i >= 0; i--)
	{
		res = (sum[i] - 48) + (s2[i] - 48) + sur;
		sur = res / 10;
		sum[i] = (res % 10) + 48;
	}
	if (sur != 0)
	{
		sum.insert(0, 1, sur + 48); //thêm phần dư vào đầu
	}
}

void Sum_String2(string& sum, const string& s2)
{
	//Push_String(sum, s2);
	int sur = 0;
	int res = 0;
	int index = 0;
	for (int i = sum.length() - 1; i >= 0; i--)
	{
		res = (sum[i] - 48) + (s2[i] - 48) + sur;
		sur = res / 10;
		sum[i] = (res % 10) + 48;
	}
	if (sur != 0)
	{
		sum.insert(0, 1, sur + 48);
	}
}


void Subtract_String(string& sub, string s2)
{
	Push_String(sub, s2); //cân bằng độ dài 2 chuỗi
	int sur = 0;
	int res = 0;
	int index = 0;
	string SUB;
	int n = s2.length();
	//tính hiệu
	// -14 + 28 = -(28 - 14)
	for (int i = n - 1; i >= 0; i--)
	{
		res = (s2[i] - 48) - (sub[i] - 48) - sur;
		if (res < 0)
		{
			SUB.insert(0, 1, res + 10 + 48);
			sur = 1;
		}
		else
		{
			SUB.insert(0, 1, res + 48);
			sur = 0;
		}
	}
	//xóa số 0 thừa ở đầu dãy bit
	int i_check = 0;
	for (int j = 0; j < n; j++)
	{
		if (SUB[j] == '0')
		{
			i_check++;
		}
		else
		{
			break;
		}
	}
	SUB.erase(0, i_check);
	//Thêm dấu cho quá trình tính toán
	sub = '-' + SUB;
}
void Convert_Binary_Decimal(string& Dec, const string& Bits)
{
	//int radix1, radix2;

	//loadDataBinaryTxT("input.txt", radix1, radix2);

	//string S1, S2;

	vector<string> S_temp;
	Split_String(S_temp, Bits); //tính 1*2^n khi đổi bit ra dec

	//Cộng các 2^n lại với nhau
	for (int i = 0; i < S_temp.size(); i++)
	{
		//cout << S_temp[i] << endl;
		if (i == S_temp.size() - 1 && Bits[0] == '1' && Bits.size() == 128) //Kiểm tra số âm
		{
			Subtract_String(Dec, S_temp[i]); //Trừ
		}
		else
		{
			Sum_String(Dec, S_temp[i]); //Cộng
		}
	}
}