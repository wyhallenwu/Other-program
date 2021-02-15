#include <iostream>
#include <string>
using namespace std;
class Currency{
protected:
	double rate, value;
public:
	Currency(double ra=1,double val=0):rate(ra),value(val){}
	void set_rate(double ra){rate=ra;}
	double get_value(){return value;}
	void set_value(double val){value=val;}
	virtual void show(ostream &out) const
	{
		out<<"value: "<<value<<"   "<<"rate: "<<rate<<endl;
	}
	friend ostream & operator<<(ostream &out ,const Currency &cu){cu.show(out);return out;}
};
class CNY:public Currency{
public:
	CNY(double value,double rate):Currency()
};