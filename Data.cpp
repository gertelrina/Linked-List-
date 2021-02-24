#include "Data.hpp"
#include <iostream>
using namespace std;

MyDate::MyDate(){
    day=0;
    month=0;
    year=0;
}

MyDate::MyDate(int d,int m,int y){
    day=d;
    month=m;
    year=y;
    if(!validate()){
        cout << "Error";
        day=month=year=0;
    }
}
MyDate::MyDate(const MyDate& k){
    day=k.day;
    month=k.month;
    year=k.year;
}

void MyDate::AddDays (int d){
    if (d>0){
        while(d--){
            day++;
            if(day>daytab[vis(year)][month]){
                day = 1;
                month++;
                if(month == 13){
                    month = 1;
                    year++;
                }
            }
        }
    }
    else
        while(d++){
            day--;
            if(!day){
                month--;
                if(!month){
                    month = 12;
                    year--;
                    if(!year){
                        year = 1, month = 1, day = 1; return;}}
                day = daytab[vis(year)][month];}}
}

 


void MyDate::AddMonths (int m){ if(m>0)
while(m--)
{month++; if(month==13)
{month=1;year++;}
 

else
 
}

while(m++)
{month--;
if(!month)
{month=12;year--;
if(!year) {year=1;month=1;return;}
 
}
}
int k;
if (day>(k=daytab[vis(year)][month])) day=k;
}
void MyDate::AddYears (int y){
    year+=y;
    if (year<=0){
        year=1;
        month=1;
        day=1;
    }
    int k;
if (day>(k=daytab[vis(year)][month])) day=k;}

int MyDate::daytab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30, 31}};

char*MyDate::MonthName[13]={"null","January","February","March","April","May","June","July","August", "September","October","November","December"};

char*MyDate::DayNames[8]={"null","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int MyDate::validate(){
    return (year>0 && month>0 && month<=12 && day>0 && day<=daytab[vis(year)][month]);
}

MyDate::~MyDate(){}

void MyDate::assign (const MyDate& t){
    day=t.day;
    month=t.month;
    year=t.year;
}

MyDate* MyDate::copy(){
    return new MyDate(*this);
}

int MyDate::equal(const MyDate& t){
    return day==t.day && month==t.month && year==t.year;
}

int MyDate::cmp(const MyDate& t){
    if(year!=t.year)
        return year-t.year;
    else
        if(month!=t.month)
            return month-t.month;
    else return day-t.day;
}

int MyDate::input(){
    cout<<"Day:";
    cin>>day;
    cout<<"Month:";
    cin>>month;
    cout<<"Year:";
    cin>>year;
    if(!validate()){
        cout<<"Error Data"<<endl;
        day=month=year=0;
    }
    return 1;
}

int MyDate::output(){
    char *s=MonthName[month], *ss=this->get_DayOfWeek();
    cout<<day<<" ("<<ss<<") "<<s<<" ("<<month<<") "<<year<<endl;
    return 1;
}

char* MyDate::get_DayOfWeek(){
    long dd = (get_AllDays())%7+1;
    char*s = new char[strlen(DayNames[dd])+1];
    strcpy(s,DayNames[dd]);
    return s;
}

long MyDate::get_AllDays(){
    unsigned long d, m, y;
    d=day;
    y=1;
    m=1;
    while(y<year){
        d+=365+vis(y);
        y++;
    }
    while(m<month){
        d+=daytab[vis(year)][m];
        m++;
    }
return d;
}
