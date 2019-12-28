#include<iostream>
#include<algorithm>
using namespace std;
int t,n,i,j,k,a[30],b[30];
char o[4],w[256];
int G(char s)
{
	if(s>='0'&&s<='9')
		return (s-'2')*4;
	return w[s];
}
void scan(int *a)
{
	for(i=0;i<n;i++)
	{
		scanf("%s",o);
		a[i]=G(o[0])+G(o[1]);
	}
	return;
}
int main()
{
	w['H']=3;
	w['S']=2;
	w['D']=1;
	w['C']=0;
	w['T']=32;
	w['J']=36;
	w['Q']=40;
	w['K']=44;
	w['A']=48;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scan(a);
		scan(b);
		sort(a,a+n);
		sort(b,b+n);
		for(k=i=j=0;i<n;i++)
			if(b[i]>a[j])
				j++,k++;
		printf("%d\n",k);
	}
	return 0;
}