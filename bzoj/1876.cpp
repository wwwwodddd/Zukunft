#include<string>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Int
{
public:
	int a[3000];
	Int(){memset(a,0,sizeof(a));}
	void print()
	{
		printf("%d",a[a[0]]);
		for(int i=a[0]-1;i>0;i--)
			printf("%04d",a[i]);
		printf("\n");
	}
	Int operator+(Int b)
	{
		Int re;
		int l=max(a[0],b.a[0]);
		for(int i=1;i<=l;i++)
			re.a[i]=a[i]+b.a[i];
		for(int i=1;i<=l;i++)
		{
			re.a[i+1]+=re.a[i]/10000;
			re.a[i]%=10000;
		}
		if(re.a[l+1])
			l++;
		re.a[0]=l;
		return re;
	}
	Int operator-(Int b)
	{
		Int re;
		int l=max(a[0],b.a[0]);
		for(int i=1;i<=l;i++)
			re.a[i]=a[i]-b.a[i];
		for(int i=1;i<=l;i++)
			if(re.a[i]<0)
			{
				re.a[i+1]--;
				re.a[i]+=10000;
			}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
	Int div2()
	{
		int l=a[0],y=0;
		for(int i=a[0];i>0;i--)
		{
			a[i-1]+=(a[i]&1)*10000;
			a[i]>>=1;
		}
		while(!a[l]&&l)
			l--;
		a[0]=l;
		return *this;
	}
	int mod2()
	{
		return a[1]&1;
	}
	int so()
	{
		return a[1]==0&&a[0]==0;
	}
	Int mul2()
	{
		for(int i=1;i<=a[0];i++)
			a[i]*=2;
		for(int i=1;i<=a[0];i++)
		{
			a[i+1]+=a[i]/10000;
			a[i]%=10000;
		}
		if(a[a[0]+1])
			a[0]++;
		return *this;
	}
	Int mul65536()
	{
		for(int i=1;i<=a[0];i++)
			a[i]*=65536;
		for(int i=1;i<=a[0];i++)
		{
			a[i+1]+=a[i]/10000;
			a[i]%=10000;
		}
		if(a[a[0]+1])
			a[0]++;
		return *this;
	}
	bool operator <(const Int b)
	{
		int i;
		if(a[0]!=b.a[0])
			return a[0]<b.a[0];
		for(i=a[0];i>0;i--)
			if(a[i]!=b.a[i])
				return a[i]<b.a[i];
		return 0;
	}
}a,b;
char sa[10020],sb[10020];
int ta[10020],tb[10020];
int t[10];
int la,lb,i,j,c;
int main()
{
	scanf("%s %s",sa,sb);
	la=strlen(sa);
	lb=strlen(sb);
	t[0]=1;
	for(i=1;i<10;i++)
		t[i]=10*t[i-1];
	for(i=0;i<la;i++)
		ta[la-i]=sa[i]-'0';
	for(i=0;i<lb;i++)
		tb[lb-i]=sb[i]-'0';
	for(i=1;i<=la;i+=4)
	{
		a.a[0]++;
		for(j=i;j<i+4;j++)
			a.a[a.a[0]]+=ta[j]*t[j-i];
	}
	for(i=1;i<=lb;i+=4)
	{
		b.a[0]++;
		for(j=i;j<i+4;j++)
			b.a[b.a[0]]+=tb[j]*t[j-i];
	}
	while(1)
	{
		if(a<b)
			swap(a,b);
		if(b.so())
			break;
		i=a.mod2();
		j=b.mod2();
		if(!i)
			a.div2();
		if(!j)
			b.div2();
		if(!i&&!j)
			c++;
		if(i&&j)
			a=a-b;
	}
	while(c)
	{
		if(c>=16)
			a.mul65536(),c-=16;
		else
			a.mul2(),c--;
	}
	a.print();
	return 0;
}