#include<stdio.h>
int f[2020][2020];
int v[30];
char s[2020];
int n,m,x,y,i,c;
int min(int x,int y)
{
	return x<y?x:y;
}
int F(int x,int y)
{
	if(f[x][y]!=0)
		return f[x][y];
	if(x>=y)
		return 0;
	if(s[x]==s[y])
		return f[x][y]=F(x+1,y-1);
	return f[x][y]=min(F(x+1,y)+v[s[x]-'a'],F(x,y-1)+v[s[y]-'a']);
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d",&c,&x,&y);
		v[c-'a']=min(x,y);
	}
	printf("%d",F(0,m-1));
	return 0;
}