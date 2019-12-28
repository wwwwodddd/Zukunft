#include<stdio.h>
#include<math.h>
#include<string.h>
int n,a[20][2]={0},i,j=0,k,m,d,x=1;
int main()
{
scanf("%d",&d);
while(d--)
{
j=0;
m=1;
memset(a,0,sizeof(a));
scanf("%d",&n);
for(i=2;i<=n;i++)
    {
    if(i>sqrt((double)n))
    {
    a[j][0]=n;
    a[j][1]=1;
    j++;
    break;
    }
    if(n%i==0)
        {
        while(n%i==0)
            {
            n/=i;
            a[j][1]++;
            }
        a[j][0]=i;
        j++;
        }
    }
for(j--;j>=0;j--)
	m*=(a[j][1]*2+1);
printf("Scenario #%d:\n",x++);
printf("%d\n\n",(m+1)/2);
}
return 0;
}