// 6.	Viết chương trình cho phép người dùng nhập vào danh sách học sinh (thông tin mỗi học sinh giống bài 5). 
// Tìm và xuất thông tin học sinh có điểm trung bình cao nhất, thấp nhất ra màn hình.

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

//
void InputListST(STUDENT *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
        cin.ignore();
    }
}

void OutputListST(STUDENT *list, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << list[i];
    }
}


//overload > <
bool operator < (STUDENT a, STUDENT b)
{
    return a.dtb < b.dtb;
}

bool operator > (STUDENT a, STUDENT b)
{
    return a.dtb > b.dtb;
}

bool operator == (STUDENT a, STUDENT b)
{
    return a.dtb == b.dtb;
}

// find min max

void FindMinGPA(STUDENT *list, int n)
{
    int min_idx = 0;
    for(int i = 1; i < n; i++)
    {
        if(list[i] < list[min_idx])
        {
            min_idx = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(list[i] == list[min_idx])
        cout << list[i];
    } 
}

void FindMaxGPA(STUDENT *list, int n)
{
    int max_idx = 0;
    for(int i = 1; i < n; i++)
    {
        if(list[i] > list[max_idx])
        {
            max_idx = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(list[i] == list[max_idx])
        cout << list[i];
    } 
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    STUDENT *list = new STUDENT[n];
    // inputST(a);
    // outputST(a);
    InputListST(list, n);
    cout << "Sinh vien co so diem trung binh thap nhat: " << endl;
    FindMinGPA(list, n);
    cout << "Sinh vien co so diem trung binh cao nhat: " << endl;
    FindMaxGPA(list, n);
    system("pause");
    return 0;

}