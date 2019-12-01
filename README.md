# ĐỒ ÁN 1: BIỂU DIỄN VÀ TÍNH TOÁN SỐ NGUYÊN LỚN 

## <u>Thành viên nhóm:</u>

| **Họ tên**                         | **MSSV** |
| ------------------------------ | ---- |
|Đinh Hoàng Dương|18127084|
|Đào Việt Hoàng|18127101|
## <u>Môi trường lập trình</u>

Visual Studio 2017 (v141)

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

## <u>Các chức năng</u>

### 0. Tóm tắt

![](../../../Typora/TyporaImageCustomFolder/image-20191127110716668.png)

Vì dữ liệu dưới dạng `bitset` nên constructor sẽ chịu trách nhiệm chuyển đổi mọi số sang hệ 2 và thực hiện các tác vụ trong hệ này (vd: cộng, trừ, nhân, chia,...). Khi nào muốn hiển thị kết quả thì sử dụng các hàm `getBits`, `getDecimal`, `getHexaDecimal` để lấy.

### 1. Chuyển đổi giữa các hệ 2, 10, 16

![image-20191127104919411](../../../Typora/TyporaImageCustomFolder/image-20191127104919411.png)

### 2. Cộng, trừ, nhân, chia

![image-20191127105623412](../../../Typora/TyporaImageCustomFolder/image-20191127105623412.png)

### 3. AND, OR, XOR, NOT, bù 2

![image-20191127105034890](../../../Typora/TyporaImageCustomFolder/image-20191127105034890.png)

### 4. Dịch trái, dịch phải, xoay bit

![image-20191127105232354](../../../Typora/TyporaImageCustomFolder/image-20191127105232354.png)

## <u>Đánh giá</u>

Sau nhiều lần thử và sai, tỷ lệ hoàn thành đồ án là 100%. Tuy còn xuất hiện 1 số ["hiện tượng lạ"](https://github.com/tarzanchemgio/BigIntergerProject/issues/1) không thể giải thích nhưng nếu viết code đúng cách thì đảm bảo an toàn.

## <u>Các nguồn tham khảo</u>

- [Stack Overflow](https://stackoverflow.com/)

- [Cplusplus.com]( http://www.cplusplus.com/ )