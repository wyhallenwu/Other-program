#include "LinkList.h"
#include <iostream>
#include <string>
using namespace std;
class Book{
public:
	string name;
	int ID;
	Book(string n="noname",int id=0):name(n),ID(id){}
	friend ostream & operator<<(ostream &out,const Book &book)
	{
		out<<"ID: "<<book.ID<<"  Name: "<<book.name<<endl;
		return out;
	}
};
int main(){
	Book book1("a",1),book2("b",2),book3("c",3);
	Book bookarray[3]={book1,book2,book3};
	LinkList<Book> list(3,bookarray);
	list.ShowList();
	return 0;
}