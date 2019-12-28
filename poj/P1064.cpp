#include <stdio.h>
int ns[10020];
int k,n,maxL=0,res=0;
double ipt;
int begin=0;
int end=maxL + 1;
int mid;
bool Test(int len)
{
	int i,j,t;
	for (i=0,j=0;i<n&&j<k;++i)
	{
		t=ns[i];
		while(j<k&&t>=len)
		{
			t-=len;
			++j;
		}
	}
	if (j<k)
		return false;
	if (res<len)
		res=len;
	return true;
}
int main()
{
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;++i)
	{
		scanf("%lf",&ipt);
		ns[i]=int(ipt*100);
		if(maxL<ns[i])
			maxL=ns[i];
	}
	while (begin<end)
	{
	mid=(begin+end)/2;
	if(Test(mid))
		begin=mid+1;
	else
		end=mid;
	}
	printf("%.2lf\n",double(res) / 100.0);
	return 0;
}
