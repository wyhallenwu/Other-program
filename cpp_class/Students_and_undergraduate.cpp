#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Students{
protected:
	char *name,*ID;
	int age;
public:
	Students(){}
	Students(char *na,char *id,int ag):name(na),ID(id),age(ag){cout<<"construct a Students!"<<endl;}
	Students(const Students& stu)
	{
		if(this!=&stu)
		{
			cout<<"construct a Students(copy)"<<endl;
			name=new char[strlen(stu.name)+1];
			strcpy(name,stu.name);
			ID=new char[strlen(stu.name)+1];
			strcpy(ID,stu.ID);
			age=stu.age;
		}
	}
	virtual ~Students(){cout<<"destruct a Students"<<endl;}
	virtual void get_name(){cout<<name<<" Students//virtual"<<endl;}
	friend ostream & operator<<(ostream & out,const Students &stu)
	{
		out<<stu.ID<<" "<<stu.name<<" "<<stu.age<<endl;
		return out;
	}
};
class Undergraduate:public Students{
private:
	char *tutor;
public:
	Undergraduate(){}
	Undergraduate(char *na,char *id,int age,char *tut):Students(na,id,age),tutor(tut){cout<<"construct a Undergraduate"<<endl;}
	virtual void get_name(){cout<<name<<" Undergraduate//virtual"<<endl;}
	virtual ~Undergraduate(){cout<<"destruct a Undergraduate"<<endl;}
	friend ostream & operator<<(ostream & out,const Undergraduate &stu)
	{
		out<<stu.ID<<" "<<stu.name<<" "<<stu.age<<" "<<stu.tutor<<endl;
		return out;
	}
};

int main(){
	Students a("allen","123",19);
	Students b(a);
	b.get_name();
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<"********"<<endl;
	Undergraduate c("allen","123",19,"anna");
	cout<<c<<endl;
	c.get_name();
	cout<<"***********"<<endl;
	Students d(c);
	cout<<d<<endl;
	return 0;
}