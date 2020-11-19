#include<stdio.h>
#include<string.h>
#include<iostream>
#define ins(v) f[!u].add(x^(v)<<j*2,y)
using namespace std;
#define fh for(int i=1,x=f[u].a[i][1],y=f[u].a[i][2];i<=f[u].tot;i++,x=f[u].a[i][1],y=f[u].a[i][2])
int mo=49877,n,m;
char s[105][105];
struct H
{
	int tot,h[50020],a[600020][3];
	void clr()
	{
		memset(h,0,sizeof h);
		tot=0;
	}
	void add(int x,int y)
	{
		for(int i=h[x%mo];i;i=a[i][0])
			if(a[i][1]==x)
			{
				a[i][2]=(a[i][2]+y)%20110520;
				return;
			}
		tot++;
		a[tot][0]=h[x%mo];
		a[tot][1]=x;
		a[tot][2]=y;
		h[x%mo]=tot;
	}
}f[2];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	if(m>n)
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<m;j++)
				swap(s[i][j],s[j][i]);
		swap(n,m);
	}
	f[0].add(0,1);
	int u=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			f[!u].clr();
			if(s[i][j]=='*')
			{
				fh
					if((x>>j*2&15)==0)
						f[!u].add(x,y);
				u^=1;
				continue;
			}
			fh
				switch(x>>j*2&15)
				{
					case 0:ins(0^2);ins(0^5);ins(0^8);break;
					case 1:ins(1^0);ins(1^4);break;
					case 2:ins(2^8);ins(2^1);break;
					case 4:ins(4^0);ins(4^1);break;
					case 8:ins(8^2);ins(8^4);break;
					case 10:ins(10^0);break;
				}
			u^=1;
		}
		f[!u].clr();
		fh
			if((x>>m*2)==0)
				f[!u].add(x<<2,y);
		u^=1;
	}
	fh
		if(x==0)
		{
			printf("%d\n",y);
			return 0;
		}
	puts("0");
	return 0;
}
