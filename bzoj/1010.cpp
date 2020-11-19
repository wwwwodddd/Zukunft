#include<stdio.h>
#include<iostream>
#include<stdlib.h>
int b,f,n,l;
int q[500020]; 
long long g[500020];
long long s[500020];
template<typename T>inline T sqr(T x)
{
	return x*x;
}
int main()
{
	freopen("c.in","r",stdin);
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];
    }
	for(int i=1;i<=n;i++)
	{
		while(b<f&&((sqr(s[q[b+1]]+q[b+1])+g[q[b+1]])-(sqr(s[q[b]]+q[b])+g[q[b]])<=2*(s[i]+i-1-l)*(s[q[b+1]]+q[b+1]-s[q[b]]-q[b])))
			b++;
		g[i]=g[q[b]]+sqr(s[i]-s[q[b]]+i-q[b]-1-l);
		while(b<f&&((sqr(s[i]+i)+g[i])-(sqr(s[q[f]]+q[f])+g[q[f]]))*((s[i]+i)-(s[q[f]]+q[f]))>=((sqr(s[i]+i)+g[i])-(sqr(s[q[f-1]]+q[f-1])+g[q[f-1]]))*((s[i]+i)-(s[q[f-1]]+q[f-1])))
			f--;
		q[++f]=i;
	}
	printf("%lld\n",g[n]);
	while(1);
    return 0;
}
