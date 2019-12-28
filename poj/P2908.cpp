#include<stdio.h>
#include<string.h>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int t,n,m,l,st,ed;
int O[40],A[40],R[40],w[40];
char v[1<<20],s[40];
int BFS(int st,int ed)
{
	priority_queue<ii>q;
	memset(v,0,sizeof v);
	q.push(ii(0,st));
	for(;q.size();)
	{
		ii u=q.top();
		q.pop();
		if(v[u.Y])
			continue;
		if(u.Y==ed)
			return u.X;
		v[u.Y]=1;
		for(int i=0;i<n;i++)
		{
			int k=u.Y&A[i]^R[i]|O[i];
			if(!v[k])
				q.push(ii(u.X-w[i],k));
		}
	}
	return 1;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&l,&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%s %d",s,w+i);
			O[i]=R[i]=0;
			A[i]=(1<<l)-1;
			for(int j=0;j<l;j++)
				if(s[j]=='S')
					O[i]+=1<<j;
				else if(s[j]=='F')
					R[i]+=1<<j;
				else if(s[j]=='C')
					A[i]-=1<<j;
		}
		for(int i=0;i<m;i++)
		{
			st=ed=0;
			scanf("%s",s);
			for(int j=0;j<l;j++)
				st|=s[j]-'0'<<j;
			scanf("%s",s);
			for(int j=0;j<l;j++)
				ed|=s[j]-'0'<<j;
			int z=BFS(st,ed);
			if(z>0)
				printf("NP ");
			else
				printf("%d ",-z);
		}
		puts("");
	}
	return 0;
}
