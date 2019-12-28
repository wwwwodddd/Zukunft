#include <iostream>
using namespace std;
int mx,t,i,n,x,y;
char c,s[1020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mx=0;
		memset(s,'A'-1,sizeof(s));
		while (n--)
		{
			scanf("%s %d %d",&c,&x,&y);
			if(mx<y)
				mx=y;
			for(i=x;i<y;i++)
				s[i]++;
		}
		for(i=0;i<mx;i++)
			if(s[i]>='A')
				putchar(s[i]);
		printf("\n");
	}
	return 0;
}
