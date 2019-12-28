#include<stdio.h>
#include<string.h>
int u[20000];
int d[20000];
int l[20000];
int r[20000];
int R[20000];
int s[1025];
int c[20000];
int p,v[400];
char g[20][20];
void del(int x)
{
	int i,j;
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	for(i=d[x];i!=x;i=d[i])
		for(j=r[i];j!=i;j=r[j])
		{
			d[u[j]]=d[j];
			u[d[j]]=u[j];
			s[c[j]]--;
		}
	return;
}
void res(int x)
{
	int i,j;
	for(i=d[x];i!=x;i=d[i])
		for(j=l[i];j!=i;j=l[j])
		{
			d[u[j]]=u[d[j]]=j;
			s[c[j]]++;
		}
	r[l[x]]=l[r[x]]=x;
	return;
}
int dfs(int x)
{
	if(r[0]==0)
		return 1;
	int i,j,ts=0xffff,tc=0;
	for(i=r[0];i;i=r[i])
		if(s[i]<ts)
			ts=s[tc=i];
	if(ts==0)
		return 0;
	del(tc);
	for(i=u[tc];i!=tc;i=u[i])
	{
		v[x]=R[i];
		for(j=r[i];j!=i;j=r[j])
			del(c[j]);
		if(dfs(x+1))
			return 1;
		for(j=l[i];j!=i;j=l[j])
			res(c[j]);
	}
	res(tc);
	return 0;
}
int ins(int x,int y,int v)
{
	int nd=p++;
	u[nd]=u[x];
	d[nd]=x;
	if(v)
	{
		l[nd]=v;
		r[nd]=r[v];
		r[v]=l[r[v]]=nd;
	}
	else
		l[nd]=r[nd]=nd;
	c[nd]=x;
	R[nd]=y;
	s[x]++;
	u[x]=d[u[x]]=nd;
	return nd;
}
int main()
{
	int i,j,k,x,y,z,ln,rn,t,cs=0;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<9;i++)
			scanf("%s",g[i]);
		p=1;
		memset(v,0,sizeof(v));
		l[0]=r[0]=d[0]=u[0]=0;
		for(i=0;i<324;i++)
		{
			s[p]=0;
			d[p]=u[p]=p;
			l[p]=p-1;
			r[p]=r[p-1];
			l[r[p-1]]=p;
			r[p-1]=p;
			p++;
		}
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
			{
				x=0;
				y=8;
				z=i/3*3+j/3;
				if(g[i][j]!='0')
					x=y=g[i][j]-'1';
				for(k=x;k<=y;k++)
				{
					ln=0;
					rn=i*81+j*9+k;
					ln=ins(1+i*9+j,rn,ln);
					ln=ins(1+81+i*9+k,rn,ln);
					ln=ins(1+162+j*9+k,rn,ln);
					ln=ins(1+243+z*9+k,rn,ln);
				}
			}
		dfs(0);
		for(i=0;i<81;i++)
			g[v[i]/81][v[i]/9%9]='1'+v[i]%9;
		printf("Scenario #%d:\n",++cs);
		for(i=0;i<9;i++)
			puts(g[i]);
		puts("");
	}
	return 0;
}