#include<iostream>
#include<algorithm>
using namespace std;
int i,n,ans,k,t,z;
int mn=1<<30;
int a[10020];
int p[10020];
int h[10020];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d", a+i);
		mn=min(mn,a[i]);
		p[i]=i;
		ans+=a[i];
	}
	sort(p,p+n,cmp);
	for(i=0;i<n;i++)
		h[p[i]]=i;
	for(i=0;i<n;i++)
		if(p[i]!=-1)
		{
			k=0;
			t=a[p[i]];
			z=p[i];
			while(p[z]!=-1)
			{
				k++;
				p[z]=-1;
				z=h[z];
			}
			ans+=min((k-2)*t,t+(k+1)*mn);
		}
	printf("%d\n",ans);
	return 0;
}
