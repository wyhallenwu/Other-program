#include <iostream>
using namespace std;
template <typename T>
class Vec{
private:
    T real,imag;
public:
    Vec(T re=0,T im=0):real(re),imag(im){}
    Vec<T> & operator=(const Vec<T>& v);
    friend ostream & operator<<(ostream &out, const Vec<T>& v){
        out<<v.real<<"+"<<v.imag<<'i'<<endl;
        return out;
    }
    Vec<T> operator+(const Vec<T> &v);
    Vec<T> operator*(const Vec<T> &v);
    Vec<T>& operator+=(const Vec<T> &v);
    Vec<T> & operator++();
    Vec<T>  operator++(int);
};
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &v)
{
	this->real=v.real;
	this->imag=v.imag;
	return *this;
}
template <typename T>
Vec<T> Vec<T>::operator+(const Vec<T> &v)
{
	Vec<T> tem;
	tem.real=this->real+v.real;
	tem.imag=this->imag+v.imag;
	return tem;
}
template <typename T>
Vec<T> Vec<T>::operator*(const Vec<T> & v)
{
	Vec<T> tem;
	tem.real=this->real*v.real;
	tem.imag=this->imag*v.imag;
	return tem;
}
template <typename T>
Vec<T> & Vec<T>::operator+=(const Vec<T> &v)
{
	this->real+=v.real;
	this->imag+=v.imag;
	return *this;
}
template <typename T>
Vec<T> & Vec<T>::operator++()
{
	this->real++;
	this->imag++;
	return *this;
}
template <typename T>
Vec<T> Vec<T>::operator++(int)
{
	Vec<T> tem(*this);
	++(*this);
	return tem;
}
int main(){
	Vec<double> a(1.1,2.2);
	Vec<double> b(3.3,4.4);
	Vec<double> t;
	t=a+b;
	cout<<t<<endl;
	t=a*b;
	cout<<t<<endl;
	++a;
	cout<<a<<endl;
	cout<<(b++)<<endl;
	cout<<b<<endl;
}