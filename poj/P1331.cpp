#include<iostream>
using namespace std;
char p[8],q[8],r[8];
int ans,mx,n;
int i,j,k;
int T(char *p, int b)
{
	int re=0;
	for(int i=0;p[i];i++)
		re=re*b+p[i]-'0';
	return re;
}
int Q(char *p,char *q,char *r)
{
	int mx=0,i;
	for(i=0;p[i];i++)
		if(mx<p[i]-'0')
			mx=p[i]-'0';
	for(i=0;q[i];i++)
		if(mx<q[i]-'0')
			mx=q[i]-'0';
	for(i=0;r[i];i++)
		if(mx<r[i]-'0')
			mx=r[i]-'0';
	return mx;
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>p>>q>>r;
		ans=0;
		mx=Q(p,q,r);
		for(i=mx+1;i<=16;i++)
			if(T(p,i)*T(q,i)==T(r,i))
			{
				ans=i;
				break;
			}
		cout<<ans<<endl;
	}
	return 0;
}