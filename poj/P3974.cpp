#include<iostream>
using namespace std;
char o[2000020],s[2000020];
int p[2000020];
int r,i,j,mx,n;
int main()
{
	int t=0;
	while(scanf("%s",o),o[0]^'E')
	{
		memset(s,'#',sizeof(s));
		n=strlen(o);
		for(i=0;i<n;i++)
			s[(i+1)*2]=o[i];
		s[n=(n+1)*2]=0;
		r=mx=0;
		for(i=0;i<n;i++)
		{
			if(mx>i)
				p[i]=min(p[2*j-i],mx-i);
			else
				p[i]=1;
			while(s[i+p[i]]==s[i-p[i]])
				p[i]++;
			r=max(r,p[i]);
			if(mx<i+p[i])
				mx=i+p[j=i];
		}
		printf("Case %d: %d\n",++t,r-1);
	}
	return 0;
}