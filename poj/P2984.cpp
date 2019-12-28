#include<stdio.h>
#include<string.h>
char c[10020];
int a[10020],b[10020];
int z,i,j,k,l;
int u[10020];
int md()
{
	int r=0;
	for(i=a[0];i>0;i--)
	{
		a[i]+=r*10000;
		r=a[i]%2;
		a[i]/=2;
	}
	while(!a[a[0]]&&a[0])
		a[0]--;
	return r;
}
int mul(int x)
{
	int i;
	int r=0;
	for(i=1;i<=u[0];i++)
		u[i]*=x;
	for(i=1;i<=u[0];i++)
	{
		u[i+1]+=u[i]/10000;
		u[i]%=10000;
	}		
	if(u[u[0]+1])
		u[0]++;
	return r;
}

int main()
{
	scanf("%s",c);
	l=strlen(c);
	for(i=0;i<l;i++)
		a[l-i]=c[i]-'0';
	for(i=1;i<=(l-1)/4+1;i++)
		b[i]=a[4*i]*1000+a[4*i-1]*100+a[4*i-2]*10+a[4*i-3];
	b[0]=(l-1)/4+1;
	memcpy(a,b,sizeof(b));
	while(a[0])
		z+=md();
	u[0]=u[1]=1;
	for(i=0;i<z/10;i++)
		mul(1024);
	for(i=0;i<z%10;i++)
		mul(2);
	u[1]-=1;
	printf("%d",u[u[0]]);
	for(i=u[0]-1;i>0;i--)
		printf("%04d",u[i]);
	return 0;
}

