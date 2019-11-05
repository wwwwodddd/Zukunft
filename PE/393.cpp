#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char ch;
int h[40010],tot[2],cur,pre,a[20][20];
int n,m,ex,ey,le,up,pos,nxt;
long long s[2][1000000][2],ans,cnt;
int find(int x,int y,int z)
{
	int t=1,w,d=1;
	if(x==1)
		t=-1,d=-1;
	for(;0<y&&y<m;)
	{
		y+=d;
		w=(z>>2*y)&3;
		if(w==1)
			t++;
		if(w==2)
			t--;
		if(!t)
			return y;
	}
	return 0;
}
void add(int st,long long cnt)
{
	int u=st%40001;
	for(;h[u];)
	{
		if(s[cur][h[u]][0]==st)
		{
			s[cur][h[u]][1]+=cnt;
			return;
		}
		u++;
		if(u==40001)
			u=0;
	}
	h[u]=++tot[cur];
	s[cur][tot[cur]][0]=st;
	s[cur][tot[cur]][1]=cnt;
}

void sb()
{
	memset(h,0,sizeof h);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			a[i][j] = 1;
			ex=i,ey=j;
		}
	s[cur][1][0]=0;
	s[cur][1][1]=1;
	tot[cur]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sb();
			pre=cur;
			cur^=1;
			tot[cur]=0;
			for(int k=1;k<=tot[pre];k++)
			{
				pos=s[pre][k][0];
				cnt=s[pre][k][1];
				le=(pos>>(2*j))&3;
				up=(pos>>(2*j+2))&3;
				if(!a[i][j])
				{
					if(!le&&!up)
						add(pos,cnt);
				}
				else if(!le&&!up)
				{
					if(a[i+1][j]&&a[i][j+1])
					{
						nxt=pos+(1<<(2*j))+(2<<(2*j+2));
						add(nxt,cnt);
					}
				}
				else if(le&&!up)
				{
					if(a[i][j+1])
					{
						nxt=pos-(le<<(2*j))+(le<<(2*j+2));
						add(nxt,cnt);
					}
					if(a[i+1][j])
						add(pos,cnt);
				}
				else if(!le&&up)
				{
					if(a[i+1][j])
					{
						nxt=pos-(up<<(2*j+2))+(up<<(2*j));
						add(nxt,cnt);
					}
					if(a[i][j+1])
						add(pos,cnt);
				}
				else if(le==1&&up==1)
				{
					int p=find(2,j+1,pos);
					nxt=pos-(1<<(2*j))-(1<<(2*j+2))-(1<<2*p);
					add(nxt,cnt);
				}
				else if(le==2&&up==2)
				{
					int p=find(1,j,pos);
					nxt=pos-(2<<(2*j))-(2<<(2*j+2))+(1<<2*p);
					add(nxt,cnt);
				}
				else if(le==2&&up==1)
				{
					nxt=pos-(2<<(2*j))-(1<<(2*j+2));
					add(nxt,cnt);
				}
				else if(le==1&&up==2) {
					nxt=pos-(1<<(2*j))-(2<<(2*j+2));
					add(nxt,2*cnt);
					if(i==ex&&j==ey)
						ans+=2*cnt;
				}
			}
		}
		for(int j=1;j<=tot[cur];j++)
			s[cur][j][0]<<=2;
	}
	cout<<ans<<endl;
	return 0;
}