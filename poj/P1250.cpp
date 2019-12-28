#include<iostream>
using namespace std;
int n,i,x,ans,l,z;
char s[100];
int v[30];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(v,0,sizeof(v));
		scanf("%s",s);
		ans=0;
		z=0;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			x=s[i]-'A';
			if(!v[x])
			{
				v[x]=1;
				z++;
				if(z>n)
					ans++;
			}
			else
			{
				z--;
				v[x]=0;
			}
		}
		if(ans==0)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n",ans);
	}
	return 0;
}