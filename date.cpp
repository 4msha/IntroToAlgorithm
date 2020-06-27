#include"date.h"

date::date(const int& d,const int& m,const int& y)
:year_(y),month_(m),day_(d){
   cout<<"Date Created\n";
};

int date::day()const{return day_;};
int date::month() const{ return month_;};
int date::year() const{return year_;};

void date::setDay(const int&day){date::day_=day;};
void date::setMonth(const int&month){date::month_=month;};
void date::setYear(const int&year){date::year_=year;}

bool date::valid()const{
    if(year_<0) return false;
    if(month_>12 || month_<1) return false;
    if(day_>31 || day_<1) return false;
    if(day_==31 && month_==12 || month_==4 || month_==6 || month_==9 || month_==11)
      return false;
    if(day_==30 && month_==2) return false;

    if(year_<2000){
        if((day_==29 && month_==2) && !((year_-1900)%4==0)) return false;
    }  

    if(year_>200){
         if((day_==29 && month_==2) && !((year_-2000)%4==0)) return false;
    }

    return true;
}
inline date next_date(const date& d){
    date nDate=date((d.day()+1),d.month(),d.year()); 
     
     nDate.setDay(d.day()+1);
    if(nDate.valid()) return nDate;
     nDate.setMonth(d.month()+1);
    if(nDate.valid()) return nDate;
     nDate.setYear(d.year()+1);
    if(nDate.valid()) return nDate;
}

date date::operator++(int){
    date d=*this;
    *this=next_date(*this);
    return d;
}

bool operator<(const date& d1,const date& d2){
    if(!d1.valid())return false;
    if(!d2.valid()) return false;
    if(d1.year()<d2.year()) return true;
    else if(d1.year()>d2.year()) return false;
    else{
        if(d1.month()<d2.month()) return true;
        else if(d1.month()>d2.month()) return false;
        else{
            if(d1.day()<d2.day()) return true;
            else return false;
        }
    }
    return false;
}

ostream& operator <<(ostream& os,const date& d){
    os<<d.year()<<" - "<<d.month()<<" - "<<d.day()<<"\n";
}