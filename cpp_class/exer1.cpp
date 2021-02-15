#include <iostream>
#include <string>
using namespace std;
struct Car{
  string license_plate;
  int year,month,day,hour,minute,second;
  Car(){}
  Car(string str_license,int y,int m,int d,int h,int min,int sec):license_plate(str_license),year(y),month(m),day(d),hour(h),minute(min),second(sec){}
};
class Seq_stack{
private:
  int max_length;
  int top;
  Car *elem;
public:
  Seq_stack(){}
  Seq_stack(int max_len):max_length(max_len),top(-1){elem=new Car[max_length];}
  virtual ~Seq_stack(){
    delete []elem;
  }
  int get_lenght(){
    return top+1;
  }
  bool is_empty()const{
    return top==-1;
  }
  void push(const Car c){
    if(top==max_length)return ;
    elem[++top]=c;
  }
  Car &get_top(){
    return elem[top];
  }
  friend ostream &operator<<(ostream &out,const Seq_stack&seq_stack){
    for(int i=0;i<=seq_stack.top;i++){
      cout<<"Car license:  "<<seq_stack.elem[i].license_plate<<"   Year:  "<<seq_stack.elem[i].year<<" Month:  "<<seq_stack.elem[i].month<<" Day:  "<<seq_stack.elem[i].day<<" Hour:  "<<seq_stack.elem[i].hour<<" Minute:  "<<seq_stack.elem[i].minute<<" Second:  "<<seq_stack.elem[i].second<<endl;
}
    return out;
  }
};
int main(){
  Car car1("hu00001",2012,12,12,14,20,59);
  Car car2("hu00002",2013,12,13,14,20,59);
  Car car3("hu00003",2014,12,14,14,24,59);
  Car list[]={car1,car2,car3};
  Seq_stack stack(4);
  stack.push(car1);
  stack.push(car2);
  stack.push(car3);
  cout<<stack;
}
