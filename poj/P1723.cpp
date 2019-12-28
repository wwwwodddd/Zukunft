#include<iostream>
using namespace std;
int x[10050],y[10050],z[10050];
int i,a,b,n,ans;
int cmp(const void* a,const void* b)
{
	return *((int*)a)-*((int*)b);
}
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	qsort(x,n,4,cmp);
	qsort(y,n,4,cmp);
	for(i=0;i<n;i++)
		z[i]=x[i]-(i-1);
	qsort(z,n,4,cmp);
	b=y[n/2],a=z[n/2];
	for(i=0;i<n;i++)
		ans+=abs(y[i]-b)+abs(z[i]-a);
	cout<<ans<<endl;
}