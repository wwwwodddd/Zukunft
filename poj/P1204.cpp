#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char s[1020][1020];
char c[1020];
int t[1000020][26],tt;
int g[1000020];
int w[1000020];
int z[1020][3];
int len[1020];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int ans,n,m,l;
void ins(char *s,int i)
{
	int p=0;
	for(;*s;s++)
	{
		if(!t[p][*s-'A'])
			t[p][*s-'A']=++tt;
		p=t[p][*s-'A'];
	}
	w[p]=i;
}
queue<int>q;
void bd()
{
	q.push(0);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
			if(t[u][i])
			{
				if(u)
					g[t[u][i]]=t[g[u]][i];
				q.push(t[u][i]);
			}
			else
				t[u][i]=t[g[u]][i];
	}
}
void ok(int x,int y,int dx,int dy,char o)
{
	int p=0;
	for(;x>=0&&y>=0&&x<m&&y<l;x+=dx,y+=dy)
	{
		p=t[p][s[x][y]-'A'];
		for(int i=p;i;i=g[i])
			if(w[i])
			{
				z[w[i]][0]=x-dx*(len[w[i]]-1);
				z[w[i]][1]=y-dy*(len[w[i]]-1);
				z[w[i]][2]=o;
				w[i]=0;
			}
	}
}
int main()
{
	scanf("%d %d %d",&m,&l,&n);
	for(int i=0;i<m;i++)
		scanf("%s",s[i]);
	for(int i=1;i<=n;i++)
		scanf("%s",c),ins(c,i),len[i]=strlen(c);
	bd();
	for(int i=0;i<m;i++)
		for(int j=0;j<8;j++)
			ok(i,0,dx[j],dy[j],'A'+j);
	for(int i=0;i<m;i++)
		for(int j=0;j<8;j++)
			ok(i,l-1,dx[j],dy[j],'A'+j);
	for(int i=0;i<l;i++)
		for(int j=0;j<8;j++)
			ok(0,i,dx[j],dy[j],'A'+j);
	for(int i=0;i<l;i++)
	{
		if(i==19)
			i=19;
		for(int j=0;j<8;j++)
			ok(m-1,i,dx[j],dy[j],'A'+j);
	}
	for(int i=1;i<=n;i++)
		printf("%d %d %c\n",z[i][0],z[i][1],z[i][2]);
	return 0;
}
