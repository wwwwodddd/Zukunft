#include<stdio.h>
int t,m,n,l;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&l);
		if(l==30&&(m==9||m==11))
			m++;
		printf("%s\n",(m+l)&1?"NO":"YES");
	}
	return 0;
}