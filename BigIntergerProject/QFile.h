#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "QIntUtility.h"
#include "QInt.h"

using namespace std;

struct QRecord
{
	string fromBase;
	string toBase;
	string operation;
	string values[2];
};
//Dùng để đọc/xuất file các loại
class QFile
{
private:
	vector<QRecord> m_Records;
public:
	QFile();
	void readInputTXT(string path);
	void saveOutputTXT(string path);
	//Processing record to get output
	static string processRecord(const QRecord& record);

	QRecord& operator[](const unsigned int& index);
};

