#pragma once
#include <iostream>
#include <string>
#include "QIntUtility.h"

using namespace std;

class QInt
{
private:
	bitset<128> m_bits;
public:
	QInt();
	QInt(const string& decimalNum);
	
	string getBits();
};
