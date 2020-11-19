#include<stdio.h>
typedef long long ll;
int w[100020];
ll a[100020];
ll b[100020];
char s[9];
int n,m,x,y;
void R(ll *a,int x,ll y)
{
	for(;x<=n;x+=x&-x)
		a[x]+=y;
}
ll G(ll *a,ll x)
{
	ll re=0;
	for(;x;x-=x&-x)
		re+=a[x];
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i),a[i]=w[i],b[i]=a[i]*i;
	for(int i=1;i<=n;i++)
		if(i+(i&-i)<=n)
		{
			a[i+(i&-i)]+=a[i];
			b[i+(i&-i)]+=b[i];
		}
	for(int i=0;i<m;i++)
	{
		scanf("%s%d",s,&x);
		if(*s=='Q')
		{
			printf("%lld\n",(x+1)*G(a,x)-G(b,x));
		}
		else
		{
			scanf("%d",&y);
			R(a,x,y-w[x]);
			R(b,x,(ll)x*(y-w[x]));
			w[x]=y;
		}
	}
}
