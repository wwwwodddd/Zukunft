#include"stdio.h"
char a[120][120];
void s(int x,int y)
{
if(a[x][y]=='W')
{
a[x][y]='.';
s(x,y+1);
s(x-1,y);
s(x+1,y);
s(x,y-1);
s(x-1,y+1);
s(x-1,y-1);
s(x+1,y+1);
s(x+1,y-1);
}}
int main()
{
int i,j,m,n,c=0;
scanf("%d %d",&m,&n);
for(i=1;i<=m;i++)
	scanf("%s",a[i]+1);
for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        if(a[i][j]>'0')
            {
            c++;
            s(i,j);
            }
printf("%d",c);
return 0;
}