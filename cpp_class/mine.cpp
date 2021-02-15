#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Word{
    string word;
    int frequency;
    int order;
    Word *next;
    Word *prev;
    Word():next(NULL),prev(NULL),frequency(0),order(0),word("not a word"){}
    Word(string word_,int order_,Word *next_=NULL,Word *prev_=NULL):word(word_),frequency(1),next(next_),prev(prev_),order(order_){}
    Word(const Word &wr):word(wr.word),frequency(wr.frequency),order(wr.order){next=wr.next;prev=wr.prev;}
    bool operator==(const Word &wr){
        return wr.word==this->word;
    }
};
class Link{
protected:
    Word *head;
    int length;
public:
    Link():head(new Word),length(0){head->next=head;head->prev=head;}
    virtual ~Link(){
        clear();
        delete head;
    }
    void clear(){
        Word *p=head->next;
        while(p!=head){
            head->next=p->next;
            delete p;
            p=head->next;
        }
    }
    bool Is_exist(const string &str){
        Word *p=head->next;
        while(p!=head)
        {
            if(p->word==str) {
                p->frequency++;
                return true;
            }
            p=p->next;
        }
        return false;
    }

    void Insert_to_end(const string &str){
        Word *pguard=head;
        for(int i=0;i<length;i++)
        {
            pguard=pguard->next;
        }
        length++;
        Word *p=new Word(str,length,head,pguard);
        pguard->next=p;
        head->prev=p;
    }
    void Exchange(const string &str){
        Word *p=head->next;
        for(;p!=head;p=p->next)
        {
            if(p->word==str)
                break;
        }
        Word *pguard=head->next;
            for (; pguard != head; pguard = pguard->next) {
                if ((pguard->frequency==p->frequency&&pguard->prev->order<p->order&&pguard->order>p->order)||(pguard->frequency < p->frequency)) {
                    p->prev->next=p->next;
                    p->next->prev=p->prev;
                    p->prev=pguard->prev;
                    p->next=pguard;
                    p->prev->next=p;
                    pguard->prev=p;
                    break;
                }
            }
    }
    void show()const{
        Word *p=head->next;
        for(;p!=head;p=p->next)
        {
            cout<<p->word<<"  frequency:"<<p->frequency<<endl;
        }
    }
    void Load(const char *filename){
        ifstream infile(filename);
        string str;
        while (infile >> str) {
            string s;
            for (int i = 0; i < str.size(); i++) {
                if (!ispunct(str[i]))
                    s += str[i];
            }
            this->input(s);
        }
    }
    void input(const string &str){
        if (Is_exist(str)) {
            Exchange(str);
        } else {
            Insert_to_end(str);
        }
    }
    int get_length()const{
        return length;
    }
    void Save(const char *filename)
    {
        ofstream outfile(filename,ios::out);
        if(outfile.fail())
            return;
        int count=1;
        Word *p = head->next;
        while (p!=head)
        {
            outfile << count <<" ";
            outfile << p->word << " " << p->frequency << " " << endl;
            p = p->next;
            count++;
        }
        outfile.close();
    }
};
int main(){
    Link link;
    link.Load("tale.txt");
    link.Save("out1.txt");
    link.show();
    cout<<link.get_length();
    return 0;
}
