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
	QInt(const QInt& bits);
	QInt(const bitset<128>& bits);
	QInt(const bool& valueOfAllBits);
	QInt(const string& bits);
	QInt(const string& _num, const int& base = 10);

	//Thực hiện phép bù 2
	void doTwoComplements();

	//Getter
	string getBits();
	string getHexaDecimal();
	string getDecimal();
	size_t getSize();
	//Trả về giá trị bù 2 của nó nhưng không thay đổi bản thân object
	QInt getTwoComplements();

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

	bool operator[](const size_t& index);

	bool operator>(const QInt& qNum);
	bool operator<(const QInt& qNum);
	bool operator!=(const QInt& qNum);
	bool operator==(const QInt& qNum);
	bool operator>=(const QInt& qNum);
	bool operator<=(const QInt& qNum);

	friend ostream& operator<<(ostream& out, const QInt& qNum);
	//friend istream& operator>>(istream& in, QInt& qNum);
};
