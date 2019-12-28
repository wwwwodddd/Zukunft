#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
char a[6][6];
int x[44],y[44];
int b[7],ans;
int r,s;
bool islink(int i,int j,int x,int y)
{
	return (i==x&&abs(j-y)==1)||(j==y&&abs(i-x)==1);
}
void link()
{
	int q[8],end=0;
	q[++end]=0;
	bool v[44]={0};
	int i;
	while(end)
	{
		int u=q[end--];
		for(i=1;i<7;i++)
			if(!v[i]&&islink(x[b[u]],y[b[u]],x[b[i]],y[b[i]]))
				v[q[++end]=i]=1;
	}
	for(i=1;i<7;i++)
		if(!v[i])
			return;
	ans++;
	return;
}
int main()
{
	int i,j,k,l,m,n,o;
	for(i=0;i<5;i++)
		scanf("%s",a[i]);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(a[i][j]=='J')
				x[++s]=i,y[s]=j,r++;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(a[i][j]=='H')
				x[++s]=i,y[s]=j;
	for(i=1;i<=r;i++)
		for(j=i+1;j<=r;j++)
			for(k=j+1;k<=r;k++)
				for(l=k+1;l<=r;l++)
					for(m=l+1;m<=s;m++)
						for(n=m+1;n<=s;n++)
							for(o=n+1;o<=s;o++)
							{
								b[0]=i,b[1]=j,b[2]=k,b[3]=l,b[4]=m,b[5]=n,b[6]=o;
								link();
							}
	printf("%d\n",ans);
	return 0;
}
