#include <iostream>
#include <cstring>
using namespace std;
void swap1r(char &x,char &y)
{
	char temp=x;
	x=y;
	y=temp;
}
void swap1p(char *x,char *y)
{
	char temp=*x;
	*x=*y;
	*y=temp;
}
void swap2r(char *&x,char *&y)
{
	char *temp=x;
	x=y;
	y=temp;
}
void swap2p(char **x,char **y)
{
	char *temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void swap_str(char *const x,char *const y)
{
	char *str=new char[strlen(x)+1];
	strcpy(str,x);
	strcpy(x,y);
	strcpy(y,str);
	delete []str;
}
int main(){
	char c1='A',c2='B';
	char *p="Tom",*q="Jerry";
	char s[10]="hello",t[10]="World";
	swap1r(c1,c2);
	cout<<c1<<"  1  "<<c2<<endl;
	swap1p(&c1,&c2);
	cout<<c1<<"  2  "<<c2<<endl;
	swap2r(p,q);
	cout<<p<<"  3  "<<q<<endl;
	swap2p(&p,&q);
	cout<<p<<"  4  "<<q<<endl;
	swap_str(s,t);
	cout<<s<<"  5  "<<t<<endl;
	return 0;
}