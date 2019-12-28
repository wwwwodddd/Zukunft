#include<stdio.h>
#include<string.h>
#define P printf
int a[102][102],t[102][102];
char c[128];
void sc(int x,int y)
{
	if(x>y)
		return;
	if(x==y)
		if(c[x]=='('||c[x]==')')
			P("()");
		else
			P("[]");
	else
		if(t[x][y]==-1)
			if(c[x]=='(')
				P("("),sc(x+1,y-1),P(")");
			else
				P("["),sc(x+1,y-1),P("]");
		else
			sc(x,t[x][y]),sc(t[x][y]+1,y);
}
int main()
{
	int l,i,x,j,k,s,f;
	while(gets(c))
	{
		l=strlen(c);
		for(i=0;i<l;i++)
			a[i+1][i]=0,a[i][i]=1;
		for(x=1;x<l;x++)
			for(i=0;i+x<l;i++)
			{
				j=i+x;
				f=0x7fffffff;
				if(c[i]=='('&&c[j]==')'||c[i]=='['&&c[j]==']')
					f=a[i+1][j-1];
				t[i][j]=-1;
				for(k=i;k<j;k++)
				{
					s=a[i][k]+a[k+1][j];
					if(s<f)
						f=s,t[i][j]=k;
				}
				a[i][j]=f;
			}
		sc(0,l-1);
		P("\n");
	}
return 0;
}
