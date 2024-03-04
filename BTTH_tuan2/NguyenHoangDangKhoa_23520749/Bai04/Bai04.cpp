#include <iostream>
#include <cmath>

using namespace std;

class Diem
{
    private:
        double x, y;
    public:
        Diem(/* args */);
        Diem(double, double);
        ~Diem();
        double KhoangCach(Diem );
        friend double KhoangCach(Diem , Diem);
        void NhapDiem();
        void XuatDiem();
        friend void NhapDiem(Diem &);
        friend void XuatDiem(Diem );
        friend ostream & operator << (ostream &, Diem);
        friend istream & operator >> (istream &, Diem &);

};

Diem::Diem(/* args */)
{
    this -> x = 0;
    this -> y = 0;
}

Diem::Diem(double x, double y)
{
    this -> x = x;
    this -> y = y;
}

Diem::~Diem()
{
}

double Diem::KhoangCach(Diem a)
{
    return sqrt(pow(this -> x - a.x, 2) + pow(this -> y - a.y, 2));

}

double KhoangCach(Diem a, Diem b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void Diem::NhapDiem()
{
    cin >> this -> x >> this -> y;
}
void Diem::XuatDiem()
{
    cout << "{" << this -> x << ", " << this -> y << "}" << endl;
}

void NhapDiem(Diem & a)
{
    cin >> a.x >> a.y;
}

void XuatDiem(Diem a)
{
    cout << "{" << a.x << ", " << a.y << "}" << endl;
}

ostream & operator << (ostream & out, Diem a)
{
    out << "{" << a.x << ", " << a.y << "}" << endl;
    return out;
}
istream & operator >> (istream & in, Diem & a)
{
    in >> a.x >> a.y;
    return in;
}


int main()
{
    Diem a, b;
    cout << "Nhap diem a, b:\n";
    a.NhapDiem();
    b.NhapDiem();
    cout << "Toa do diem a: ";
    a.XuatDiem();
    cout << "Toa do diem b: ";
    b.XuatDiem();
    cout << "Khoang cach giua a va b: " << a.KhoangCach(b) << endl;

    system("pause");
    return 0;
}