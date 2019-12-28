#include<iostream>
using namespace std;
int n,k,p1,p2,w[120],l[120],i;
char c1[20],c2[20];
int cmp(char *c1,char *c2)
{
	if(c1[0]==c2[0])
		return 0;
	else if(c1[0]=='r'&&c2[0]=='s'||c1[0]=='s'&&c2[0]=='p'||c1[0]=='p'&&c2[0]=='r')
		return 1;
	else
		return -1;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&k);
		for(i=1;i<=n;i++)
			w[i]=l[i]=0;
		k*=n*(n-1)/2;
		while(k--)
		{
			scanf("%d%s%d%s",&p1,&c1,&p2,&c2);
			if(cmp(c1,c2)==1)
			{
				w[p1]++;
				l[p2]++;
			}
			else if(cmp(c1,c2)==-1)
			{
				w[p2]++;
				l[p1]++;
			}
		}
		for(i=1;i<=n;i++)
			if(l[i]+w[i])
				printf("%.3lf\n",1.*w[i]/(w[i]+l[i]));
			else
				printf("-\n");
		printf("\n");
	}
}