#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <bitset>
#include <functional>
#include <Windows.h>

#define KEY_UP		72
#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_DOWN	80
#define ENTER		13
#define BACK_SPACE	16
#define DETECT_ARROW_KEY 244
#define ESCAPE		27

static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


// String manipulation
/**
 Chuyển hết các ký tự kiểu std::string sang in thường

 @param[in] s Một chuỗi kiểu string
 @param[out] s Một chuỗi kiểu string có tất cả ký tự in thường.
 @exceptsafe no-throw
*/
void stringLower(std::string& s);

/**
 In hoa một chuỗi kiểu std::string.

 @param[in] s Một chuỗi kiểu string.
 @param[out] s Một chuỗi kiểu string có tất cả ký tự in hoa.
 @exceptsafe no-throw
*/
void stringUpper(std::string& s);


// trim from start (in place)
/**
 Cắt hết các ký trắng ở bên trái một string
 @param[out]: s là chuỗi đã cắt hết các ký tự là khoảng trắng ' '
*/
void ltrim(std::string& s);

// trim from end (in place)
/**
 Cắt hết các ký trắng ở bên phải một string
 @param[out]: s là chuỗi đã cắt hết các ký tự là khoảng trắng ' '
*/
void rtrim(std::string& s);

// trim from both ends (in place)
/**
 Cắt hết các ký trắng ở bên trái và bên phải một string
 @param[out]: s là chuỗi đã cắt hết các ký tự là khoảng trắng ' '
*/
void trim(std::string& s);

/**
Cắt hết ký tự c nằm bên trái một string
@param[out] Một string đã được cắt
*/
std::string ltrim(const std::string& s, const char& c);

/**
Cắt hết ký tự c nằm bên phải một string
@param[out] Một string đã được cắt
*/
std::string rtrim(const std::string& s, const char& c);

/**
Cắt hết ký tự c nằm 2 bên một string
@param[out] Một string đã được cắt
*/
std::string trim(const std::string& s, const char& c);

/**
 Kiểm tra một chuỗi kiểu std::wstring chỉ chứa các ký tự ascii hay không
 @param[in] s là một chuỗi ký tự cần kiểm tra
 @return true nếu đúng với điều kiện trên, false nếu ngược lại
*/
bool isASCII(const std::wstring& s);

/**
 Hàm cắt chuỗi từ dạng string sang const char* để lưu vào file bin
 @param[in] s là chuỗi cần cắt
 @param[in] maxSize là độ dài chuỗi tối đa (kể cả ký tự '\0')
 @details
 khi chuỗi s vượt quá kích thước maxSize - 4 sẽ cắt chuỗi ra độ dài maxSize - 4, gắn "..." vào cuối chuỗi trả về.
 (3 ký tự dùng để gắn ký tự "...", 1 ký tự chừa cho '\0' nên trừ ra 4 ký tự)
 @return chuỗi trả về có kích thước <= maxSize (kể cả ký tự '\0')
*/
const std::string stringTrim_BookBin(std::string s, const std::size_t& maxSize);

std::string getDate_String(time_t m_ImportDate);
// =======================================================================

// Input - output

// Input validation for Yes/No answer
/**
 @brief Xác nhận câu trả lời Yes/No từ input của người dùng.

 @return true nếu người dùng chọn câu "Yes" hợp lệ, false cho trường hợp ngược lại.
 @exceptsafe no-throw
 @details
 Hàm sẽ kiểm tra các câu trả lời Yes/No có sẵn, người dùng có thể
 nhập ký tự "?" để xem các câu trả lời Yes/No hợp lệ.


*/
bool yesNoAns(const std::string& invalidInputAnounce = "\t>>(Yes/No/?): ");
// Input validation for menu commands

/**
 @details Hàm hỏi người dùng nhập số lệnh để thực thi chương trình.\n
 Ví dụ: \n
		1. Lệnh 1 \n
		2. Lệnh 2 \n
		3. ...	  \n
		[lastCommand]. Lệnh cuối. \n
		>> //Người dùng nhập lệnh để thực thi//. \n
 Lặp cho đến khi nào người dùng nhập hợp lệ thì thôi.
 @param[in] lastCommand lệnh cuối cùng trong menu.
 @return lệnh hợp lệ mà người dùng đã nhập.
 @see int askCommand(int firstCommand, int lastCommand),
 @see int askManyCommands(int first_command, int last_command, set<int>& selected_command);
 @exceptsafe no-throw
*/
int askCommand(int lastCommand);
/**
 @brief: Hàm hỏi người dùng nhập số lệnh để thực thi chương trình từ lệnh [firstCommand, lastCommand]
 @note: Cách hoạt động tương tự như askCommand(int lastCommand).
 @param[in] firstCommand, lastCommand là khoảng lệnh hợp lệ từ [firstCommand, lastCommand].
 @return câu lệnh hợp lệ trong đoạn  [firstCommand, lastCommand]
 @see int askCommand(int lastCommand);
 @exceptsafe no-throw
*/
int askCommand(int firstCommand, int lastCommand);

std::size_t askManyCommands(int first_command, int last_command, std::set<int>& selected_command);
/**
 @brief Hỏi người dùng nhập số lệnh để thực thi chương trình từ lệnh [firstCommand, lastCommand]
 @param[in] firstCommand, lastCommand là khoảng lệnh hợp lệ từ [firstCommand, lastCommand].
 @return một vector<int> là các lệnh sắp xếp theo thứ tự tăng dần
*/
std::vector<int> askManyCommands(int first_command, int last_command);

std::pair <std::size_t, std::size_t> askManyTypesOfCommand(const std::vector<std::size_t>& lastCommands,
	const std::vector<std::string>& string_notation);

// Input validation for numbers
/**
 cin >> number;
 Kiểm tra người dùng có nhập đúng kiểu dữ liệu không
 Nếu không đúng kiểu dữ liệu thì lặp cho đến khi nào nhập đúng
 Dùng cho kiểu dữ liệu số (int, char, float, double,..)
 @tparam NumericType kiểu dữ liệu dạng số
 @param[in] inputFormat, invalidInput là những chuỗi kí tự thông báo trên màn hình
 @param[out] outputNumber giá trị số hợp lệ
*/
template <class NumericType> void inputNumber(
	NumericType& outputNumber,
	const std::string& inputFormat = "\t>>",
	const std::string& invalidInput = "\tInvalid input, please try again!") {

	while (true) {
		std::cin >> outputNumber;
		// Kiểm tra xem người dùng có nhập đúng kiểu dữ liệu hay không
		if (std::cin.fail()) {
			std::cin.clear();	// Nếu nhập lỗi thì xóa trạng thái lỗi trong buffer
			std::cin.ignore((std::numeric_limits <std::streamsize > ::max)(), '\n'); // Bỏ đi những kí tự không hợp lệ
			std::cout << invalidInput << std::endl;
			std::cout << "\t>> ";
		}
		else {
			std::cin.ignore((std::numeric_limits <std::streamsize > ::max)(), '\n');
			return;
		}
	}
}

/**
 @brief cin >> number;
 @tparam NumericType kiểu dữ liệu dạng số
 @param[in] inputFormat, invalidInput là những chuỗi kí tự thông báo trên màn hình
 @return giá trị số hợp lệ
 @see template <class NumericType> void inputNumber(NumericType& outputNumber, const std::string & inputFormat, const std::string & invalidInput")
 @details
 Kiểm tra người dùng có nhập đúng kiểu dữ liệu không \n
 Nếu không đúng kiểu dữ liệu thì lặp cho đến khi nào nhập đúng \n
 Dùng cho kiểu dữ liệu số (int, char, float, double,..)
*/
template <class NumericType> NumericType inputNumber(
	const std::string& inputFormat = "\t>>",
	const std::string& invalidInput = "\tInvalid input, please try again!") {
	NumericType n;
	inputNumber(n, inputFormat, invalidInput);
	return n;
}

/**
@details
 Kiểm tra người dùng có nhập đúng kiểu dữ liệu trong khoảng [from, to) \n
 Nếu không đúng kiểu dữ liệu thì lặp cho đến khi nào nhập đúng \n
 Dùng cho kiểu dữ liệu số (int, char, float, double,..).
 @tparam NumericType kiểu dữ liệu dạng số
 @param[in] inputFormat, invalidInput là những chuỗi kí tự thông báo trên màn hình
 @param[in] from, to điều kiện hợp lệ
 @return giá trị số hợp lệ trong khoảng [from, to)
 @see template <class NumericType> void inputNumber(NumericType& outputNumber, const std::string & inputFormat, const std::string & invalidInput")
*/
template<class NumericType> NumericType inputNumberFromRange(
	NumericType from = 0,
	NumericType to = 2,
	const std::string & invalidCondition = "\tInvaid number",
	const std::string & inputFormat = "\t>>",
	const std::string & invalidInput = "\tInvalid input, please try again!") {
	NumericType outputNumber;
	bool condition = false;
	if (from >= to) {
		condition = false;
	}

	if (!condition) {
		inputNumber(outputNumber, inputFormat, invalidInput);
	}
	else {
		do {
			inputNumber(outputNumber, inputFormat, invalidInput);
			if (outputNumber >= from && outputNumber < to) {
				break;
			}
			std::cout << invalidCondition << std::endl;
		} while (true);
	}

	return outputNumber;
}

/**
 Kiểm tra người dùng có nhập đúng kiểu dữ liệu
 Nếu không đúng kiểu dữ liệu thì lặp cho đến khi nào nhập đúng
 Dùng cho kiểu dữ liệu số (int, char, float, double,..)
 @tparam NumericType kiểu dữ liệu dạng số
 @param[in] inputFormat, invalidInput là những chuỗi kí tự thông báo trên màn hình
 @param[in] from, to điều kiện hợp lệ
 @return giá trị số hợp lệ trong khoảng [from, to)
 @see template <class NumericType> void inputNumber(NumericType& outputNumber, const std::string & inputFormat, const std::string & invalidInput")
*/
template<class NumericType> NumericType inputNumberIf(
	NumericType from = 0,
	const std::string & invalidCondition = "\tInvaid number",
	const std::string & inputFormat = "\t>>",
	const std::string & invalidInput = "\tInvalid input, please try again!") {
	NumericType outputNumber;
	bool condition = false;

	if (false) {
		inputNumber(outputNumber, inputFormat, invalidInput);
	}
	else {
		do {
			inputNumber(outputNumber, inputFormat, invalidInput);
			if (outputNumber >= from) {
				break;
			}
			std::cout << invalidCondition << std::endl;
		} while (true);
	}

	return outputNumber;
}

// =======================================================================

//Date time 
/**
 Kiểm tra giá trị dd mm yyyy có phải là giá trị ngày tháng hay không
 @param[in] dd mm yyyy là giá trị cần kiểm tra với dd là ngày, mm là tháng, yyyy năm
 @return true nếu là giá trị hợp lệ, ngược lại là false
*/
bool checkValidDate(int dd, int mm, int yyyy);


struct	date
{
	int	dd = 1;
	int	mm = 1;
	int	yyyy = 1970;
	bool operator == (const date& d1)
	{
		return (dd == d1.dd && mm == d1.mm && yyyy == d1.yyyy);
	}
	bool operator != (const date& d1)
	{
		return !(dd == d1.dd && mm == d1.mm && yyyy == d1.yyyy);
	}
	bool operator > (const date& d1)
	{
		if (yyyy > d1.yyyy)
			return true;
		else if (yyyy < d1.yyyy)
			return false;
		if (mm > d1.mm)
			return true;
		else if (mm < d1.mm)
			return false;
		if (dd > d1.dd)
			return true;
		return false;
	}
	bool operator < (const date& d1)
	{
		if (yyyy < d1.yyyy)
			return true;
		else if (yyyy > d1.yyyy)
			return false;
		if (mm < d1.mm)
			return true;
		else if (mm > d1.mm)
			return false;
		if (dd < d1.dd)
			return true;
		return false;
	}
    bool operator >= (const date& d1) {
        return (*this == d1) || (*this > d1);
    }
    bool operator <= (const date& d1) {
        return (*this == d1) || (*this < d1);
    }
};
struct	hour
{
	int	hh;
	int	mm; //

	bool operator == (const hour& h1)
	{
		return (h1.hh == hh && h1.mm == mm);
	}
	bool operator != (const hour& h1)
	{
		return !(h1.hh == hh && h1.mm == mm);
	}
	bool operator < (const hour& h1)
	{
		if (hh < h1.hh)
			return true;
		if (hh > h1.hh)
			return false;
		if (mm < h1.mm)
			return true;
		return false;
	}
	bool operator > (const hour& h1)
	{
		if (hh > h1.hh)
			return true;
		if (hh < h1.hh)
			return false;
		if (mm > h1.mm)
			return true;
		return false;
	}
	bool operator >= (const hour& h1)
	{
		return operator > (h1) || operator == (h1);
	}
	bool operator <= (const hour& h1)
	{
		return operator < (h1) || operator == (h1);
	}

};
struct	dayhour
{
	int	 dd;
	int	 mm;
	int	 yyyy;
	int	 start_hh;
	int	 start_min;
	int	 end_hh;
	int	 end_min;

};
tm getDate(date d);
void yesNoFillingInterface(const COORD& origin, std::vector<bool>& attendance);
int extractDateFromString(std::istream& fin, date& d, char delim);

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);

// =======================================================================

/**
 Tìm kiếm nhị phân
*/
template <typename Iterator, class Pred1, class Pred2, class Type >
Iterator binarySearch(Iterator begin, Iterator end,
	const Pred1& isEqual, const Pred2& isSmaller, const Type& val) {

	Iterator notFound = end;

	while (begin < end) {

		Iterator mid = begin + (std::distance(begin, end) / 2);
		if (isEqual(val, *mid)) {
			return mid;
		}
		else if (isSmaller(val, *mid)) {
			end = mid;
		}
		else {
			begin = std::next(mid);
		}

	}

	return notFound;
}

// Template Menu
/**
 Template mẫu cho menu
*/
class Menu
{
	/*
	// Cach dung class menu
	void hello() {
		cout << "Hello" << endl;
	}
	void hi() {
		cout << "Hi" << endl;
	}
	using functionPair = std::pair < const std::string &, std::function<void()>>;
	int main() {

		vector<functionPair> subFunc{
			functionPair{"Hello", hello },
			functionPair{ "Hi", hi },
			functionPair{ "Back", nullptr } };
		Menu subMenu(1,
			"This is a sub title",
			"Wrong sub commands\n",
			"Choose now: ", subFunc);

		vector<pair<const char*, function<void()>>> func{
			functionPair{ "Hello", hello },
			functionPair{ "Hi", hi },
			functionPair{ "Sub Menu", subMenu },
			functionPair{ "Back", nullptr } };

		Menu themenu(0,
			"This is a Menu",
			"Choose again\n",
			"Please choose: ", func);
		themenu.operator()();
		return 0;
	}*/
public:
	Menu(int, const char* MenuTitle,
		const char* invalidCommandAnounce,
		const char* choiceDescription,
		std::vector <std::pair<const char*, std::function<void()>>>& commands_
	);//istream& in, ostream& out);
	void operator()() const;

private:
	std::string menuTitle;
	std::string invalidCommandAnounce;
	std::string mainMenuString;
	std::string choiceDescription;
	std::vector <std::pair<const char*, std::function<void()>>> commands;
	size_t menuSize;
	//istream& in;
	//ostream& out;
};