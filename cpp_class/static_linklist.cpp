#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node *next;
};
template <typename T>
class Link{
protected:
    int avail;
public:
    Link(){}
};
