#pragma once
#include "Misc.h"

using namespace std;

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