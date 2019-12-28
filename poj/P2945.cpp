#include<iostream>
#include<algorithm>
using namespace std;
long long f[20020];
int ans[20020],i,j,l,n,m;
int w[300];
char s[40];
int main()
{
	w['A']=0;
	w['T']=1;
	w['C']=2;
	w['G']=3;
	while(scanf("%d%d",&n,&m),n+m)
	{
		for(i=0;i<n;i++)
		{
			f[i]=0;
			scanf("%s",s);
			for(j=0;s[j];j++)
				f[i]=(f[i]<<2)|w[s[j]];
		}
		sort(f,f+n);
		memset(ans,0,sizeof(ans));
		l=1;
		for(i=1;i<n;i++)
			if(f[i]!=f[i-1])
			{
				ans[l]++;
				l = 1;
			}
			else
				l++;
		ans[l]++;
		for(i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
