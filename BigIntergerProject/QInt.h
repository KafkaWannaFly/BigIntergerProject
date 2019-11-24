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
	QInt(const bitset<128>& bits);
	QInt(const string& bits);
	QInt(const string& _num, const int& base = 10);
	
	//Getter
	string getBits();
	string getHexa();
	string getDecimal();
	size_t getSize();

	//Rotation
	void rotateLeft(const unsigned int& num);
	void rotateRight(const unsigned int& num);

	//Operator
	QInt& operator=(const QInt& qNum);
	QInt operator+(const QInt& qNum);
	QInt operator-(const QInt& qNum);
	QInt operator*(QInt& qNum);
	QInt operator/(const QInt& qNum);

	QInt operator&(const QInt& qNum);
	QInt operator|(const QInt& qNum);
	QInt operator^(const QInt& qNum);
	QInt operator!();

	QInt operator<<(const unsigned int& num);
	QInt operator>>(const unsigned int& num);

	bool operator[](const unsigned int& index);

	bool operator>(const QInt& qNum);
	bool operator<(const QInt& qNum);
	bool operator!=(const QInt& qNum);
	bool operator==(const QInt& qNum);
	bool operator>=(const QInt& qNum);
	bool operator<=(const QInt& qNum);

	friend ostream& operator<<(ostream& out, const QInt& qNum);
	//friend istream& operator>>(istream& in, QInt& qNum);
};
