/*
Description

Finish the following definition

class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString(); // "mm, dd, yyyy"
  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  void addDays(int d); // adds the specified number of days to this instance
  void addMonths(int m); // adds the specified number of months to this instance
  void addYears(int y); // adds the specified number of years to this instance
  static bool isLeapYear(const Date &d);
private:
  int year, month, day;
};
class TimeSpan
{
public:
  TimeSpan();
  TimeSpan(int d, int hh, int mm, int ss);
  int toTotalDays ();
  int totalTotalHours();
  int toTotalMinutes();
  int toTotalSeconds ();
  string toString(); // dd HH:MM:SS
private:
  int day, hour, minute, second;
};
class DateTime : public Date
{
public:
  virtual string toString(); // "mm/dd/yyyy HH:MM:SS"
  DateTime() : Date()
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  DateTime(int y, int m, int d, int hh, int mm, int ss) : Date(y, m, d)
  {
    hour = hh;
    minute = mm;
    second = ss;
  }
  void setHour(int h);
  void setMinute(int m);
  void setSecond(int s);
  int getHour() const;
  int getMinute() const;
  int getSecond() const;
  void addHours(int h); // adds the specified number of hours to this instance
  void addMinutes(int m); // adds the specified number of minutes to this instance
  void addSeconds(int s); // adds the specified number of seconds to this instance
  TimeSpan operator-(const DateTime &dt) const; // return a TimeSpan object represents a time interval
private:
  int hour, minute, second;
};

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date
{
public:
    Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    virtual string toString() // "mm, dd, yyyy"
    {
        string temp;
        if(month < 10)
            temp = "0" + to_string(month);
        else
            temp = to_string(month);
        temp += ", ";
        if(day < 10)
            temp += "0" + to_string(day);
        else
            temp += to_string(day);
        temp += ", " + to_string(year);
        return temp;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }
    void addDays(int d)
    {
        day ++;
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(day > 31)
            {
                day = 1;
                addMonths(1);
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11) {
            if(day > 30) {
                day = 1;
                addMonths(1);
            }
        }
        else if(month == 2 && isLeapYear()) {
            if(day > 29) {
                day = 1;
                addMonths(1);
            }
        }
        else if(month == 2 && !isLeapYear()) {
            if(day > 28) {
                day = 1;
                addMonths(1);
            }
        }
    }

    void addMonths(int m){
        month ++;
        if(month > 12)
        {
            month = 1;
            addYears(1);
        }
    }
    void addYears(int y){
        year ++;
    }
    static bool isLeapYear(const Date &d)
    {
        int y = d.getYear();
        if(y % 400 == 0)
            return true;
        if(y % 100 == 0)
            return false;
        if(y % 4 == 0)
            return true;
        return false;
    }
    bool isLeapYear()
    {
        int y = year;
        if(y % 400 == 0)
            return true;
        if(y % 100 == 0)
            return false;
        if(y % 4 == 0)
            return true;
        return false;
    }
private:
    int year, month, day;
};
class TimeSpan
{
public:
    TimeSpan();
    TimeSpan(int d, int hh, int mm, int ss) {
        day = d;
        hour = hh;
        minute = mm;
        second = ss;
    }
    int toTotalDays() {
        int s = second;
        day = 0;
        hour = 0;
        minute = 0;
        while(s > 60)
        {
            s -= 60;
            minute ++;
        }
        while(minute > 60)
        {
            minute -= 60;
            hour ++;
        }
        while(hour > 24)
        {
            hour -= 24;
            day ++;
        }
        return day;
    }
    int toTotalHours() {
        int s = second;
        day = 0;
        hour = 0;
        minute = 0;
        while(s > 60)
        {
            s -= 60;
            minute ++;
        }
        while(minute > 60)
        {
            minute -= 60;
            hour ++;
        }
        return hour;
    }
    int toTotalMinutes() {
        int s = second;
        day = 0;
        hour = 0;
        minute = 0;
        while(s > 60)
        {
            s -= 60;
            minute ++;
        }
        return minute;
    }
    int toTotalSeconds() {
        return second;
    }
    string toString();
private:
    int day, hour, minute, second;
};
class DateTime : public Date
{
public:
    virtual string toString() {
        string temp;
        int month = getMonth();
        int year = getYear();
        int day = getDay();
        if(month < 10)
            temp = "0" + to_string(month);
        else
            temp = to_string(month);
        temp += "/";
        if(day < 10)
            temp += "0" + to_string(day);
        else
            temp += to_string(day);
        temp += "/" + to_string(year) + " ";
        if(hour < 10)
            temp += "0" + to_string(hour);
        else
            temp += to_string(hour);
        temp += ":";
        if(minute < 10)
            temp += "0" + to_string(minute);
        else
            temp += to_string(minute);
        temp += ":";
        if(second < 10)
            temp += "0" + to_string(second);
        else
            temp += to_string(second);
        return temp;
    }
    DateTime() : Date()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    DateTime(int y, int m, int d, int hh, int mm, int ss) : Date(y, m, d)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }
    void setHour(int h) {
        hour = h;
    }
    void setMinute(int m){
        minute = m;
    }
    void setSecond(int s){
        second = s;
    }
    int getHour() const {
        return hour;
    }
    int getMinute() const {
        return minute;
    }
    int getSecond() const {
        return second;
    }
    void addHours(int h) {
        hour ++;
        if(hour > 23) {
            hour = 0;
            addDays(1);
        }
    }
    void addMinutes(int m) {
        minute ++;
        if(minute > 59) {
            minute = 0;
            addHours(1);
        }
    }
    void addSeconds(int s) {
        second ++;
        if(second > 59) {
            second = 0;
            addMinutes(1);
        }
    }
    TimeSpan operator-(const DateTime &dt) const {
        int s = 0;
        DateTime temp(dt), temp2(*this);
        if(temp2 > temp)
            while(temp2.getYear() != temp.getYear() || temp2.getMonth() != temp.getMonth() || temp2.getDay() != temp.getDay() || temp2.getHour() != temp.getHour() || temp2.getMinute() != temp.getMinute() || temp2.getSecond() != temp.getSecond()) {
                temp.addSeconds(1);
                s ++;
            }
        else
            while(temp2.getYear() != temp.getYear() || temp2.getMonth() != temp.getMonth() || temp2.getDay() != temp.getDay() || temp2.getHour() != temp.getHour() || temp2.getMinute() != temp.getMinute() || temp2.getSecond() != temp.getSecond()) {
                temp2.addSeconds(1);
                s ++;
            }
        return TimeSpan(0, 0, 0, s);
    }
    bool operator>(const DateTime &dt) const {
        int year = getYear();
        int month = getMonth();
        int day = getDay();
        if(year > dt.getYear())
            return true;
        else if(year < dt.getYear())
            return false;
        if(month > dt.getMonth())
            return true;
        else if(month < dt.getMonth())
            return false;
        if(day > dt.getDay())
            return true;
        else if(day < dt.getDay())
            return false;
        if(hour > dt.getHour())
            return true;
        else if(hour < dt.getHour())
            return false;
        if(minute > dt.getMinute())
            return true;
        else if(minute < dt.getMinute())
            return false;
        if(second > dt.getSecond())
            return true;
        return false;
    }
private:
    int hour, minute, second;
};
int main()
{
    int y, m, d, hh, mm, ss;
    cin>>y>>m>>d>>hh>>mm>>ss;
    DateTime d1(y, m, d, hh, mm, ss);
    //cout<<d1.toString();
    cin>>y>>m>>d>>hh>>mm>>ss;
    DateTime d2(y, m, d, hh, mm, ss);
    cout<<(d1 - d2).toTotalSeconds();
    return 0;
}