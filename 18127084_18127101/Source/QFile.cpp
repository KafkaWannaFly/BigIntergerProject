#include "QFile.h"

QFile::QFile()
{
}

void QFile::readInputTXT(string path)
{
	ifstream fin(path);
	if (!fin.is_open())
	{
		throw exception(sExceptionsDictionary[exceptionKey::CANT_OPEN_FILE].c_str());
	}

	string scout;
	while (!fin.eof())
	{
		QRecord record;

		fin >> scout;
		if (fin.peek() == EOF)	//Loop bị dư 1 lần nên fix như này :">
			break;

		record.fromBase = scout;

		fin >> scout;
		if (scout == "2" || scout == "10" || scout == "16")	//Chuyển hệ số
		{
			record.toBase = scout;

			fin >> scout;
			record.values[0] = scout;
		}
		else if (scout == "ror" || scout == "rol" || scout == "~") //Xoay bit hoặc đảo bit
		{
			record.operation = scout;

			fin >> scout;
			record.values[0] = scout;
		}
		else //Làm toán
		{
			record.values[0] = scout;

			fin >> scout;
			record.operation = scout;

			fin >> scout;
			record.values[1] = scout;
		}

		this->m_Records.push_back(record);
	}

	fin.close();
}

void QFile::saveOutputTXT(string path)
{
	ofstream fout(path);
	if (!fout.is_open())
	{
		throw exception(sExceptionsDictionary[exceptionKey::CANT_OPEN_FILE].c_str());
	}

	vector<string> results;
	for (int i = 0; i < this->m_Records.size(); i++)
	{
		string tmp = QFile::processRecord(this->m_Records[i]);
		results.push_back(tmp);
	}

	for (int i = 0; i < results.size(); i++)
	{
		fout << results[i] << endl;
	}

	fout.close();
}

string QFile::processRecord(const QRecord& record)
{
	int base = stoi(record.fromBase);

	if (base != 2 && base != 10 && base != 16)
	{
		throw exception(sExceptionsDictionary[exceptionKey::WRONG_BASE].c_str());
	}

	QInt result;

	if (record.values[1] != "")	//Have 2 values to do
	{
		QInt v1(record.values[0], base);

		if (record.operation == "+")
		{
			QInt v2(record.values[1], base);

			result = v1 + v2;
		}
		else if (record.operation == "-")
		{
			QInt v2(record.values[1], base);

			result = v1 - v2;
		}
		else if (record.operation == "*")
		{
			QInt v2(record.values[1], base);

			result = v1 * v2;
		}
		else if (record.operation == "/")
		{
			QInt v2(record.values[1], base);

			result = v1 / v2;
		}
		else if (record.operation == ">>")
		{
			int num = stoi(record.values[1]);
			//Kiểm tra num < 0 thì không dịch.
			result = v1 >> num;
		}
		else if (record.operation == "<<")
		{
			int num = stoi(record.values[1]);
			result = v1 << num;
		}
		else if (record.operation == "&")
		{
			QInt v2(record.values[1], base);

			result = v1 & v2;
		}
		else if (record.operation == "|")
		{
			QInt v2(record.values[1], base);

			result = v1 | v2;
		}
		else if (record.operation == "^")
		{
			QInt v2(record.values[1], base);

			result = v1 ^ v2;
		}
		else
		{
			throw exception(sExceptionsDictionary[exceptionKey::UNHANDLED_INPUT].c_str());
		}
	}
	else	//Have 1 value to do
	{
		QInt v1(record.values[0], base); //v1("16151561651",16)

		if (record.operation != "")	//Have operation to do
		{
			if (record.operation == "~")	//Flip bit
			{
				result = !v1;
			}
			else if (record.operation == "rol") //Rotate left
			{
				result = v1;
				result.rotateLeft(1);
			}
			else if (record.operation == "ror")	//Rotate right
			{
				result = v1;
				result.rotateRight(1);
			}
			else
			{
				throw exception(sExceptionsDictionary[exceptionKey::UNHANDLED_INPUT].c_str());
			}
		}
		else //SPECIAL CASE: Have no operation. Do translation
		{
			int toBase = stoi(record.toBase);
			if (toBase != 2 && toBase != 10 && toBase != 16)
			{
				throw exception(sExceptionsDictionary[exceptionKey::WRONG_BASE].c_str());
			}

			result = v1;

			if (toBase == 2)
			{
				//cout << result.getBits() << endl;
				return result.getBits();
			}
			else if (toBase == 10)
			{
				//cout << result.getDecimal() << endl;
				return result.getDecimal();
			}
			else
			{
				//cout << result.getHexaDecimal() << endl;
				return result.getHexaDecimal(); 
			}
		}
	}

	if (base == 2)
	{
		//cout << result.getBits() << endl;
		return result.getBits();
	}
	else if (base == 10)
	{
		//cout << result.getDecimal() << endl;
		return result.getDecimal();
	}
	else
	{
		//cout << result.getHexaDecimal() << endl;
		return result.getHexaDecimal();
	}
}

QRecord& QFile::operator[](const unsigned int& index)
{
	if (index > this->m_Records.size())
	{
		throw exception(sExceptionsDictionary[exceptionKey::INDEX_OUT_OF_BOUND].c_str());
	}

	return this->m_Records[index];
}
