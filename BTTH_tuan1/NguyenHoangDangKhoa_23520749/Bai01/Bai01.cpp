
//1.	Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số và xuất kết quả ra màn hình.

#include <iostream>
#include <cmath>

using namespace std;

struct PHANSO
{
    int tu, mau;
};

// bổ trợ
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lcm(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return (a * b) / gcd(a, b);

}

void nhapPS(PHANSO &a)
{
    cin >> a.tu >> a.mau;
}

void xuatPSrutgon(PHANSO a)
{
    if(a.tu == 0)
    {
        cout << 0 << endl;
    }
    else if(a.tu % a.mau == 0)
    {
        cout << a.tu / a.mau << endl;
    }
    else
    {   
        if(a.mau < 0)
        {
            a.tu *= -1;
            a.mau *= -1;
        }
        int temp = gcd(a.tu, a.mau);
        a.tu /= temp;
        a.mau /= temp;
        cout << a.tu << "/" << a.mau << endl; 
    }
}

// overload toan tu << >>

std::ostream & operator << (std::ostream & out, PHANSO a)
{
    if(a.tu == 0)
    {
        out << 0 << endl;
    }
    else if(a.tu % a.mau == 0)
    {
        out << a.tu / a.mau << endl;
    }
    else
    {   
        if(a.mau < 0)
        {
            a.tu *= -1;
            a.mau *= -1;
        }
        int temp = gcd(a.tu, a.mau);
        a.tu /= temp;
        a.mau /= temp;
        out << a.tu << "/" << a.mau << endl; 
    }
    return out;
}

std::istream & operator >> (std::istream & in, PHANSO & a)
{
    in >> a.tu >> a.mau;
    return in;
}

int main()
{
    PHANSO a;
    // nhapPS(a);
    // xuatPSrutgon(a);
    cin >> a;
    cout << a;
    system("pause");
    return 0;
}