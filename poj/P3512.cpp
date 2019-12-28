#include<iostream>
#include<algorithm>
using namespace std;
int x[1020],y[1020],t,i,j,re,ans,n,cnt;double k[500000];char s[10000];
int main(){while(1){for(ans=n=0;gets(s)&&s[1]!='-';n++)sscanf(s,"%d %d",&x[n],&y[n]);if(n==0)break;for(i=0;i<n;i++)
{cnt=0;re=1;for(j=i+1;j<n;j++)if(i!=j)if(x[i]==x[j])k[cnt++]=0xffffff;else k[cnt++]=(y[j]-y[i]+0.0)/(x[j]-x[i]);sort(k,k+cnt);
for(j=1;j<cnt;j++){if(k[j]==k[j-1])re++;else re=1;ans=max(ans,re+1);}}printf("%d. %d\n",++t,ans);}return 0;}