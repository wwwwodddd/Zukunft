#include<string>
#include<iostream>
#include<math.h>
using namespace std;
const double lg10=log(10.0);
class Int
{
private:
	double x;
	int sg;
public:
	Int(){x=0;sg=0;}
	Int(double a)
	{
		sg=1;
		if(a==0)
		{
			sg=0;
			return;	
		}
		if(a<0)
			sg=-1,a=-a;
		x=log(a)/lg10;
	}
	Int(double a,int z)
	{
		x=a,sg=z;
	}
	~Int(){}
	void print()
	{
		double o;
		int y=floor(x);
		o=x-floor(x);
		o=pow(10,o)*sg;
		if(sg==0)
		{
			printf("0.000\n");
			return;
		}
		if(o>9.9995)
		{
			o/=10;
			y++;
		}
		if(y!=0)
			printf("%.3lfE%d\n",o,y);
		else
			printf("%.3lf\n",o);
	}
	Int operator*(Int b)
	{
		return Int(b.x+x,b.sg*sg);
	}
	bool operator>(Int b)
	{
		if(sg!=b.sg)
			return sg>b.sg;
		return sg*x>b.sg*b.x;
	}
};
Int p,q,ans,u,lp,lq;
double ss;
Int a[100020];
int n,i;
Int max(Int a,Int b)
{
	if(a>b)
		return a;
	return b;	
}
Int min(Int a,Int b)
{
	if(b>a)
		return a;
	return b;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&ss);
			a[i]=ss;
		}
		lp=lq=1;
		ans=-1e300;
		for(i=1;i<=n;i++)
		{
			p=max(lq*a[i],max(lp*a[i],a[i]));
			q=min(lp*a[i],min(lq*a[i],a[i]));
			ans=max(p,ans);
			lp=p;
			lq=q;
		}
		ans.print();
	}
	return 0;
}
