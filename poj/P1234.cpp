#include<stdio.h>
#include<string.h>
#define L(x) ((x+n-1)%n)
#define R(x) ((x+1)%n)
int cnt;
char c[40];
int v[40];
int p,t,n,i,tk,k;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		p=0;
		scanf("%d",&k);
		k--;
		for(i=0;i<n;i++)
			scanf("%s",c+i);
		memset(v,0,sizeof(v));
		for(t=cnt=0;cnt<n;t++)
		{
			if(!v[k])
				cnt++;
			v[k]=1;
			if(c[k]=='L')
			{
				c[k]='R';
				if(p==R(k))
				{
					p=k;
					k=L(k);
				}
				else
				{
					tk=k;
					k=L(p);
					p=tk;
				}
			}
			else
			{
				c[k]='L';
				if(p==L(k))
				{
					p=k;
					k=R(k);
				}
				else
				{
					tk=k;
					k=R(p);
					p=tk;
				}
			}
		}
		printf("Classmate %d got the ball last after %d tosses.\n",p+1,t);
	}
	return 0;
}
