#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;
int l[100020],lc;
int a[100020];
typedef pair<int,int> ii;
ii v[100020];
int vc;
int calls;
int p[3310][3310],ans;
int h[100020];
int lim,bn,n,q;
int C(int l,int r,int x)
{
	calls++;
	return lower_bound(v,v+vc,ii(x,r))-lower_bound(v,v+vc,ii(x,l));
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int t,x,y;
	scanf("%d %*d %d",&n,&t);
	lim=(int)sqrt((double)n);
	lim=33;
	bn=n/lim;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		v[vc++]=ii(a[i],i);
	sort(v,v+vc);
	for(int i=0;i<bn;i++)
	{
		memset(h,0,sizeof h);
		for(int j=i;j<bn;j++)
		{
			if(j>i)
				p[i][j]=p[i][j-1];
			for(int k=j*lim+1;k<=(j+1)*lim;k++)
			{
				h[a[k]]++;
				if(h[a[k]]>1)
					if(h[a[k]]&1)
						p[i][j]--;
					else
						p[i][j]++;
			}
		}
	}
	memset(h,-1,sizeof h);
	for(;t--;)
	{
//		cerr << t << endl;
		scanf("%d %d",&x,&y);
		x=(x+ans)%n+1;
		y=(y+ans)%n+1;
		x>y?swap(x,y):void();
		int bl=(x+lim-2)/lim;
		int br=y/lim-1;
		if(br<bl)
		{
			ans=0;
			for(int i=x;i<=y;i++)
				if(h[a[i]]!=t)
				{
					int tmp=C(x,y+1,a[i]);
					if(tmp&&~tmp&1)
						ans++;
					h[a[i]]=t;
				}
		}
		else
		{
			ans=p[bl][br];
			for(int i=x;i<=bl*lim;i++)
				if(h[a[i]]!=t)
				{
					int old=C(bl*lim+1,(br+1)*lim+1,a[i]);
					int tmp=C(x,y+1,a[i]);
					if(old&&~old&1)
						ans--;
					if(tmp&&~tmp&1)
						ans++;
					h[a[i]]=t;
				}
			for(int i=(br+1)*lim+1;i<=y;i++)
				if(h[a[i]]!=t)
				{
					int old=C(bl*lim+1,(br+1)*lim+1,a[i]);
					int tmp=C(x,y+1,a[i]);
					if(old&&~old&1)
						ans--;
					if(tmp&&~tmp&1)
						ans++;
					h[a[i]]=t;
				}
		}
		printf("%d\n",ans);
	}
//	cerr << "calls:" << calls << endl;
//	cerr << clock();
//	while(1);
}
