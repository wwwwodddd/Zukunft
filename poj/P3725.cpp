/*#include"iostream"
using namespace std;

__int64 table[20];		//保存10^i
__int64 m,k;

void init()
{
	table[0]=1;
	int i;
	for(i=1;i<19;i++)
		table[i]=table[i-1]*10;
	table[19]=1;
	table[19]=~(table[19]<<63);
}

__int64 getrank(__int64 v)		//记算从10^i到v有多少个，(i)为v的位数-1
{
	int i;
	for(i=0;table[i]<=v;i++);
	return v-table[i-1]+1;
}

int check(__int64 v)		//检查是否是10^i，要特殊处理，因为10^i只能排在i+1位。
{
	int i;
	for(i=0;i<19;i++)
		if(table[i]==v)
			return i;
		else
			if(table[i]>v)
				return -1;
			return -1;
}

int main()
{
	init();
	while(EOF!=scanf("%I64d%I64d",&k,&m))
	{
		int temp=check(m);
		if(temp>=0)
		{
			if(temp+1==k)
			{
				printf("%I64d\n",k);
			}
			else
			{
				puts("0");
			}
			continue;
		}
		__int64 r=0;
		__int64 t=m;
		while(t)
		{
			r+=getrank(t);
			t/=10;
		}
		if(r==k)
		{
			printf("%I64d\n",m);
			continue;
		}
		if(r>k)
		{
			puts("0");
			continue;
		}
		k-=r;
		t=m*10;		//当k<r时，要增加n,每次增加一个位数，排在m前面的只有比m*10小的。
		while(true)
		{
			r=getrank(t)-1;
			if(r>=k)
				break;
			k-=r;
			t*=10;
		}
		int i;
		for(i=0;table[i]<=t;i++);
		printf("%I64d\n",table[i-1]+k-1);
	}
	return 0;
}*/
#include<stdio.h>
unsigned long long n,k;
unsigned long long l,r,m;
unsigned long long f[30]={0,0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999,999999999999,9999999999999,99999999999999,999999999999999,9999999999999999,99999999999999999,999999999999999999,9999999999999999999};
unsigned long long min(unsigned long long a,unsigned long long b)
{
	return a<b?a:b;
}
unsigned long long H(unsigned long long x)
{
	unsigned long long i;
	for(i=1;x/=10;i++);
	return i;
}
unsigned long long G(unsigned long long x)//可以等于，不可大于。
{
	unsigned long long r;
	if(H(n)==x)
		return n-1;
	else if(H(n)<x)
	{
		for(r=n;H(r)!=x;r*=10);
			return r-1;
	}
	else
	{
		for(r=n;H(r)!=x;r/=10);
			return r;
	}
}
unsigned long long check(unsigned long long x)
{
	unsigned long long h=H(x);
	unsigned long long cnt=0;
	for(unsigned long long i=1;i<h;i++)
		cnt+=G(i)-f[i];
	cnt+=min(x,G(h))-f[h];
	return cnt<k?0:1;
}
int main()
{
	while(scanf("%I64d %I64d",&k,&n)!=EOF)
	{
		k--;
		l=n;
		r=999999999999999999LL;
		while(l!=r)
		{
			m=(l+r)/2;
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		if(l==999999999999999999LL)
			printf("0\n");
		else
			printf("%I64d\n",l);
	}
	return 0;
}