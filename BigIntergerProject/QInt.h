#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "QIntUtility.h"

using namespace std;

class QInt
{
private:
	bitset<128> m_bits;
public:
	QInt();
	QInt(const string& _num, const int& base = 10);
	
	string getBits();
	string getHexa();
};
