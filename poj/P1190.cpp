#include<stdio.h>
#include<math.h>
int r[22],h[22],v,ans=2147483647,l,c,f[22],d[102][102][21],time;
int m;
int min(int a,int b)
{
return a<b?a:b;
}
int sqrt(int x)
{
return (int)sqrt((float)x);
}
void dfs(int n)
{
int i,j,k=0;
if(n==l&&v!=0||c>ans)
	return;
else if(n==l)
    {
    ans=min(c,ans);
    return;
	}
else
for(i=min(sqrt(v),r[n-1]-1);i>=l-n;i--)
    {
       for(j=min(v/(i*i),h[n-1]-1);j>=l-n;j--)
        if(v>=(i*i*j+f[l-n-1])&&(v<=d[i][j][l-n]))
        {
        v-=(i*i*j);
        r[n]=i;
        h[n]=j;
		c+=2*h[n]*r[n];
        dfs(n+1);
        c-=2*h[n]*r[n];
		r[n]=0;
        h[n]=0;
        v+=(i*i*j);
        }
    }
return;
}
int main()
{
int i,j,k;
scanf("%d %d",&m,&l);
v=m;
for(i=1;i<=l;i++)
	f[i]=f[i-1]+i*i*i;
for(i=1;i<=100;i++)
	for(j=1;j<=100;j++)
		for(k=1;k<=i&&k<=j;k++)
			d[i][j][k]=d[i][j][k-1]+(i-k+1)*(i-k+1)*(j-k+1);
for(i=sqrt(m);i>0;i--)
{
r[0]=i;
c+=i*i;
for(j=m/(i*i);j>0;j--)
    {
    v-=(i*i*j);
    h[0]=j;
	c+=2*r[0]*h[0];
    dfs(1);
    c-=2*r[0]*h[0];
	h[0]=0;
    v+=(i*i*j);
    }
c-=i*i;
}
printf("%d",ans==2147483647?0:ans);
return 0;
}
