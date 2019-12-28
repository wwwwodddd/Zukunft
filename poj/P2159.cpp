#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char x;
char ca[120],cb[120];
int a[26],b[26],l,ans;
int cmp(const void *b,const void *a)
{
return *(int*)a-*(int*)b;
}
int main()
{
int i,j;
scanf("%s",ca);
scanf("%s",cb);
l=strlen(ca);
for(i=0;i<l;i++)
{
a[ca[i]-'A']++;
b[cb[i]-'A']++;
}
qsort(a,26,4,cmp);
qsort(b,26,4,cmp);
l=0;
for(i=0;i<26;i++)
	if(a[i]!=b[i])
		{
		printf("NO");
		l=1;
		break;
		}
if(l==1)
return 0;
printf("YES");
return 0;
}