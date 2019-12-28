#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Int
{
private:
	int a[15];
public:
	Int(){memset(a,0,sizeof(a));}
	~Int(){}
	Int operator*(Int b)
	{
		Int re;
		for(int i=0;i<10;i++)
			re.a[i]=b.a[a[i]];
		return re;
	}
	void scan()
	{
		for(int i=0;i<10;i++)
			scanf("%d",&a[i]);
		return;
	}
	void clear()
	{
		for(int i=0;i<10;i++)
			a[i]=i;
		return;
	}
	void set(int p,int v)
	{
		a[p]=v;	
	}
	int get(int x)
	{
		return a[x];
	}
};
Int g[15],us;
unsigned long long f[20],x,y,xx,yy;
int m,l,t,ans[50];
char s[120];
Int pw(Int x,unsigned long long y)
{
	Int re;
	re.clear();
	while(y)
	{
		if(y&1)
			re=re*x;
		x=x*x;
		y>>=1;
	}
	return re;
}
Int C(int x,int y,int z)
{
	Int re;
	re.clear();
	for(int i=z;i<z+10;i++)
		re=re*pw(g[i%10],f[x]);
	re=pw(re,y);
	return re;
}
void F()
{
	f[0]=1;
	for(int i=1;i<20;i++)
		f[i]=f[i-1]*10;
}
int gw(unsigned long long x,int y)
{
	return x/f[y]%10;
}
int tmp;
int main()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{	
			scanf("%d",&tmp);
			g[j].set(i,tmp);
		}
    F();
	scanf("%llu %llu",&x,&y);
	for(int i=0;i<19;i++)
	{
		if(x/f[i]!=y/f[i])
		{
			us.clear();
			xx=x-x%f[i]+f[i];
			yy=y-y%f[i];
			us=us*pw(g[gw(x,i)],xx-x-1);
			for(int j=0;j<(yy-xx)/f[i]%10;j++)
				us=us*pw(g[(gw(xx,i)+j)%10],f[i]);
			us=us*C(i,(yy-xx)/f[i+1],(y/f[i])%10);
			us=us*pw(g[gw(y,i)],y-yy+1);
			ans[i]=us.get(x%f[i+1]/f[i]);
		}
		else
		{
			us.clear();
			us=pw(g[gw(x,i)],y-x);
			ans[i]=us.get(gw(x,i));
		}
	}
	int l=20;
	while(!ans[l]&&l)
		l--;
	printf("%d",ans[l]);
	for(int i=l-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
}
