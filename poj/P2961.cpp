#include<stdio.h>
long long x,y;
int t,h,w;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%*I64d%I64d%I64d%d%d",&x,&y,&w,&h);
		for(int i=0;i<h;i++,puts(""))
			for(int j=0;j<w;j++)
				printf("%d ",__builtin_popcount(y+i&x+j)&1?-1:1);
		puts("");
	}
}