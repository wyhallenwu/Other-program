#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Seq_Stack{
private:
  T MyCustomType; *data;
  int top;
  int max_length;
public:
  Seq_Stack(int max_len):top(-1),max_length(max_len){
    data=new T[max_length];
  }
  bool Is_empty(){
    return top==-1;
  }
  int get_length(){
    return top;
  }
  void Push(const T da_){
    if(++top<=max_length)
      {
        data[top]=da_;
      }
    else
      cout<<"overflow."<<endl;
  }
  T Pop(){
    if(this->is_empty())
    {
      cout<<"empty stack."<<endl;
    }
    else{
    top--;
    return data[top+1];
  }
  }
};
