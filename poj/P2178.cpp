#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std; 
char o[110][60][110][15][3];
char a[120];
int l[120],b[120];
int hh,hm,mh,m,n,v,hpp,i,tot;
int cal(int x)
{
	return (x+mh-1)/mh;
}
int mfs(int hp,int mp,int mon,int p,int t)
{
	int i,j;
	if(mon<=0)
		return 1;
	if(hp<=0||mp<=0)
		return 0;
	if(o[hp][mp][mon][p][t])
		return 0;
	if(t==0)
	{
		if(p==1&&mfs(hp-cal(mon),mp,mon,1,1))
			return 1;
		if(p>1)
		{
			i=p-min(p-1,v);
			j=hp;
			if(i==1)
				j=hp-cal(mon);
			if(mfs(j,mp,mon,i,1))
				return 1;
		}
	}
	else if(t==1)
	{
		a[++tot]='L';
		if(mfs(hp,mp-1,mon-l[p],p,0))
			return 1;
		if(hp<hh)
		{
			a[tot]='H';
			if(mfs(min(hh,hp+hpp),mp-1,mon,p,0))
				return 1;
		}
		a[tot]='T';
		for(i=n;i>v;i--)
		{
	       b[tot]=i;
	       if(mfs(hp,mp-1,mon,i,0))
		   return 1;
		}
		tot--;
	}
	o[hp][mp][mon][p][t]=1;
	return 0;
}
int main()
{
	scanf("%d %d %d %d %d %d %d",&n,&hh,&hm,&mh,&m,&v,&hpp);
	for(i=1;i<=n;i++)
		scanf("%d",&l[i]);
	if(mfs(hh,hm,mh*m,n,1))
	{
		printf("%s\n","VICTORIOUS");
		for(i=1;i<=tot;i++)
		{
		printf("%c",a[i]);
		if(a[i]=='T')
			printf(" %d",b[i]);
		printf("\n");
		}
	}
	else
		printf("%s\n","DEFEATED");
	return 0;
}

