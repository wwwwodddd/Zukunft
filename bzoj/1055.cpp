#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int f[256][256][4];
int v[256][256][4];
int l[4][16];
int r[4][16];
int w[256];
int c[4],p,o;
char s[256];
char u[8]={"WING"};
char a,b;
int F(int x,int y,int z)
{
	if(v[x][y][z])
		return f[x][y][z];
	v[x][y][z]=1;
	if(x==y)
		return f[x][y][z]=(s[x]==u[z]);
	for(int i=x;i<y;i++)
		for(int j=0;j<c[z];j++)
			if(F(x,i,l[z][j])&&F(i+1,y,r[z][j]))
				return f[x][y][z]=1;
	return f[x][y][z]=0;
}
int main()
{
	int i,j;
	w['W']=0;
	w['I']=1;
	w['N']=2;
	w['G']=3;
	for(i=0;i<4;i++)
		scanf("%d",&c[i]);
	for(i=0;i<4;i++)
		for(j=0;j<c[i];j++)
			cin>>a>>b,l[i][j]=w[a],r[i][j]=w[b];
	scanf("%s",s);
	p=strlen(s);
	for(i=0;i<4;i++)
		if(F(0,p-1,i))
			cout<<u[i],o=1;
	if(!o)
		cout<<"The name is wrong!";
	return 0;
}