#include <iostream>
using namespace std;
class Time{
private:
	int h,m,s;
public:
	Time(int h=0,int m=0,int s=0);
	Time(const Time &time){h=time.h;m=time.m;s=time.s;num++;}
	Time operator++(int);
	Time & operator++();
	friend ostream & operator<<(ostream& out,const Time &time);
	static int num;
};
Time::Time(int hour,int min,int sec):h(hour),m(min),s(sec){num++;}
Time Time::operator++(int){
	Time temp(*this);
	++(*this);
	return temp;
}
Time & Time::operator++()
{
	s++;
	if(s==60){s=0;m++;}
	if(m==60){m=0;h++;}
	if(h==24){h=0;}
	return *this;
}
ostream & operator<<(ostream &out,const Time & time){
	out<<time.h<<":"<<time.m<<":"<<time.s;
	return out;
}
int Time::num=0;
int main(){
	Time t(23,59,59);
	t++++;
	cout<<t<<endl;
	cout<<Time::num;
	return 0;
}