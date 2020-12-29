#include <iostream>
#include <string>
using namespace std;

void get_failure(const string &pat,int f[]){
    int j=0,k=-1;
    f[0]=-1;
    while(j<pat.size()-1)
    {
        if(k==-1||pat[k]==pat[j]) {
            j++;
            k++;
            f[j] = k;
        }
        else
            k=f[k];
    }
}

bool KMP_find(const string &ob,const string &pat,int p=0){
    int *f=new int[pat.size()];
    get_failure(pat,f);
    for(int i=0;i<pat.length();i++)
        cout << *(f + i) << " ";
    cout<<endl;
    int i=p,j=0;
    while(i<ob.size()&&j<pat.size()&&pat.size()-j<=ob.size()-i)
    {
        if(j==-1||pat[j]==ob[i]) {
            i++;
            j++;
        }
        else
            j = f[j];
        delete []f;
        if(j<pat.size())
           return false;
        else
            return i-j;
    }
}
int main(){
    string ob="ahfdjfhkjdsafewoimxcv",pat="abcaabcabc";
    cout<<KMP_find(ob,pat)<<endl;
    return 0;
}
