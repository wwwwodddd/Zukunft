#include<iostream>
using namespace std;
int n,cnt;
char a[30];
void dfs(int w,int x,int y,int z)
{
	if(w==n+1)
	{
		if(x+z*y==0)
		{
			if(cnt<20)
			{
				int i;
				for(i=0;i<w-2;i++)
					printf("%d %c ",i+1,a[i]);
				printf("%d\n",i+1);
			}
			cnt++;
		}
		return;
	}
	a[w-2]='+';
	dfs(w+1,x+z*y,w,1);
	a[w-2]='-';
	dfs(w+1,x+z*y,w,-1);
	a[w-2]='.';
	if(w<10)
		dfs(w+1,x,y*10+w,z);
	else
		dfs(w+1,x,y*100+w,z);
}
int main()
{
	scanf("%d",&n);
	dfs(2,0,1,1);
	printf("%d\n",cnt);
	return 0;
}
