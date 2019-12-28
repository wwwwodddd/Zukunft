#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int f[105][105],d[105][105];
string s,t;
int n,i,j,k,len,fold;
int cal(int x)
{
	if(x<10)
		return 1;
	if(x<100)
		return 2;
	return 3;
}
string x(int y)
{
	char c[5];
	sprintf(c,"%d",y);
	return c;
}
string print(int l,int r)
{
	int i,k;
	string c;
	k=d[l][r];
	if(k==0)
		c+=s.substr(l,r-l+1);
	else if(k>0)
		c+=print(l,k)+print(k+1,r);
	else
		c+=x((r-l+1)/(-k-l+1))+"("+print(l,-k)+")";
	return c;
}
int main()
{
	cin >> s;
	n=s.length();
	s="$"+s;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			f[i][j]=j-i+1;
	for(len=1;len<=n;len++)
		for(i=1;i<=n-len+1;i++)
		{
			j=i+len-1;
			t=s.substr(i,len);
			for(k=i;k<j;k++)
				if(f[i][j]>f[i][k]+f[k+1][j])
				{
					f[i][j]=f[i][k]+f[k+1][j];
					d[i][j]=k;
				}
			k=j+1;
			fold=0;
			while(k<=n-len+1)
			if(t==s.substr(k,len))
			{
				fold++;
				k+=len;
				if(f[i][k-1]>f[i][j]+cal(fold)+2)
				{
					f[i][k-1]=f[i][j]+cal(fold)+2;
					d[i][k-1]=-j;
				}
			}
			else break;
		}
	cout << print(1,n);
	printf("\n");
}
