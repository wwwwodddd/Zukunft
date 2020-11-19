#include<stdio.h>
#include<algorithm>
int main()
{
	for(int p,q;~scanf("%d%d",&p,&q);)
		printf("%d\n",p+q-std::__gcd(p,q));
	return 0;
}
