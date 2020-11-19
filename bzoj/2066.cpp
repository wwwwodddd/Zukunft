#include<stdio.h>
int inf=0x3fffffff;
int i,j,k,m,n,c,x,z;
int b[3000020],a[3000020];
void nw(int k)
{
	if(c&1)
		x^=b[c];
	c+=k;
	b[c]=1;
}
int main()
{
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	k=m-1;
	a[n+1]=m-1;
	while(a[n]==k)
	{
		n--;
		k--;
		z++;
	}
	if(z)
	{
		printf("%d",z);
		return 0;
	}
	for(i=n;i>0;i--)
	{
		if(a[i+1]-a[i]==1)
			b[c]++;
		else if(a[i+1]-a[i]==2)
			nw(1);
		else if((a[i+1]-a[i])&1)
			nw(2);
		else
			nw(3);
	}
	if(c&1)
		x^=b[c];
	if(x==0)
		z=0;
	else
		for(i=1;i<=c;i++)
			if((i&1)&&((x^b[i])<b[i])||(!(i&1))&&(b[i-1]<(x^b[i-1]))&&(b[i-1]+b[i]>=(x^b[i-1])))
				z++;
	printf("%d",z);
	return 0;
}