#include <iostream>
using namespace std;
class Point{
protected:
    double x,y;
public:
    Point(int dx,int dy):x(dx),y(dy){}
};
class Circle:public Point{
private:
    int R;
public:
    Circle(int dx,int dy,int r):Point(dx,dy),R(r){}
    void GetO(){
        cout<<"Centre: ("<<x<<" , "<<y<<")"<<endl;
    }
    void GetR(){
        cout<<"Radius: "<<R<<endl;
    }
    void SetR(int r){
        R=r;
    }

    void MoveTo(int dx=0,int dy=0){
        x=dx;y=dy;
    }
    void Display(){
        GetO();
        GetR();
    }
};
int main(){
    Circle a(1,1,1);
    a.Display();
    return 0;
}
