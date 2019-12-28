#include<stdio.h>
#include<iostream>
using namespace std;
int a,b,c,d,ans;
int main()
{
	while(scanf("%d %d %d %d",&a,&b,&c,&d)&&a+b+c+d)
	{
		if(a<b)
			swap(a,b);
		if(c<d)
			swap(c,d);
		ans=min(c*100/a,d*100/b);
		printf("%d%c\n",min(ans,100),'%');
	}
	return 0;
}