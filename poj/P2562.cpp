#include<stdio.h>
#include<string.h>
char a[120],b[120];
int c[120],d[120],s[120],k,la,lb,x;
int main()
{
while(scanf("%s %s",a,b)&&(a[0]!='0'||b[0]!='0'))
{
x=0;
la=strlen(a);
lb=strlen(b);
for(k=la;k>0;k--)
    c[la-k]=a[k-1]-'0';
for(k=lb;k>0;k--)
    d[lb-k]=b[k-1]-'0';
for(k=0;k<110;k++)
    s[k]=c[k]+d[k];
for(k=0;k<110;k++)  
    if(s[k]>9)
    {
	x++;
    s[k]-=10;
    s[k+1]+=1;
    }
if(x==0)
	printf("No carry operation.\n");
else if(x==1)
	printf("1 carry operation.\n");
else
	printf("%d carry operations.\n",x);
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(c,0,sizeof(c));
memset(d,0,sizeof(d));
memset(s,0,sizeof(s));
}
return 0;
}
