#ifndef  _DATE_H_
#define _DATE_H_

#include<iostream>
using namespace std;

class date{
    public:
      int year_;
      int month_;
      int day_;
    public:
      date();
      date(const int& d,const int& m,const int& y);

      int day()const;
      int month()const;
      int year()const;

    void setDay(const int& day){ date::day_=day;};
    void setMonth(const int& month){ date::month_=month;};
    void setYear(const int& year){ date::year_=year;};
     
      bool valid(void)const;

      date operator++(int);
      
};

bool operator<(const date&,const date&);
ostream& operator<<(ostream& os,const date& d);

#endif