#include<stdio.h>
#include<math.h>
double n,k,z;
int main()
{
	for(;~scanf("%lf%lf",&n,&k);)
	{
		z=0;
		if(n<1000)
			for(int i=1;i<=n;i++)
				z+=log((double)i);
		else
			z=0.91893853320467274178+log(sqrt(n))+n*log(n)-n;
		z/=log(k),z+=1e-9;
        printf("%lld\n",(long long)z+1);
	}
    return 0;
}
