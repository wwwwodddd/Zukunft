#include<iostream>
using namespace std;
char c[620][30];
char s[320];
int f[320];
int n,m,i,j,k,l;
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(i=0;i<n;i++)
		scanf("%s",c[i]);
	for(i=m-1;i>=0;i--)
	{
		f[i]=301;
		for(j=0;j<n;j++)
		{
			for(k=0,l=i;c[j][k]&&l<m;l++)
				if(c[j][k]==s[l])
					k++;
			if(!c[j][k])
				f[i]=min(min(f[i],f[i+1]+1),f[l]+l-i-k);
			else
				f[i]=min(f[i],f[i+1]+1);
		}
	}
	printf("%d",f[0]);
	return 0;
}
