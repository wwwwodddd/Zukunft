#include<iostream>
#include<string.h>
using namespace std; 
int f[3][2][120];;
int T[3],n,c,m,t,p;
int k[3],sum;
char s[10];
int main()
{
	while(cin>>T[0]>>T[1]>>T[2]&&(T[0]+T[1]+T[2]))
	{
		getchar();
		k[0]=k[1]=k[2]=sum=0;
		memset(f,0,sizeof(f));
		while(gets(s)&&s[0]!='#')
		{
			sscanf(s,"%d:%d %d",&c,&m,&p);
			t=60*(c-8)+m;
			n=(p-1)/2;
			if(t>=f[n][0][k[n]])
			{
				f[n][0][k[n]]=t+30;
				k[n]=(k[n]+1)%T[n];
				sum+=p;
			}
			else if(t>=f[n][1][k[n]])
			{
				f[n][1][k[n]]=f[n][0][k[n]];
				f[n][0][k[n]]+=30;
				k[n]=(k[n]+1)%T[n];
				sum+=p;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
