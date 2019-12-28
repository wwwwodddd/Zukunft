#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LT(x) ((x<<2)|1)
#define RT(x) ((x<<2)|2)
#define LB(x) ((x<<2)|3)
#define RB(x) ((x<<2)+4)
struct{
	char c;
	int lt,rt,lb,rb;
}a[1024*1024];
unsigned char g[1024][128];
char s[1024];
void C(int x,int t,int l,int s)
{
	int m;
	if(s==1)
		a[x].c=g[t][l>>3]&(1<<(l&7))?'B':'W';
	else
	{
		m=s>>1;
		C(LT(x),t,l,m);
		C(RT(x),t,l+m,m);
		C(LB(x),t+m,l,m);
		C(RB(x),t+m,l+m,m);
		if(a[LT(x)].c==a[RT(x)].c&&a[LT(x)].c==a[LB(x)].c&&a[LT(x)].c==a[RB(x)].c)
			a[x].c=a[LT(x)].c;
		else
			a[x].c='Q';
	}
}
void P(int x)
{
	putchar(a[x].c);
	if(a[x].c=='Q')
	{
		P(LT(x));
		P(RT(x));
		P(LB(x));
		P(RB(x));
	}
}
int main()
{
	int n,i,j;
	scanf("%s%s%d ",s,s,&n);
	gets(s);
	gets(s);
	for(i=0;i<n;i++)
		for(j=0;j<n>>3;j++)
			scanf("%x,",&g[i][j]);
	C(0,0,0,n);
	printf("%d\n",n);
	P(0);
	puts("");
	return 0;
}
