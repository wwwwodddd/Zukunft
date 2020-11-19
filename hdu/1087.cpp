#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[1020],f[1020];
int main()
{
	while(cin>>n,n)
	{
		fill_n(f,n+1,0);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<i;j++)
				if(a[j]<a[i])
					f[i]=max(f[i],f[j]+a[i]);
		cout<<*max_element(f,f+n+1)<<endl;
	}
}
