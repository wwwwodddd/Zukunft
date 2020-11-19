#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[6];
int t[105];
int w[105];
int main()
{
	int n,x,y,z;
	for(;scanf("%d",&n),n>=0;)
	{
		fr(i,6)
			a[i].clear();
		fr(i,n)
			scanf("%d %d:%d:%d",w+i,&x,&y,&z),a[w[i]].push_back(t[i]=x*3600+y*60+z);
		fr(i,6)
			sort(a[i].begin(),a[i].end());
		fr(i,n)
		{
			if(w[i]==5)
				puts("100");
			else if(w[i]==4)
				puts(t[i]<a[4][a[4].size()/2]?"95":"90");
			else if(w[i]==3)
				puts(t[i]<a[3][a[3].size()/2]?"85":"80");
			else if(w[i]==2)
				puts(t[i]<a[2][a[2].size()/2]?"75":"70");
			else if(w[i]==1)
				puts(t[i]<a[1][a[1].size()/2]?"65":"60");
			else if(w[i]==0)
				puts("50");
		}
		puts("");
	}
}
