# ĐỒ ÁN 1: BIỂU DIỄN VÀ TÍNH TOÁN SỐ NGUYÊN LỚN 

## <u>Thành viên nhóm:</u>

| **Họ tên**                         | **MSSV** |
| ------------------------------ | ---- |
|Đinh Hoàng Dương|18127084|
|Đào Việt Hoàng|18127101|
## <u>Môi trường lập trình</u>

Visual Studio 2019 (v142)

ISO C++ 17 Standard (std:c++17)

## <u>Phân công công việc</u>

| Chức năng                            | Người làm |
| :----------------------------------- | --------- |
| Chuyển số từ hệ 10 sang hệ 2         | Dương     |
| Chuyển số từ hệ 2 sang hệ 10         | Hoàng     |
| Chuyển số từ 16 sang 2 và ngược lại  | Dương     |
| Chuyển số từ 10 sang 16 và ngược lại | Hoàng |
| Operator = + - \* /         | Hoàng (ft. Dương) |
| Toán tử AND, OR, XOR, NOT | Dương |
| Dịch trái dịch phải số học |Dương|
| Xoay trái xoay phải cho 1 bit | Dương |
| Đọc/Xuất file | Dương |

----

## <u>Ý tưởng thiết kế</u>

Nhờ kinh nghiệm tích lũy từ các đồ án môn học trước mà nhóm đã biết được `bitset`. Thay vì sử dụng `char[128]` hay `__int64[2]`, sẽ dễ dàng hơn rất nhiều nếu tận dụng kiểu dữ liệu có sẵn của C++.

Đồ án sẽ được chia làm 2 class chính:

- `QInt`: Lưu trữ và tính toán số nguyên lớn (128 bits)
![image-20191118214237131](../../../Typora/TyporaImageCustomFolder/image-20191118214237131.png)

- `QFile`: Đọc và xuất file

	![image-20191118213534406](../../../Typora/TyporaImageCustomFolder/image-20191118213534406.png)

## <u>Tỷ lệ hoàn thành</u>

## <u>Các nguồn tham khảo</u>

- [Stack Overflow](https://stackoverflow.com/)

- [Cplusplus.com]( http://www.cplusplus.com/ )