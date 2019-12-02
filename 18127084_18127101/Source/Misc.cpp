#include "Misc.h"
using namespace std;

void stringLower(string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		char character = tolower(s[i]);
		s[i] = character;
	}
}
void stringUpper(string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		char character = toupper(s[i]);
		s[i] = character;
	}
}
void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
		}));
}
void rtrim(std::string& s) {
	s.erase(
		std::find_if(s.rbegin(), s.rend(), [](int ch) {return !std::isspace(ch); }
	).base(), s.end());
}
void trim(std::string& s) {
	ltrim(s);
	rtrim(s);
}

std::string ltrim(const std::string& s, const char& c)
{
	int i = 0;
	for (; i < s.length(); i++)
	{
		if (s[i] != c)
			break;
	}

	std::string result = s.substr(i, s.length() - i);
	return result;
}

std::string rtrim(const std::string& s, const char& c)
{
	int i = s.length() - 1;
	for (; i >= 0; i--)
	{
		if (s[i] != c)
			break;
	}

	return s.substr(0, i);
}

std::string trim(const std::string& s, const char& c)
{
	std::string result = s;
	result = ltrim(result, c);
	result = rtrim(result, c);
	return result;
}

std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}
std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}
std::string trim_copy(std::string s) {
	trim(s);
	return s;
}
bool isASCII(const wstring& s) {

	for (size_t i = 0; i < s.length(); i++) {
		// Nếu giá trong chuỗi s có một ký tự 
		// vượt quá giá trị SCHAR_MAX (a.k.a 127)
		// nghĩa là kí tự đó không phải là ký tự char
		// vì một ký tự char không vượt quá SCHAR_MAX
		if (s[i] > SCHAR_MAX) {
			return false;
		}
	}
	return true;
};
const string stringTrim_BookBin(std::string s, const std::size_t& maxSize)
{
	// Đây là lần sửa code thứ n, còn bug nữa chắc bỏ nhà đi shikoku quá 
	string temp;
	if (s.empty()) {
		return "";
	}

	if (!(s.front() == '\"' && s.back() == '\"')) {

		// Chuỗi có dấu ',' mà đầu và cuối không đặt trong "" xuất ra CSV là hỏng liền
		if (any_of(s.begin(), s.end(),
			[](const char& c)->bool {return c == ','; })) {
			s.insert(0, "\"");
			s += '\"';
		}

	}

	// Độ dài chuỗi thật, khi vượt quá độ dài này thì thêm "...\0" vào cuối chuỗi
	long long int actualSize = long long int(maxSize) - 4LL;

	bool isQuotationMark = false;
	if (s.length() > 0 && s[0] == '\"') {
		// Khi chuỗi bắt đầu bằng dấu ' " ' thì chừa thêm một ô để chứa dấu "
		// Nên độ dài chuỗi thật giảm đi 1
		isQuotationMark = true;
		actualSize = long long int(maxSize) - 5LL;
	}

	if (actualSize > 0 && s.length() > size_t(actualSize)) {

		// Cắt chuỗi ra, thêm vào cuối chuỗi "..."
		temp += s.substr(0, actualSize);
		temp += "...";
		if (isQuotationMark) {
			// Thêm dấu " vào cuối chuỗi
			temp += '\"';
		}
	}
	else {
		temp = s;
	}
	return temp;
}

std::string getDate_String(time_t m_ImportDate)
{
	// @ref http://www.cplusplus.com/reference/ctime/strftime/?kw=strftime
	if (m_ImportDate < 0) {
		return "";
	}
	struct tm time;
	char buffer[80];
	localtime_s(&time, &m_ImportDate);

	strftime(buffer, 80, "%F", &time);
	return string(buffer);
}

bool yesNoAns(const std::string& invalidInputAnounce)
{
	// Hàm trả về false nếu nhập vào "no", "n", "khong", "ko", "k", "non", "0", "o", "null"
	// Còn lại trả về true
	string ans;

	getline(cin, ans, '\n');
	//cin.ignore((std::numeric_limits<streamsize>::max)());
	cin.clear();
	stringLower(ans);
	vector<string> yes = { "yes", "ys", "y", "co", "c", "oui", "1", "vang", "tiep tuc", "tiep", "continue", "i love you",
					"si", "hello", "haii", "ok", "co minh xinh dep", "co tu dep xiu", "tuonglaituoisang" };
	vector<string> no = { "no", "n", "khong", "ko", "k", "non", "0", "o", "null", "nope", "dep",
				   "oh no", "shut up", "iie", "del", "mr.thanh dep trai", "ktlt so easy", "1+1=3", "wt" };
	int i = 0,
		len = 19;
	while (true)
	{
		if (ans.empty()) {
			// Không trả lời tự hiểu là đồng ý :)))
			return true;
		}
		if (ans.find("?") != string::npos) {
			cout << "\tValid Commands for Yes and No: " << endl;
			cout << "\t";
			cout << setfill('*') << setw(46) << "*" << setfill(' ') << endl;
			cout << "\t";
			cout << "|  " << setw(19) << left << "YES"
				<< "|  " << setw(20) << left << "NO"
				<< "|" << endl;
			cout << "\t";
			cout << "|" << setfill('-') << setw(44) << "-"
				<< "|" << setfill(' ') << endl;
			for (int i = 0; i < len; i++)
			{
				cout << "\t";
				cout << "|  " << setw(19) << left << yes[i] << "|  " << setw(20) << left << no[i] << "|" << endl;
			}
			cout << "\t";
			cout << setfill('*') << setw(46) << "*" << setfill(' ') << endl;
		}
		else {
			if (std::find(no.begin(), no.end(), ans) != no.end()) {
				return false;
			}
			if (std::find(yes.begin(), yes.end(), ans) != yes.end()) {
				return true;
			}

		}
		cout << invalidInputAnounce;
		getline(cin, ans, '\n');
		stringLower(ans);
		cin.clear();

	}
}

bool checkValidDate(int dd, int mm, int yyyy)
{
	//Kiểm tra tính hợp lệ của định dạng struct date
	if (dd > 31 || dd <= 0)
		return false;
	if (mm > 12 || mm <= 0)
		return false;
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 16:
	case 10:
	case 12:
	{
		if (dd < 1 || dd > 31)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	}
	case 4:
	case 6:

	case 9:
	case 11:
	{

		if (dd < 1 || dd > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
		break;
	}
	case 2:
	{
		bool isLeap = false;
		if (yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0)
			isLeap = true;
		if (isLeap)
		{
			if (dd > 29)
				return false;
		}
		else
		{
			if (dd > 28)
				return false;
		}
	}
	}
	return true;
}
bool checkValidDate(date d)
{
	return checkValidDate(d.dd, d.mm, d.yyyy);
}

int askCommand(int lastCommand)
{
	return askCommand(1, lastCommand);
}
int askCommand(int firstCommand, int lastCommand)
{
	int command = 0;
	while (true)
	{
		cout << "\t>> ";
		command = inputNumber<int>();
		if (command >= firstCommand && command <= lastCommand)
		{
			return command;
		}
		cout << "    !Invalid command." << endl;
	}
}
size_t askManyCommands(int first_command, int last_command, set<int>& selected_command)
{
	int n = 0;
	do
	{
		int command;
		cout << "\t>> ";
		string s;
		stringstream selected;
		getline(cin, s, '\n');
		selected << s;
		while (!selected.eof())
		{
			string temp;
			selected >> temp;
			if (stringstream(temp) >> command)
			{
				if (command >= first_command && command <= last_command) {
					selected_command.insert(command);
				}
			}
		}

		if (selected_command.size() == 0)
		{
			cout << "\tYou did not choose any valid command, please choose again!!" << endl;
			continue;
		}
		cout << "\tYou selected command(s): ";
		for (set<int>::iterator it = selected_command.begin(); it != selected_command.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	} while (true);

	return selected_command.size();
}

vector<int> askManyCommands(int first_command, int last_command)
{
	set<int> commands;
	vector<int> selected_command;
	askManyCommands(first_command, last_command, commands);
	std::copy(commands.begin(), commands.end(), std::back_inserter(selected_command));
	return selected_command;
}

std::pair<size_t, size_t> askManyTypesOfCommand(const std::vector<size_t>& lastCommands, const vector<std::string>& string_notation)
{
	if (lastCommands.size() != string_notation.size()) {
		throw runtime_error("askManyTypesOfCommand function Exception: The size of three parameters must be equals");
	}

	size_t command_no;
	string command_str;

	bool blankNotation = false;
	size_t blankNotationIndex = 0;
	auto temp_it = std::find(string_notation.begin(), string_notation.end(), "");
	if (temp_it != string_notation.end()) {

		blankNotation = true;
		blankNotationIndex = std::distance(string_notation.begin(), temp_it);
	}

	while (true)
	{
		cout << "\t>> ";
		getline(cin, command_str, '\n');

		if (!command_str.empty())
		{
			if (!(blankNotation &&
				std::all_of(command_str.begin(), command_str.end(), std::isdigit))) {

				auto notation_it = std::find_if(string_notation.begin(), string_notation.end(),
					[&command_str](string s) {return (!s.empty() && (command_str.find(s) != string::npos)); });

				if (notation_it != string_notation.end()) {

					size_t index = std::distance(string_notation.begin(), notation_it);

					string sub = command_str.substr(notation_it->length());
					if (std::all_of(sub.begin(), sub.end(), std::isdigit)) {

						command_no = stoi(sub);
						if (command_no >= 1 && command_no <= lastCommands[index]) {

							return make_pair(command_no, index);
						}
					}
				}

			}
			else {
				command_no = stoi(command_str);
				if (command_no >= 1 && command_no <= lastCommands[blankNotationIndex]) {

					return make_pair(command_no, blankNotationIndex);
				}
			}
		}

		cout << "    !Invalid command." << endl;
	}
}

void Menu::operator()() const
{
	bool invalidCommand = true;
	bool firstshowMenu = false;
	//bool confirm = false;
	string choice_str;
	int choice = 0;
	while (true)
	{
		try {
			if (!firstshowMenu || !invalidCommand) {
				firstshowMenu = true;
				cout << mainMenuString
					<< choiceDescription;
			}
			getline(cin, choice_str, '\n');
			choice = stoi(choice_str) - 1;

			if (choice >= 0 && choice <= menuSize - 1) {
				invalidCommand = false;
				if (this->commands[choice].second == nullptr) {
					break;
				}
				this->commands[choice].second();
			}
			else {
				cout << invalidCommandAnounce
					<< choiceDescription;
			}
		}
		catch (const std::invalid_argument&) {
			cout << invalidCommandAnounce
				<< choiceDescription;
		}
		catch (const std::exception&) {
			cout << invalidCommandAnounce
				<< choiceDescription;
		}
	}
}
Menu::Menu(int NumberOfTabs, const char* MenuTitle,
	const char* invalidCommandAnounce,
	const char* choiceDescription,
	vector <pair<const char*, function<void()>>>& commands)
	//istream& in = std::cin, ostream& out = std::cout) : in{ in }, out{ out }
{
	this->menuTitle = MenuTitle;
	this->commands = commands;
	this->menuSize = commands.size();
	stringstream menu;
	string tabs;

	for (int i = 0; i < NumberOfTabs; i++) {
		tabs += "\t";
	}

	menu << tabs << MenuTitle << endl;
	for (int i = 0; i < commands.size(); i++)
	{
		menu << tabs << "\t" << i + 1 << ". " << commands[i].first << endl;
	}
	mainMenuString = menu.str();

	this->invalidCommandAnounce = tabs + "\t" + invalidCommandAnounce + "\n";
	this->choiceDescription = tabs + "\t" + choiceDescription;
}

bool timeInputChecking(hour start, hour end)
{
	if ((start.hh * 60 + start.mm) < (end.hh * 60 + end.mm))
	{
		if (start.hh < 24 && start.hh >= 0 && end.hh < 24 && end.hh >= 0)
		{
			if (start.mm < 60 && start.mm >= 0 && end.mm < 60 && end.mm >= 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool hourRangeOverlap(const dayhour& d1, const dayhour& d2)
{
	// Kiểm tra khung giờ của hai biến dayhour có chồng-chéo nhau hay không
	// Giả sử hay ngày có dd mm yyyy giống nhau

	// Nếu 2 khoảng giờ bị chồng chéo
	/*	A = (StartA, EndA)
		B = (StartB, EndB)

									(----DateRange A------)	 (True if StartA >= EndB)
		(--- ate Range B-----)


		(----DateRange A-----)                             (True if EndA <= StartB)
									(---Date Range B----)

		Overlap if: (StartA < EndB)  and  (EndA > StartB)
	*/

	hour startA = { d1.start_hh, d1.start_min },
		startB = { d2.start_hh, d2.start_min },
		endA = { d1.end_hh, d1.end_min },
		endB = { d2.end_hh, d2.end_min };
	if (startA < endB && endA > startB)
		return true;
	return false;
}

size_t timeSince1970(int dd, int mm, int yy) //Tính số giây từ 0:00AM 1st, Jan, 1970
{
	size_t ans = 0;

	for (int i = 1; i <= 12; i++)
	{
		if (i >= mm)
			break;
		switch (mm)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 16:
		case 10:
		case 12:
		{
			ans += 31;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			ans += 30;
			break;
		}
		case 2:
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				ans += 29;
			else
				ans += 28;
			break;
		}
		default:
			break;
		}
	}
	ans += dd;

	for (int i = yy - 1; i >= 1970; i--)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			ans += 366;
		}
		else
		{
			ans += 365;
		}
	}

	return (ans + 1) * 24 * 60 * 60;
}
//void courseDateGenerator(course& c) //Hàm tạo ngày tháng đi học cho course_date
//{
//	// time_t : For historical reasons, it is generally implemented as an integral value
//	// representing the number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC (i.e., a unix timestamp).
//	// Although libraries may implement this type using alternative time representations.
//	time_t start = timeSince1970(c.start_date.dd, c.start_date.mm, c.start_date.yyyy); //time_t là kiểu dữ liệu ghi số giây. Có sẵn trong <time.h>
//	time_t end = timeSince1970(c.end_date.dd, c.end_date.mm, c.end_date.yyyy) - 86400; //end thừa một ngày
//
//	tm dateInfo; //tm là kiểu struct lưu trữ các giá trị thời gian (ngày,tháng,năm,...). Có sẵn trong <time.h>
//	dayhour date;
//	int n = 0;
//	c.n_course_date = 0;
//	while (start <= end)
//	{
//		localtime_s(&dateInfo, &start);		 //chuyển đổi từ time_t sang tm
//		if (c.dow[dateInfo.tm_wday] == true) //Kiểm tra xem có tiết hay không
//		{
//			date.dd = dateInfo.tm_mday; //Sử dụng giá trị ngày tháng trong KDL tm để gán giá trị cho course_date
//			date.mm = dateInfo.tm_mon + 1;
//			date.yyyy = dateInfo.tm_year + 1900;
//			date.start_hh = c.start_hour[dateInfo.tm_wday].hh;
//			date.start_min = c.start_hour[dateInfo.tm_wday].mm;
//			date.end_hh = c.end_hour[dateInfo.tm_wday].hh;
//			date.end_min = c.end_hour[dateInfo.tm_wday].mm;
//			push_back(c.course_date, c.n_course_date, date);
//		}
//		start = start + 86400; //86400s = 1 ngày. Sang ngày tiếp theo để tiếp tục kiểm tra và lưu dữ liệu
//	}
//}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi)) {
		return cbsi.dwCursorPosition;
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}
tm getDate(date d)
{
	time_t time_t = time(0);
	tm return_tm;
	localtime_s(&return_tm, &time_t);

	return_tm.tm_hour = 1;
	return_tm.tm_min = 1;
	return_tm.tm_sec = 1;
	return_tm.tm_mday = d.dd;
	return_tm.tm_mon = d.mm - 1;
	return_tm.tm_year = d.yyyy - 1900;

	return return_tm;
}
void yesNoFillingInterface(const COORD& origin, vector<bool>& attendance) {
	COORD cur_pos = origin;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int get_character, detect_key_arrrow;
	SetConsoleCursorPosition(hStdout, cur_pos);
	while (true)
	{
		get_character = _getch();
		if (get_character && get_character != 224) {
			int index = cur_pos.Y - origin.Y;
			if ((get_character == 'Y' || get_character == 'y' ||
				get_character == 'N' || get_character == 'n')
				&& (index) < attendance.size())
			{
				if (get_character == 'Y' || get_character == 'y') {
					cout << "\bY";
					//wcout << check;
					//WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), s__, slen, &slen, NULL);
					//wcout << check;
					attendance[index] = true;
				}
				else {
					cout << "\bN";
					attendance[index] = false;
				}
				if ((index) < attendance.size())
				{
					cur_pos.Y++;
					SetConsoleCursorPosition(hStdout, cur_pos);
				}
			}
			if (get_character == BACK_SPACE) {
				cout << "\b ";
				attendance[index] = false;
			}
			if (get_character == ENTER) {
				if (index == attendance.size())
				{
					cout << endl;
					break;
				}
			}
		}
		else
		{
			switch (detect_key_arrrow = _getch()) {
			case KEY_UP: {
				if ((cur_pos.Y - origin.Y) > 0) {
					cur_pos.Y--;
					SetConsoleCursorPosition(hStdout, cur_pos);
				}
				break;
			}
			case KEY_DOWN: {
				if ((cur_pos.Y - origin.Y) <= short(attendance.size())) {
					cur_pos.Y++;
					SetConsoleCursorPosition(hStdout, cur_pos);
				}
				break;
			}
			case KEY_LEFT:
			case KEY_RIGHT:
				break;
			default:
				break;
			}
		}
	}
}
string intToMonth(int n)
{
	switch (n)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 16:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "";
	}
}
int monthToString(string s)
{
	string month[] = { "january", "febuary", "march", "april", "may", "june",
					  "july", "august", "september", "october", "november", "december" };
	stringLower(s);
	for (int i = 0; i < 12; i++)
	{
		if (month[i] == s)
			return i + 1;
	}
	return 0;
}
int checkDateStrDDMMYYYY(date& d, char delim)
{
	// Hàm cũ, cẩn thận khi dùng !!!
	// return 1	-> Không lỗi
	// return -1 -> Không đọc được ngày
	// return 0 -> Ngày không hợp lệ

	char temp[1000];
	// Để chạy được định dạng YYYY/MM/DD hoặc YYYY-MM-DD
	char* token = NULL, * next_token = NULL;
	cin.getline(temp, 12, delim);
	for (int i = 0; i < strlen(temp); i++)
	{
		if ((temp[i] > '9' || temp[i] < '0') && temp[i] != '/' && temp[i] != '-' && temp[i] != ' ')
			return -1;
	}
	token = strtok_s(temp, "/- ", &next_token);
	d.dd = atoi(temp);
	token = strtok_s(NULL, "/- ", &next_token);
	if (token == NULL)
		return -1;
	d.mm = atoi(token);
	token = strtok_s(NULL, "/- ", &next_token);
	d.yyyy = atoi(token);
	if (!checkValidDate(d))
		return 0;
	return 1;

} //
int extractDateFromString(istream& fin, date& d, char delim)
{
	// return 1	-> Không lỗi
	// return -1 -> Không đọc được ngày
	// return 0 -> Ngày không hợp lệ

	char temp[1000];
	// Để chạy được định dạng YYYY/MM/DD hoặc YYYY-MM-DD
	char* token = NULL, * next_token = NULL;
	fin.getline(temp, 12, delim);
	for (int i = 0; i < strlen(temp); i++)
	{
		if ((temp[i] > '9' || temp[i] < '0') && temp[i] != '/' && temp[i] != '-')
			return -1;
	}
	try
	{
		token = strtok_s(temp, "/- ", &next_token);
		d.yyyy = atoi(temp);
		token = strtok_s(NULL, "/- ", &next_token);
		if (token == NULL)
			return -1;
		d.mm = atoi(token);
		token = strtok_s(NULL, "/- ", &next_token);
		d.dd = atoi(token);
	}
	catch (const std::invalid_argument&)
	{
		return -1;
	}
	catch (const std::out_of_range&)
	{
		return -1;
	}

	if (!checkValidDate(d))
		return 0;
	return 1;

} //
int weekToInt(char* token)
{
	char temp[10];
	strcpy_s(temp, token);
	_strlwr_s(temp, 10);
	char dow1[7][10] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	char dow2[7][2] = { "1", "2", "3", "4", "5", "6", "7" };
	char dow3[][7] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat", "sun" };
	for (int i = 0; i < 7; i++)
	{
		if (strcmp(temp, dow1[i]) == 0 || strcmp(temp, dow2[i]) == 0)
			return i;
	}
	return -1;
} //
bool readDOWInSemesterTXT(bool dow[7], const char* str)
{
	char temp[50];
	strcpy_s(temp, str);
	char* token = NULL, * next_token = NULL;
	token = strtok_s(temp, " ;-&", &next_token);
	int weekday;
	while (token)
	{
		weekday = weekToInt(token);
		if (weekday >= 0)
		{
			dow[weekday] = true;
		}
		else
			return false;
		token = strtok_s(NULL, " ;-&", &next_token);
	}
	return true;
} //
hour strToHour(char* token)
{
	char temp[1000];
	strcpy_s(temp, 100, token);
	hour h;
	char* temp_token = NULL, * next_token = NULL;
	temp_token = strtok_s(temp, ": ,;\t-", &next_token);
	if (token == NULL)
	{
		return h = { 0, 0 };
	}
	else
		h.hh = atoi(temp_token);

	if (next_token == NULL)
	{
		return h = { 0, 0 };
	}
	else
		h.mm = atoi(next_token);
	return h;
} //
bool readHourInSemesterCSV(bool dow[7], hour hours[7], const char* str)
{
	// !!!Hàm này đã cũ, cẩn thận khi sử dụng
	char temp[1000];
	strcpy_s(temp, 1000, str);
	char* token = NULL, * next_token = NULL;
	token = strtok_s(temp, " ;-&", &next_token);
	int n = 0;
	int temp_hour[7] = { 0 }, // Lưu các vị trí có ngày trong mảng dow
		n_temp = 0;
	while (token)
	{
		for (int i = n; i < 7; i++)
		{
			if (dow[i] == true)
			{
				n = i;
				temp_hour[n_temp++] = i;
				break;
			}
		}
		hours[n++] = strToHour(token);
		token = strtok_s(NULL, " ;-&", &next_token);
	}
	if (n == 1 && n != n_temp)
	{
		for (int i = 1; i < n_temp; i++)
		{
			hours[temp_hour[n_temp]] = hours[temp_hour[0]];
		}
	}
	return true;
} //

const string passwordInput() {
	int get_pass_character;
	int detect_arrow_key = 0;
	string pass;

	while (true)
	{
		get_pass_character = _getch();
		if (get_pass_character && get_pass_character != DETECT_ARROW_KEY)
		{
			if (get_pass_character != '\b' && get_pass_character != '\r') {

				cout << '*';
				cout << char(get_pass_character);
				pass += get_pass_character;
			}
			if (get_pass_character == BACK_SPACE && pass.length() >= 0) {

				if (pass.length() > 0) {
					pass.pop_back();
					cout << "\b \b";
				}
				if (pass.length() == 0) {
					cout << " \b";
				}
			}
			if (get_pass_character == 13) {
				break;
			}
		}
		else {
			detect_arrow_key = _getch();
		}
	}
	return pass;
}
