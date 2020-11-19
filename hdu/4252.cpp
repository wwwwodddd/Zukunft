#include<stdio.h>
int s[100020],ss,n,z,x,t;
void P(int x)
{
	while(x<s[ss])
		ss--,z++;
	if(x>s[ss])
		s[++ss]=x;	
}
int main()
{
	while(~scanf("%d",&n))
	{
		ss=z=0;
		for(int i=0;i<n;i++)
			scanf("%d",&x),P(x);
		P(0);
		printf("Case %d: %d\n",++t,z);
	}
	return 0;
}
