#include <iostream>
using namespace std;
class Obj1{
public:
	Obj1(){cout<<"Obj1"<<endl;}
	~Obj1(){cout<<"~Obj1"<<endl;}
};
class Obj2{
public:
	Obj2(){cout<<"Obj2"<<endl;}
	~Obj2(){cout<<"~Obj2"<<endl;}
};
class Base1{
public:
	Base1(){cout<<"Base1"<<endl;}
	~Base1(){cout<<"~Base1"<<endl;}
};
class Base2{
public:
	Base2(){cout<<"Base2"<<endl;}
	~Base2(){cout<<"~Base2"<<endl;}
};
class Base3{
public:
	Base3(){cout<<"Base3"<<endl;}
	~Base3(){cout<<"~Base3"<<endl;}
};
class Base4{
public:
	Base4(){cout<<"Base4"<<endl;}
	~Base4(){cout<<"~Base4"<<endl;}
};
class Derived:public Base1,virtual public Base2,public Base3,virtual public Base4
{
public:
	Derived():Base4(),Base3(),Base2(),Base1(),y(),x()
	{
		cout<<"Derived"<<endl;
	}
	~Derived(){cout<<"~Derived"<<endl;}
private:
	Obj1 x;
	Obj2 y;
};
int main(){
	Derived d;
	cout<<"return to main "<<endl;
	return 0;
}