
//3.	Viết chương trình cho phép người dùng nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả ra màn hình.

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

// hàm tổng, hiệu, tích, thương

PHANSO tongPS(PHANSO a, PHANSO b)
{
    PHANSO tong;
    int temp = lcm(a.mau, b.mau);
    tong.tu = a.tu *(temp / a.mau) + b.tu *(temp / b.mau);
    tong.mau = temp;
    return tong;
}

PHANSO hieuPS(PHANSO a, PHANSO b)
{
    PHANSO hieu;
    int temp = lcm(a.mau, b.mau);
    hieu.tu = a.tu *(temp / a.mau) - b.tu *(temp / b.mau);
    hieu.mau = temp;
    return hieu;
}

PHANSO tichPS(PHANSO a, PHANSO b)
{
    PHANSO tich;
    tich.tu = a.tu * b.tu;
    tich.mau = b.mau * a.mau;
    return tich;
}

PHANSO thuongPS(PHANSO a, PHANSO b)
{
    PHANSO thuong;
    thuong.tu = a.tu * b.mau;
    thuong.mau = b.tu * a.mau;
    return thuong;
}
// overload các thể loại toán tử
PHANSO operator + (PHANSO a, PHANSO b)
{
    PHANSO tong;
    int temp = lcm(a.mau, b.mau);
    tong.tu = a.tu *(temp / a.mau) + b.tu *(temp / b.mau);
    tong.mau = temp;
    return tong;
}

PHANSO operator - (PHANSO a, PHANSO b)
{
    PHANSO hieu;
    int temp = lcm(a.mau, b.mau);
    hieu.tu = a.tu *(temp / a.mau) - b.tu *(temp / b.mau);
    hieu.mau = temp;
    return hieu;
}

PHANSO operator * (PHANSO a, PHANSO b)
{
    PHANSO tich;
    tich.tu = a.tu * b.tu;
    tich.mau = b.mau * a.mau;
    return tich;
}

PHANSO operator / (PHANSO a, PHANSO b)
{
    PHANSO thuong;
    thuong.tu = a.tu * b.mau;
    thuong.mau = b.tu * a.mau;
    return thuong;
}

PHANSO operator ++ (PHANSO a)
{
    a.tu += a.mau;
    return a;
}

PHANSO operator -- (PHANSO a)
{
    a.tu -= a.mau;
    return a;
}

bool operator += (PHANSO &a, PHANSO b)
{
    a = a + b;
    return 1;
}

bool operator -= (PHANSO &a, PHANSO b)
{
    a = a - b;
    return 1;
}
bool operator /= (PHANSO &a, PHANSO b)
{
    a = a / b;
    return 1;
}
bool operator *= (PHANSO &a, PHANSO b)
{
    a = a * b;
    return 1;
}

bool operator == (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau == (double) b.tu / b.mau);
}

bool operator != (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau != (double) b.tu / b.mau);
}

bool operator >= (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau >= (double) b.tu / b.mau);
}

bool operator <= (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau <= (double) b.tu / b.mau);
}

bool operator > (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau > (double) b.tu / b.mau);
}

bool operator < (PHANSO a, PHANSO b)
{
    return ((double) a.tu / a.mau < (double) b.tu / b.mau);
}



int main()
{
    PHANSO a, b;
    // nhapPS(a);
    // xuatPSrutgon(a);
    cout << "Nhap phan so a, b: ";
    cin >> a >> b;

    cout << "Tong: " << a + b;
    cout << "Hieu: " << a - b;
    cout << "Tich: " << a * b;
    cout << "Thuong: " << a / b;
    
    system("pause");
    return 0;
}