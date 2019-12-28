#include<stdio.h>
#include<string.h>
char a[100020],b[100020];
int main()
{
int i,j,la,lb;
while(scanf("%s %s",a,b)!=EOF)
{
i=j=0;
la=strlen(a);
lb=strlen(b);
for(;j<lb;j++)
	if(b[j]==a[i])
		{
		i++;
		if(i==la)
			break;
		}
if(i==la)
	printf("Yes\n");
else
	printf("No\n");
}
return 0;
}