#include<stdio.h>
int n,x,y,xy;
int i,ans;
int s(int x,int y)
{
	x--;
	return x/100-y/100;
}
int main()
{	
	while(scanf("%d %d %d",&n,&x,&y)+1)
	{
		xy=x-y;
		if(xy==0)
		{
			if(x%100||x==0||x==100*n)
				printf("%d\n",n);
			else
				printf("%d\n",n*2);
			continue;
		}
		ans=n;
		if(x>y)
			ans+=s(x,y);
		else if(x<y)
			ans+=s(y,x);
		for(i=0;i<=n;i++)
			if(xy*i%n==0&&(x-xy*i/n)%100==0)
					ans++;
		if(x==0||y==0)
			ans--;
		if(x==n*100||y==n*100)
			ans--;
		printf("%d\n",ans);
	}
	return 0;
}