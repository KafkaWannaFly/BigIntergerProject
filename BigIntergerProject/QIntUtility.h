#pragma once
#include <map>
#include "Misc.h"

using namespace std;

enum exceptionKey
{
	WRONG_BASE,
	UNHANDLED_CHARACTER,
	INDEX_OUT_OF_BOUND,
	CANT_OPEN_FILE,
	DIVIDE_ZERO,
	UNHANDLED_INPUT,
};
/*
	Từ điển exception. Cần throw cái gì thì vô đây xem. Nếu chưa có thì tạo thêm.
*/
static map<int, string> sExceptionsDictionary
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
	{
		exceptionKey::CANT_OPEN_FILE,
		"Exception: Can't open file!"
	},
	{
		exceptionKey::DIVIDE_ZERO,
		"Exception: Divide to zero!"
	},
	{
		exceptionKey::UNHANDLED_INPUT,
		"Exception: Unhandled input values!"
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

void Convert_Binary_Decimal(string& Dec, const string& Bits);
void Sum_String2(string& s1, const string& s2);

/****************************************/
//Tổng hợp lỗi.
//1: Dòng 7 (16 10 A99FDF503E1DD54FCB92B24BE16A52FC)
//2: Dòng 9 (16 10 6A5AEF4C937418D1A4313A1CBB1)
//3: Dòng 17 (16 2 BC170713)
//4: Dòng 21 (16 ~ 6673417108604A17BCF0F7427D6A12F)
//5: Dòng 27 (16 539 ^ 83C0B8536)
//6: Dòng 28 (16 10 563C16A08539)
//7: Dòng 33 (16 16 5AE643EB99E3703149D6A4A8C5C1)
//8: Dòng 34 (16 9C448 - A8E8A44EFC7D8F1A4571F)
//9: (16 10 540115A89BAEC232E0ABB33C9868EE87)
//...........
//10: (16 ~ A5206)
//11: 16 ror 590
//12: 16 97175C77FBE0BB64B36D512D6F2 >> 73
//Đặc biệt:
//13: 10 -6529624872154135214755416638567 >> 67
//............
/*
Tóm lại: lỗi xảy ra với các dòng chuyển đổi qua lại hệ 16
và các phép toán trên hệ này ==>> fix
- Lỗi đặc biệt xảy ra ở hệ 10 với phép dịch trái
(10 -6529624872154135214755416638567 >> 67) ==>> fix
*/
//************************************************************
