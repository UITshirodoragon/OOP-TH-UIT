#include <iostream>
#include <cmath>
#define PI 2*acos(0)
// 3.Viết chương trình nhập tọa độ tâm và bán kính của đường tròn. 
// Tính diện tích và chu vi của đường tròn.

using namespace std;

class DuongTron
{
    private:
        double tam_x, tam_y, r, s, c;

    public:
        DuongTron();
        DuongTron(double, double, double );
        double TinhChuVi();
        double TinhDienTich();
        void NhapDT();
        void XuatDT();
        friend void NhapDT(DuongTron &);
        friend void XuatDT(DuongTron);
        friend ostream & operator << (ostream &, DuongTron);
        friend istream & operator >> (istream &, DuongTron &);
        ~DuongTron();
};
double DuongTron::TinhChuVi()
{
    return 2*PI*(this -> r);
}

double DuongTron::TinhDienTich()
{
    return PI*pow(r, 2);
}
DuongTron::DuongTron()
{
    this -> tam_x = 0;
    this -> tam_y = 0;
    this -> r = 0;
    this -> s = 0;
    this -> c = 0;
}

DuongTron::DuongTron(double tam_x, double tma_y, double r )
{
    this -> tam_x = tam_x;
    this -> tam_y = tam_y;
    this -> r = r;
    this -> s = this -> TinhDienTich();
    this -> c = this -> TinhChuVi();

}

DuongTron::~DuongTron()
{

}

void DuongTron::NhapDT()
{
    cin >> this -> tam_x >> this -> tam_y >> this -> r;
    this -> s = this -> TinhDienTich();
    this -> c = this -> TinhChuVi();
}

void NhapDT(DuongTron & a)
{
    cin >> a.tam_x >> a.tam_y >> a.r;
    a.s = a.TinhDienTich();
    a.c = a.TinhChuVi();
}

void DuongTron::XuatDT()
{
    cout << this -> tam_x << " " <<  this -> tam_y << " " << this -> r << " " << this -> s << " " << this -> c << endl;
}

void XuatDT(DuongTron a)
{
    cout << a.tam_x << " " <<  a.tam_y << " " << a.r << " " << a.s << " " << a.c << endl;
}

ostream & operator << (ostream & out, DuongTron a)
{
    out << a.tam_x << " " <<  a.tam_y << " " << a.r << " " << a.s << " " << a.c << endl;
    return out;
}
istream & operator >> (istream & in, DuongTron & a)
{
    in >> a.tam_x >> a.tam_y >> a.r;
    a.s = a.TinhDienTich();
    a.c = a.TinhChuVi();
    return in;
}



int main()
{
    DuongTron a;
    //nhap a;
    cout << "Nhap thong tin duong tron:\n";
    a.NhapDT();
    a.XuatDT();
    cout << "Chu vi: " << a.TinhChuVi() << endl;
    cout << "Dien tich: " << a.TinhDienTich() << endl;
    system("pause");

    return 0;
}