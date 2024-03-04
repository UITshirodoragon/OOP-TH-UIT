// Viết chương trình nhập vào một ngày. 
// Tìm ngày kế tiếp và xuất kết quả.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// 1 3 5 7 8 10 12 là 31 ngày
// 2 có 28 hoặc 29 (nhuận ?)
// còn lại là 30


struct DATE
{
    int day, month, year;
};
void inputDate(DATE &t)
{
    cout << "Nhap ngay theo dang dd/mm/year: ";
    vector<int> v_date;
    string date;

    getline(cin, date, '\n');
    for(int i = 0; i < date.length(); i++)
    {
        if(date[i] == ' ')
        {
            date[i] = '/';
        }
    }

    stringstream ss(date);
    string res;
    while(getline(ss, res, '/'))
    {

        v_date.push_back(stoi(res));
    }
    t.day = v_date[0];
    t.month = v_date[1];
    t.year = v_date[2];
} 
    
void outputDate(DATE t)
{
    cout << t.day << "/"<< t.month << "/"<< t.year << "\n";
}

bool checkright(DATE t)
{
    if(t.month > 12 || t.month <= 0) return false;
    else
    {
        switch (t.month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(t.day > 31 || t.day <= 0) return false;
            else return true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(t.day > 30 || t.day <= 0) return false;
            else return true;
            break;
        case 2:
            if(t.day > ((t.year % 400 == 0 || (t.year % 4 == 0 && t.year % 100)) ? 29 : 28) || t.day <= 0) return false;
            else return true;
            break;
        
        default:
            return false;
            break;
        }
    }
}
void thenextday(DATE &t)
{
    t.day += 1;
    if(checkright(t) == 0)
    {
        t.day = 1;
        t.month += 1;
        if(checkright(t) == 0)
        {
            t.month = 1;
            t.year += 1;
        }
    }
}


int main()
{
    DATE t;
    do
    {
        inputDate(t);
    } while (checkright(t) == 031);

    cout << "Ngay ke tiep la: ";
    thenextday(t);
    outputDate(t);
    
    system("pause");
    return 0;
}