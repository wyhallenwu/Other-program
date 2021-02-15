Node:T data, Node<T> *next    Ls:Node<T> *head
LinkList<T>::LinkList(int n,const T *x):head(NULL),next(NULL)
{
	Node<T> *p;
	for(i=n-1;i>=0;i--)
	{
		p=new Node<T>;
		if(x!=NULL)
			p->data=x[i];
		p->next=head;
		head=p;
	}
}
LinkList<T>::LinkList(const LinkList<T> &link)
{
	*this=link;
}
LinkList<T>::~LinkList()
{
	FreeList();
}
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& link)
{
	if(this==&link)return *this;
	Node<T> *p=head;
	for(p;p!=NULL;p=p->next)
		Append(p->data);
	return *this;
}
void LinkList<T>::FreeList()
{
	if(head==NULL)return ;
	Node<T> *p=new Node<T>;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
void LinkList<T>::Append(const T &t)
{
	Node<T> *p=new Node<T>(t);
	Node<T> *pguard=new Node<T>;
	for(pguard=head;pguard->next!=NULL;pguard=pguard->next)
	pguard->next=p;
}
void LinkList<T>::ShowList(ostream & out)cosnt
{
	Node<T> *p=new Node <T>;
	for(p=head;p!=NULL;p=p->next)
		out<<p-data<<"->";
	return out;
}
ostream & LinkList::operator<<(ostream & out,const LinkList<T> &link)
{
	link.ShowList(out);
	return out;
}