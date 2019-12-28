#include<stdio.h>
#include<string.h>
int s[10020],n,m,r,z[10020][2];
int k,u,p,q,i,x,v;
int main()
{
	scanf("%d%d",&n,&m);
	for(k=1;k<=10000;k++)
	{
		x=n;
		u=m;
		p=0;
		q=k-1;
		while(u>0)
		{
			u--;
			i=(p+q)/2;
			if(i==x&&u>0)
				break;
			if(i==x&&u==0)
			{
				s[k]=1;
				v=k;
				break;
			}
			if(n<i)
			q=i-1;
			else
			p=i+1;
		}
	}
	for(i=1;i<=v;)
	{
		if(s[i]==1)
		{
			r++;
			z[r][0]=i;
			while(s[i]==1)
				i++;
			z[r][1]=i-1;
		}
		else
			i++;
	}
	printf("%d\n",r);
	for(i=1;i<=r;i++)
		printf("%d %d\n",z[i][0],z[i][1]);
	return 0;
}