#pragma once
#include <map>
#include "Misc.h"

using namespace std;

enum exceptionKey
{
	WRONG_BASE,
	UNHANDLED_CHARACTER,
	INDEX_OUT_OF_BOUND
};
/*
	Từ điển exception. Cần throw cái gì thì vô đây xem. Nếu chưa có thì tạo thêm. 
*/
static map<int, string> s_ExceptionsDictionary
{
	{
		exceptionKey::WRONG_BASE, 
		"Exception: Wrong-base input! We only work with binary, decimal, hexadecimal number."
	},
	{
		exceptionKey::UNHANDLED_CHARACTER, 
		"Exception: We have found an unhandled character!"
	},
	{
		exceptionKey::INDEX_OUT_OF_BOUND, 
		"Exception: Index out of bound!"
	},
};

//Chuyển từ hệ 10 sang 2. Bit 0 nằm ở đầu string
//[Input] num: 1 số hệ 10 ở dạng chuỗi
//[Output] bits: chuỗi số nhị phân
void numToRBits(const std::string& num, string& bits);

/*
	Lấy bù 2
	[Input]: bits: dãy bit cần xử lý
	[Output]: bits: kết quả sau khi xử lý
*/
void binaryTwoComplements(bitset<128>& bits);

void Convert_Binary_Decimal(string &Dec, const string& Bits);
void Sum_String2(string &s1, const string& s2);

