#include<stdio.h>
#include<string.h>
int f[5];
char s[100];
char c[100];
int g,h,i,j,k,l;
int C(char x)
{
	if(x>='a'&&x<='i')
		return 0;
	if(x>='j'&&x<='r')
		return 1;
	return 2;
}
int G(int a)
{
	g=C(s[a]);
	j=a;
	h=f[g];
	while(h--)
	{
		j++;
		while(C(s[j%l])!=g)
			j++;
	}
	return j%l;
}
int main()
{
	while(scanf("%d %d %d",&f[0],&f[1],&f[2]),f[0]+f[1]+f[2])
	{
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
			c[G(i)]=s[i];
		c[l]='\0';
		printf("%s\n",c);
	}
	return 0;
}

