#include<stdio.h>
#include<string.h>
int n,i,j,p,ans;
struct LOG
{
char d[25],n[20],s[2];
}P[1020];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		strcpy(P[0].d,"23:00:00:00");
		for(i=1;i<=n;i++)
			scanf("%s%s%s",P[i].d,P[i].n,P[i].s);
		i=1;
		while(P[i].s[0]=='-')
			ans++,i++;
		strcpy(P[n+1].d,"00:00:00:00");
		for(p=i,i++;i<=n;i++)
			if(P[i].s[0]=='+')
				p=i;
			else if(strcmp(P[i].d,P[p].d)>0&&(strcmp(P[i+1].d,P[i].d)>0||strcmp(P[i+1].d,P[p].d)<=0))
				ans++;
			else if(strcmp(P[i].d,P[p].d)<0&&strcmp(P[i+1].d,P[p].d)<=0&&strcmp(P[i].d,P[i+1].d)<0)
				ans++;
			else
				p=i;
		printf("%d\n",n-ans);
	}
	return 0;
}