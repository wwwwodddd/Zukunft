#include<stdio.h>
typedef long long ll;
ll x,y,t;
int i,f,n;
ll u,m,v,r,d,c;
ll egcd(ll a,ll b)
{
if(b==0)
{
x=1;
y=0;
return a;
}
else
{
ll e=egcd(b,a%b);
t=x;
x=y;
y=t-a/b*y;
return e;
}
}
int main()
{
while(scanf("%d",&n)+1)
{
f=0;
u=1;
v=0;
for(i=0;i<n;i++)
{
scanf("%I64d%I64d",&m,&r);
d=egcd(u,m);
c=r-v;
if(c%d)
break;
t=m/d;
x=(c/d*x%t+t)%t;
v=u*x+v;
u=u*m/d;
}
if(i!=n)
puts("-1");
else
printf("%I64d\n",v);
for(;i<n;i++)
scanf("%I64d%I64d",&m,&r);
}
return 0;
}
