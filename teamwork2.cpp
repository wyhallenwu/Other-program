#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int mad = 1;//���ֵı�־
struct word
{
	string w;//����
	int fz;//Ƶ��
	int locate;//����˳��

	word *next;
	word *pre;

	word() :next(NULL),pre(NULL){}
	word(const string &w_, word *pre_ = NULL, word *next_ = NULL,int fz_=1,int locate_=0) :w(w_), pre(NULL), next(NULL),fz(fz_),locate(locate_){ next = next_; pre = pre_; }
};
bool operator == (const string &n, const string &m)//==����
{
	if (n.size() != m.size())
		return false;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] != m[i])
			return false;
	}
	return true;
}
class Alist
{
private:
	word *head;
	int lenth ;
public:
	Alist();
	Alist(string *x,int lenth);
	virtual ~Alist();
	void Show() const;
	void Clear();
	void Delete(int x);
	void Add(int x,const string &data);//û��
	void Add(const string &data);
	void Add(int x, int y, const string &data, int z);
	int Find(int fz_,int locate_);
	void Sort(int x,int y);
    void Load(const char *filename);
    void Save(const char *filename);
	friend ostream & operator << (ostream &out, const Alist &data);
};
Alist::Alist()//�޲ι���
{
	head = new word;
	head->next = head->pre = head;
	lenth = 0;
}
Alist::Alist(string *x,int lenth_):head(NULL),lenth(lenth_)
{
	if (!x)
		return;
	word *p;
	p = head = new word;
	for (int i = 0; i < lenth_; i++)
	{
		p->next = new word(x[i], p);
		p = p->next;
		p->locate = mad;
		mad++;
	}
	head->pre = p;
	p->next = head;
}
Alist::~Alist()//����
{
	Clear();
	delete head;
}
void Alist::Clear()//�������
{
	while (lenth > 0)
		Delete(1);
	lenth = 0;
}
void Alist::Delete(int x)//����λ��ɾ���ڵ�
{
	if (x < 0)
		return;
	word *p = head->next;
	for (int i = 1; i < x; i++)
		p = p->next;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	delete p;
	lenth--;
}
void Alist::Add(const string &data)//����ʱ�Ĳ��뺯��
{
	int count = 0;
	word *p = head->next;
	for (; p != head; p = p->next)//��ǰ������ͬ�ĵ���
	{
		count++;//���ڵ�λ��
		if (p->w == data)
		{
			p->fz++;
			int n = Find(p->fz, p->locate);//Ӧ�ò����λ��
			if (count == 1 || n == -1 || count == n - 1)
				return;
			Sort(count, n - 1);
			return;
		}
	}
	if (p == head)//��������µĵ���
	{
		p = head->pre;
		p->next = new word(data, p, head, 1, mad++);
		p = p->next;
		head->pre = p;
		lenth++;
	}
}
void Alist::Add(int x,int y,const string &data,int z)//��Ƶ�����ӵĵ�����ӵ��ʵ�λ��
{
	if (x < 0)
		return;
	word *p = head->next;
	if (x == 0)
	{
		word *pa = new word(data, head, p, y,z);
		head->next = pa;
		p->pre = pa;
		return;
	}
	else if (x > 0)
	{
		for (int i = 1; i < x; i++)
			p = p->next;
		word *pa = new word(data, p, p->next, y, z);
		p->next->pre = pa;
		p->next = pa;
		lenth++;
		return;
	}
}
void Alist::Sort(int x,int y)//ɾ��ԭ�ڵ㣬�����½ڵ�
{
	word *p = head->next;
 	for (int i = 1; i < x; i++)
		p = p->next;
	int fzz = p->fz;
	string ww = p->w;
	int madd = p->locate;
	if (x > y) {
		Delete(x);
		Add(y, fzz, ww, madd);
	}
	else
	{
		Add(y+1, fzz, ww, madd);
		Delete(x);
	}
}
int Alist::Find(int fz_,int locate_)//Ѱ�ҽڵ���ӵ�λ��
{
	int count = 1;
	word *p = head->next;
	for (; p != head; p = p->next)
	{
		if (p->fz == fz_)
		{
			if (p->locate > locate_)
				return count;
			count++;
		}
		else if (p->fz < fz_) {

			return count;
		}
		else
			count++;
	}
	return -1;
}
void Alist::Show() const
{
	word *p = head->next;
	int count=1;
	while (p!=head)
	{
		cout<< count <<" ";
		cout << p->w << " " << p->fz << " " << endl;
		p = p->next;
		count++;
	}
}
void Alist::Add(int x,const string &data)
{
	if (x < 0)
		return;
	word *p = head->next;
	for (int i = 1; i < x; i++)
		p = p->next;
	word *pa = new word(data, p, p->next);
	p->next->pre = pa;
	p->next = pa;
	lenth++;
}
ostream & operator << (ostream &out, const Alist &data)
{
	data.Show();
	return out;
}
void Alist::Load(const char *filename)
{
	ifstream infile(filename);
	string c;
	while (infile >> c)
	{
		string s;
		for (int i = 0; i < c.size(); i++)
		{
			if (!ispunct(c[i]))
				s += c[i];
		}
		this->Add(s);

	}
	infile.close();
}
void Alist::Save(const char *filename)
{
	ofstream outfile(filename,ios::out);
	if(outfile.fail())
		return;
	int count=1;
	word *p = head->next;
	while (p!=head)
	{
		outfile << count <<" ";
		outfile << p->w << " " << p->fz << " " << endl;
		p = p->next;
		count++;
	}
	outfile.close();
}
int main()
{

	Alist tst;
	tst.Load("tale.txt");
	cout << tst << endl;
	tst.Save("out.txt");
    return 0;
}
