#include<stdio.h>
char a[30],c;
int main()
{
int i,j;
scanf("%s",a);
getchar();
while((c=getchar())!=EOF)
	if(c>='a'&&c<='z')
	printf("%c",a[c-'a']);
	else if(c>='A'&&c<='Z')
	printf("%c",a[c-'A']-'a'+'A');
	else
	printf("%c",c);
printf("\n");
return 0;
}