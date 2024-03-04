#include <iostream>
#include <string>


#define MAX 100

// 2.Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. 
// Tính điểm trung bình, xếp loại và xuất kết quả.

using namespace std;

class HocSinh
{
    private:
        string hoten;
        string xeploai;
        double toan, van, dtb;
    public:
        HocSinh();
        HocSinh(string, int, int);
        ~HocSinh();
        double TinhDTB();
        string XepLoai();
        void NhapHS();
        void XuatHS();
        friend void NhapHS(HocSinh &);
        friend void XuatHS(HocSinh );
        friend ostream & operator << (ostream &, HocSinh);
        friend istream & operator >> (istream &, HocSinh &);

};

double HocSinh::TinhDTB()
{
    return (this -> van + this -> toan) / 2;

}

string HocSinh::XepLoai()
{
    double dtb = this ->  dtb;
    if(dtb >= 9) return "Xuat Xac";
    else if(dtb >= 8) return "Gioi";
    else if(dtb >= 6) return "Kha";
    else if(dtb >= 5) return "Trung Binh";
    else if(dtb >= 3) return "Yeu";
    else return "Kem";
}


HocSinh::HocSinh()
{
    this -> hoten = "";
    this -> xeploai = "";
    this -> toan = 0;
    this -> van = 0;
    this -> dtb = 0;

}
HocSinh::HocSinh(string hoten, int toan, int van)
{
    this -> hoten = hoten;
    this -> toan = toan;
    this -> van = van;
    this -> dtb = this -> TinhDTB();
    this -> xeploai = this -> XepLoai();

}

HocSinh::~HocSinh()
{

}
void HocSinh::NhapHS()
{
    cout << "Nhap thong tin hoc sinh:\n";
    getline(cin, this -> hoten, '\n');
    cin >> this -> toan >> this -> van;
    this -> dtb = this -> TinhDTB();
    this -> xeploai = this -> XepLoai();
}
void HocSinh::XuatHS()
{
    cout.precision(2); 
    cout << this -> hoten << " " << this -> toan << " " << this -> van << " " << this -> dtb << " " << this -> xeploai << endl;
}

void NhapHS(HocSinh & a)
{
    cout << "Nhap thong tin hoc sinh:\n";
    getline(cin, a.hoten, '\n');
    cin >> a.toan >> a.van;
    a.dtb = a.TinhDTB();
    a.xeploai = a.XepLoai();

}
void XuatHS(HocSinh a)
{
    cout.precision(2); 
    cout << a.hoten << " " << a.toan << " " << a.van << " " << a.dtb << " " << a.xeploai << endl;
}

ostream & operator << (ostream & out, HocSinh a)
{
    out.precision(2); 
    out << a.hoten << " " << a.toan << " " << a.van << " " << a.dtb << " " << a.xeploai << endl;
    return out;
}
istream & operator >> (istream & in, HocSinh & a)
{
    cout << "Nhap thong tin hoc sinh:\n";
    getline(in, a.hoten, '\n');
    in >> a.toan >> a.van;
    a.dtb = a.TinhDTB();
    a.xeploai = a.XepLoai();
    return in;
}



int main()
{
    HocSinh a;
    NhapHS(a); // a.NhapHS();

    XuatHS(a); // a.XuatHS();
    system("pause");
    return 0;
}