#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int m,n;
string s[110];
int a[110][2];
int i,j,k;
int f()
{
	int x=0;
	for(j=0;j<n;j++)
		for(k=j+1;k<n;k++)
			if(s[i][j]>s[i][k])
				x++;
	return x;
}
int cmp(const void *a,const void *b)
{
return *(int *)a-*(int *)b;
}
int main()
{
cin >> n >> m;
for(i=1;i<=m;i++)
{
	cin >> s[i];
	a[i][0]=f();
	a[i][1]=i;
}
qsort(a+1,m,8,cmp);
for(i=1;i<=m;i++)
	cout << s[a[i][1]] << endl;
return 0;
}