// 5.	Viết chương trình cho phép người dùng nhập họ tên, điểm toán, điểm văn của một học sinh. 
// Tính điểm trung bình và xuất kết quả ra màn hình.

#include <iostream>
#include <string>

using namespace std;

struct STUDENT
{
    string hoten;
    double toan, van, dtb;
};
void inputST(STUDENT &a)
{
    getline(cin, a.hoten, '\n');
    cin >> a.toan >> a.van;
    a.dtb = (a.van + a.toan) / 2;
}
void outputST(STUDENT a)
{
    cout << a.hoten;
    cout.precision(2);
    cout << "\t" << a.toan << "\t" << a.van << "\t" << a.dtb << endl;
}

//overload >> <<
istream & operator >> (istream & in, STUDENT & a)
{
    getline(in, a.hoten, '\n');
    in >> a.toan >> a.van;
    a.dtb = (a.van + a.toan) / 2;
    return in;
}

ostream & operator << (ostream & out, STUDENT a)
{
    out << a.hoten;
    out.precision(2);
    out << "\t" << a.toan << "\t" << a.van << "\t" << a.dtb << endl;
    return out;
}

int main()
{
    STUDENT a;
    // inputST(a);
    // outputST(a);
    cin >> a;
    cout << a;
    system("pause");
    return 0;

}