#include<stdio.h>
#include<algorithm>
using namespace std;
int a[50020],n;
int h[50020];
int z[50020];
int s[50020],ss;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",h+i,a+i);
		while(ss&&h[i]>h[s[ss]])
			z[i]+=a[s[ss--]];
		s[++ss]=i;
	}
	ss=0;
	for(int i=n;i>0;i--)
	{
		while(ss&&h[i]>h[s[ss]])
			z[i]+=a[s[ss--]];
		s[++ss]=i;
	}
	printf("%d\n",*max_element(z+1,z+1+n));
	return 0;
}
