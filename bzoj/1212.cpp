#include<stdio.h>
#include<string.h>
int f[2000020];
int t[20020][26],tot=1;
int d[20020];
int z,n,m;
char s[2000020];
void ins(char *s)
{
	int p=1;
	for(;*s;s++)
	{
		if(!t[p][*s-'a'])
			t[p][*s-'a']=++tot;
		p=t[p][*s-'a'];
	}
	d[p]=1;
}
void dp(int i)
{
	int p=1;
	for(;s[i];i++)
	{
		if(!t[p][s[i]-'a'])
			break;
		p=t[p][s[i]-'a'];
		if(d[p])
		{
			f[i+1]=1;
			if(i+1>z)
				z=i+1;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	for(int i=0;i<m;i++)
	{
		memset(f,0,sizeof f);
		scanf("%s",s);
		f[0]=1;
		z=0;
		for(int j=0;s[j];j++)
			if(f[j])
				dp(j);
		printf("%d\n",z);
	}
	return 0;
}
