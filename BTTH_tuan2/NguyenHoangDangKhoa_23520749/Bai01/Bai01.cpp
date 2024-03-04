#include <iostream>

// 1. Định nghĩa lớp cPhanSo biểu diễn khái niệm phân số gồm 2 thành phần dữ liệu: tử số, mẫu số và các thao tác:
//  - Nhập phân số
//  - Khởi tạo tử số và mẫu số cho phân số
//  - Xuất phân số
//  - Lấy giá trị phấn số
//  - Tính tổng 2 phân số
// Viết chương trình cho phép người dùng nhập vào 2 phân số, tính tổng 2 phân số và xuất kết quả ra màn hình dưới dạng phân số


using namespace std;


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

class PHANSO
{
    private:
        int tu, mau;

    public:
        PHANSO();
        PHANSO(int ,int );
        ~PHANSO();
        void inputPS();
        void outputPS();
        friend void inputPS(PHANSO &);
        friend void outputPS(PHANSO);
        double giatri();
        friend istream & operator >> (istream &, PHANSO &);
        friend ostream & operator << (ostream &, PHANSO);
        PHANSO tongPS(PHANSO);
        PHANSO hieuPS(PHANSO);
        PHANSO tichPS(PHANSO);
        PHANSO thuongPS(PHANSO);
        friend PHANSO tongPS(PHANSO, PHANSO);
        friend PHANSO hieuPS(PHANSO, PHANSO);
        friend PHANSO tichPS(PHANSO, PHANSO);
        friend PHANSO thuongPS(PHANSO, PHANSO);
        friend PHANSO operator + (PHANSO, PHANSO);
        friend PHANSO operator - (PHANSO, PHANSO);
        friend PHANSO operator * (PHANSO, PHANSO);
        friend PHANSO operator / (PHANSO, PHANSO);

};
PHANSO::PHANSO(int tu, int mau)
{
    this -> tu = tu;
    this -> mau = mau;
}
PHANSO::PHANSO()
{
    this -> tu = 0;
    this -> mau = 1;
}
PHANSO::~PHANSO()
{

}

void PHANSO::inputPS()
{
    cin >> this -> tu >> this -> mau;
}

void PHANSO::outputPS()
{
    if(tu == 0)
    {
        cout << 0 << endl;
    }
    else if(tu % mau == 0)
    {
        cout << tu / mau << endl;
    }
    else
    {   
        if(mau < 0)
        {
            tu *= -1;
            mau *= -1;
        }
        int temp = gcd(tu, mau);
        tu /= temp;
        mau /= temp;
        cout << tu << "/" << mau << endl; 
    }
}

void inputPS(PHANSO & a)
{
    cin >> a.tu >> a.mau;
}
void outputPS(PHANSO a)
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

double PHANSO::giatri()
{
    return (double) this-> tu / this -> mau;
}

istream & operator >> (istream & in, PHANSO & a)
{
    in >> a.tu >> a.mau;
    return in;
}
ostream & operator << (ostream & out, PHANSO a)
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
PHANSO PHANSO::tongPS(PHANSO b)
{
    PHANSO tong;
    int temp = lcm(this->mau, b.mau);
    tong.tu = this->tu *(temp / this->mau) + b.tu *(temp / b.mau);
    tong.mau = temp;
    return tong;
}
PHANSO PHANSO::hieuPS(PHANSO b)
{
    PHANSO hieu;
    int temp = lcm(this->mau, b.mau);
    hieu.tu = this->tu *(temp / this->mau) - b.tu *(temp / b.mau);
    hieu.mau = temp;
    return hieu;
}
PHANSO PHANSO::tichPS(PHANSO b)
{
    PHANSO tich;
    tich.tu = this->tu * b.tu;
    tich.mau = b.mau * this->mau;
    return tich;
}
PHANSO PHANSO::thuongPS(PHANSO b)
{
    PHANSO thuong;
    thuong.tu = this->tu * b.mau;
    thuong.mau = b.tu * this->mau;
    return thuong;
}
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




int main()
{
    PHANSO a, b(2,3); // khoi tao phan so 
    cout << "Nhap phan so a: ";
    // cin >> a; inputPS(a);
    // nhap phan so
    a.inputPS();
    //xuat phan so
    a.outputPS();
    outputPS(b);
    // lay gia tri phan so
    cout << "Gia tri cua a: " << a.giatri() << endl;
    cout << "Gia tri cua b: " << b.giatri() << endl;
    //tinh tong 2 phan so
    cout << "Tong: " << tongPS(a,b) << endl;


    system("pause");
    return 0;
}