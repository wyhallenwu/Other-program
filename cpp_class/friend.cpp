#include <iostream>
using namespace std;
class Animal{
protected:
	char *name;
	int ID;
public:
	Animal(char *pname="noname",int id=0):name(pname),ID(id){}
	void set_id(int id){ID=id;};
	void set_name(char *pname){name=pname;}
	virtual ~Animal(){if(name!=NULL)delete []name;}
	virtual void show(ostream & out)const
	{
		out<<name<<" and "<<ID<<endl;
	}
	friend ostream & operator<<(ostream&out,const Animal&ani)
	{
		ani.show(out);
		return out;
	}
};
class Bird:public Animal
{
protected:
	int wings;
public:
	Bird(char* pname,int id,int wing):Animal(pname,id),wings(wing){}
	void show(ostream & out)const
	{	
		Animal::show(out);
		out<<"wings: "<<wings<<endl;
	}
	friend ostream &operator<<(ostream & out,const Bird &bi)
	{
		bi.show(out);
		return out;
	}
	~Bird(){if(name!=NULL)delete name;}
};
int main(){
	Animal b("dog",1);
	Bird a("xique",10,2);
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}