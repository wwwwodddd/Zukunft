#include<stdio.h>
#include<string.h>
int a[70],ac;
int b[70],bc,ab;
int c[70],cc;
int t[2000020][10],tt;
int w[2000020];
int z[100020];
int q;
char s[50];
void add()
{
	cc=bc;
	memset(c,0,sizeof c);
	for(int i=0;i<cc;i++)
		c[i]=a[i+ab]+b[i];
	for(int i=0;i<cc;i++)
		c[i+1]+=c[i]/10,c[i]%=10;
	if(c[cc])
		cc++;
	int d=0;
	if(cc>60)
		d=1,cc--;
	ac=bc;
	for(int i=0;i<ac;i++)
		a[i]=b[i];
	bc=cc;
	for(int i=0;i<bc;i++)
		b[i]=c[i+d];
	ab=d;
}
void ins(char*s,int x)
{
	int p=0;
	for(;*s;s++)
	{
		if(!t[p][*s-'0'])
			t[p][*s-'0']=++tt;
		p=t[p][*s-'0'];
	}
	z[x]=p;
}
void ask(int x)
{
	int p=0;
	for(int i=ac;i--;)
	{
		if(!t[p][a[i]])
			return;
		p=t[p][a[i]];
		if(w[p]==-1)
			w[p]=x;
	}
}
int main()
{
	scanf("%d",&q);
	memset(w,-1,sizeof w);
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s);
		ins(s,i);
	}
	a[ac++]=0;
	b[bc++]=1;
	for(int i=0;i<100000;i++)
	{
		add();
		ask(i);
	}
	for(int i=1;i<=q;i++)
		printf("Case #%d: %d\n",i,w[z[i]]);
	return 0;
}
