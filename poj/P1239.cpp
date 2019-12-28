#include<stdio.h>
#include<string.h>
char s[100];
int f[100],c[100];
int i,j,k,l,x;
int cmp(int a,int b,int c,int d)
{
	while(s[a]=='0'&&a<b)
		a++;
	while(s[c]=='0'&&c<d)
		c++;
	if(d-c>b-a)
		return 1;
	else if(d-c<b-a)
		return 0;
	int x=b-a;
	for(int i=0;i<=x;i++)
		if(s[a+i]<s[c+i])
			return 1;
		else if(s[a+i]>s[c+i])
			return 0;
	return 0;
}
void print(int x,int y)
{
	for(int i=x;i<=y;i++)
		printf("%c",s[i]);
}
int main()
{
	while(scanf("%s",s+1)+1)
	{
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		l=strlen(s+1);
		s[0]='0';
		if(s[1]=='0'&&l==1)
			return 0;
		for(i=1;i<=l;i++)
			f[i]=1;
		for(i=1;i<=l;i++)
			for(j=i-1;j>=0;j--)
				if(cmp(f[j],j,j+1,i)&&cmp(j+1,i,f[i],i))
					f[i]=j+1;
		for(i=1;i<f[l];i++)
			c[i]=i;
		c[f[l]]=l;
		for(i=f[l]-1;i>0;i--)
		{
			if(s[i]=='0')
				c[i]=c[i+1];
			else
				for(j=i;j<=f[l];j++)
					if(cmp(i,j,j+1,c[j+1])&&cmp(i,c[i],i,j))
						c[i]=j;
		}
		x=1;
		while(c[x]!=l)
		{
			print(x,c[x]);
			printf(",");
			x=c[x]+1;
		}
		print(x,l);
		printf("\n");
	}
}