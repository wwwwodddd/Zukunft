#include <iostream>
using namespace std;
char c[10000][16];
int a[10000];
int i,j,k;
char s[16];
bool differ(char *a, char *b, int pos)
{
	int judge=0;
	int i=0,j=0;
	int sizea=strlen(a);
	int sizeb=strlen(b);
	if(sizea==sizeb)
	{
		int found=0;
		int i;
		for(i=0;i<sizea;i++)
			if(a[i]!=b[i])
			{
				if(found==0)
					found=1;
				else
					return 0;
			}
		return 1;
	}
	else if(sizea==sizeb+1)
	{
		while(judge!=2&&j<sizeb)
		{
			if(a[i]!=b[j])
			{
				i++;
				judge++;
				continue;
			}
			i++;
			j++;
		}
		if(judge==2)
			return 0;
		else
			return 1;
	}
	else if (sizea+1==sizeb)
	{
		while(judge!=2&&i<sizea)
		{
			if(a[i]!=b[j])
			{
				j++;
				judge++;
				continue;
			}
			i++;
			j++;
		}
		if(judge == 2)
			return 0;
		else
			return 1;
		}
	return 0;
}
int main()
{
	while(scanf("%s",c[i])&&c[i][0]!='#')
		i++;
	while(scanf("%s", s)&&s[0]!='#')
	{
		k=0;
		for(j=0;j<i;j++)
		{
			if(strcmp(s,c[j])==0)
			{
				printf("%s is correct\n",s);
				break;
			}
			if(differ(s,c[j],j))
				a[k++]=j;
		}
		if(j==i)
		{
			printf("%s:",s);
			for(j=0;j< k;j++)
				printf(" %s",c[a[j]]);
			printf("\n");
		}
	}
	return 0;
}
