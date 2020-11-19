#include<stdio.h>
int t,n,k,q;
int main()
{
	for(scanf("%d",&t);t--;)
		scanf("%d %d",&n,&k),printf("Case #%d: %.8f\n",++q,1./(k*n+k+1));
}
