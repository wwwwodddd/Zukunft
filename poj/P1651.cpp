#include<stdio.h>
int n;
int f[120][120];
int s[120];
int min(int x,int y)
{
	return x<y?x:y;
}
int F(int x,int y)
{
	if(f[x][y]!=0)
		return f[x][y];
	int i,re=0x3fffffff;
	if(x>y)
		return 0;
	for(i=x;i<=y;i++)
		re=min(re,F(x,i-1)+F(i+1,y)+s[x-1]*s[y+1]*s[i]);
	return f[x][y]=re;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	printf("%d",F(1,n-2));
	return 0;
}