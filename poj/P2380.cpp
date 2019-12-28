#include<iostream>
#include<algorithm>
using namespace std;
struct O
{
long q,s,vi;
}a[500005];
int qq[500005],ss[500005];
int q[500005],s[500005];
int i,j,k,n,v;
int qc=0,sc=0;
int cmp(const O &a,const O &b)
{
	if(a.s!=b.s)
		return a.s<b.s;
	return a.q<b.q;
}
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i].q,&a[i].s,&a[i].vi);
		qq[i]=a[i].q;
		ss[i]=a[i].s;
	}
	sort(qq,qq+n);
	sort(ss,ss+n);
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
	{
		if(qq[i]!=qq[i+1])
			q[qc++]=qq[i];
		if(ss[i]!=ss[i+1])
			s[sc++]=ss[i];
	}
	printf("-1 ");
	for(i=0;i<qc;i++)
		printf("%d ",q[i]); 
	printf("%\n");
	for(i=0;i<sc;i++)
	{
		printf("%d ",s[i]);
		for(j=0;j<qc;j++)
		{
			for(v=0;a[k].q==q[j]&&a[k].s==s[i];k++)
				v+=a[k].vi;
			printf("%d ",v);
		}
		printf("\n");
	}
	return 0;
}