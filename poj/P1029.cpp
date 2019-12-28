#include<stdio.h>
#include<string.h>
int n,m;
char v[1020];
char o[1020];
char g[1020];
char h[1020];
int l[1020],r[1020];
int i,j,k,ans;
char c;
void E()
{
	for(i=0;i<k;i++)
		v[l[i]]=v[r[i]]=1;
	return;
}
void L()
{
	memset(o,1,sizeof(o));
	for(i=0;i<k;i++)
		o[l[i]]=o[r[i]]=0;
	for(i=0;i<k;i++)
		g[l[i]]=h[r[i]]=1;
	for(i=1;i<=n;i++)
		v[i]|=o[i]|(g[i]&h[i]);
}
void M()
{
	memset(o,1,sizeof(o));
	for(i=0;i<k;i++)
		o[l[i]]=o[r[i]]=0;
	for(i=0;i<k;i++)
		h[l[i]]=g[r[i]]=1;
	for(i=1;i<=n;i++)
		v[i]|=o[i]|(g[i]&h[i]);
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		ans=0;
		memset(v,0,sizeof(v));
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		while(m--)
		{
			scanf("%d",&k);
			for(i=0;i<k;i++)
				scanf("%d",&l[i]);
			for(i=0;i<k;i++)
				scanf("%d",&r[i]);
			scanf("%s",&c);
			if(c=='<')
				L();
			if(c=='=')
				E();
			if(c=='>')
				M();
		}
		for(i=1;i<=n;i++)
			if(v[i]==0)
				j=i,ans++;
		printf("%d\n",ans==1?j:0);
	}
	return 0;
}