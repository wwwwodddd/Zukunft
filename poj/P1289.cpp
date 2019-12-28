#include<iostream>
#include<math.h>
using namespace std;
long long h,n,i,j,ans;
double t,k;
int main()
{

    while(scanf("%d %d",&h,&n)&&(h||n))
    {
        for(j=1;j<32;j++)
        {
            t=pow(h,1.0/j);
            k=pow(n,1.0/j);
            if(abs(t-k-1)<1e-3)
            {
                ans=(k+0.5);
                break;
            }
		}
		if(ans!=1)
			printf("%I64d %I64d\n",(n-1)/(ans-1),ans*(h-n)+h);
    }
    return 0;
}