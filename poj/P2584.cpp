#include<iostream>
using namespace std;
int d[220];
int r[220][220];
int g[220][220];
int c[220];
int p[220];
int n,m;
int isap(int s,int t)
{
	int i=s,j;
	int re=0,z;
	c[0]=m;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
int i,j,x,M;
char s[300],cc[300];
int main()
{
	cc['S']=1;
	cc['M']=2;
	cc['L']=3;
	cc['X']=4;
	cc['T']=5;
	while(1)
	{
		scanf("%s",s);
		if(strcmp(s,"ENDOFINPUT")==0)
			break;
		scanf("%d",&M);
		m=M+5+2;
		memset(c,0,sizeof(c));
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		for(i=1;i<=M;i++)
		{
			scanf("%s",s);
			g[0][5+i]=1;
			for(j=cc[s[0]];j<=cc[s[1]];j++)
				g[5+i][j]=1;
		}
		for(i=1;i<=5;i++)
		{
			scanf("%d",&x);
			g[i][m-1]=x;
		}
		scanf("%s",&s);
		if(isap(0,m-1)==M)
			printf("T-shirts rock!\n");
		else
			printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}