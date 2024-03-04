// 4.	Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số. Tìm và xuất ra màn hình phân số lớn nhất. 
// Sắp xếp dãy phân số tăng dần/giảm dần.
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
        out << a.tu / a.mau;
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
        out << a.tu << "/" << a.mau; 
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
//
void findMaxPS(PHANSO *list, int n)
{
    int max_idx = 0;
    for(int i = 1; i < n; i++)
    {
        if(list[i] > list[max_idx]) max_idx = i;
    }
    
    cout << "Phan so lon nhat: " << list[max_idx] << endl;
}

// sắp xếp
void InputListPS(PHANSO *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
}

void OutputListPS(PHANSO *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
void increasement(PHANSO *list, int n)
{
    int min_idx;
    for(int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(list[j] < list[min_idx])
            {
                min_idx = j;
            }
        }
        //swap
        PHANSO tmp = list[min_idx];
        list[min_idx] = list[i];
        list[i] = tmp;
    }
}

void decreasement(PHANSO *list, int n)
{
    int max_idx;
    for(int i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(list[j] > list[max_idx])
            {
                max_idx = j;
            }
        }
        //swap
        PHANSO tmp = list[max_idx];
        list[max_idx] = list[i];
        list[i] = tmp;
    }
}


int main()
{
    int n;
    cin >> n;

    PHANSO *list = new PHANSO [n];
    InputListPS(list,n);
    findMaxPS(list,n);
    cout << "Tang dan: " ;
    increasement(list,n);
    OutputListPS(list,n);
    cout << "Giam dan: ";
    decreasement(list,n);
    OutputListPS(list,n);
    
    system("pause");
    return 0;
}