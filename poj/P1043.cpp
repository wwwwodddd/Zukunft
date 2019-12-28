#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<map>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<string,int>m1,m2;
string s1[30],s2[30],o,s;
int a[30][30],v[30],l[30],z[30],n;
int dfs(int x)
{
	for(int i=0;i<n;i++)
		if(a[x][i]&&!v[i])
		{
			v[i]=1;
			if(l[i]==-1||dfs(l[i]))
				return l[i]=x,1;
		}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s1[i],m1[s1[i]]=i;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=1;
	for(;;)
	{
		cin>>o;
		if(o=="Q")
			break;
		else if(o=="E")
		{
			cin>>s;
			if(!m2.count(s))
			{
				int t=m2.size();
				m2[s]=t;
				s2[t]=s;
			}
			v[m2[s]]=1;
		}
		else if(o=="L")
			cin>>s,v[m2[s]]=0;
		else if(o=="M")
		{
			cin>>s;
			int x=m1[s];
			for(int i=0;i<n;i++)
				if(!v[i])
					a[i][x]=0;
		}
	}
	s1[n]="???";
	for(int i=0,j,k;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(a[i][j])
			{
				a[i][j]=0;
				memset(l,-1,sizeof l);
				for(k=0;k<n;k++)
				{
					memset(v,0,sizeof v);
					if(!dfs(k))
						break;
				}
				a[i][j]=1;
				if(k<n)
					break;
			}
		z[i]=j;
	}
	fe(i,m2)
		cout << i->X << ":" << s1[z[i->Y]] << endl;
	return 0;
}
