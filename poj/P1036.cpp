#include<iostream>
using namespace std;
struct Edge{int s,p,n;}e[110];
int p[110],dp[2][110],cm[110],s[110];
int net[30005];
int c,N,T,K,in;
void add(int u,int st,int pr)
{
    e[in].s=st;
    e[in].p=pr;
    e[in].n=net[u];
    net[u]=in;
   ++in;
}
int get_p(int tim,int s)
{
    int sum=0;
    for(int i=net[tim];i!=-1;i=e[i].n)
        if(e[i].s ==s)
            sum+=e[i].p;
    return sum;
}
int input()
{
    c=0;
    in=0;
	memset(net,-1,sizeof(net));
	memset(dp,0,sizeof(dp));
    int i;
    for(i=0;i<N;i++)
		cin >> cm[i];
    for(i=0;i<N;i++)
        cin >> p[i];
    for(i=0;i<N;i++)
        cin >> s[i];
    for(i=0;i<N;i++)
        add(cm[i],s[i],p[i]);
    return 0;
}
int _dp()
{
    int i,j,t,d;
    for(i=1;i<=T;i++)
    {
        d=min(i,K);
        dp[c][0]=max(dp[1-c][0],dp[1-c][1]);
        dp[c][d]=max(dp[1-c][d],dp[1-c][d-1])+get_p(i,d);
        for(j=1;j<d;j++)
            dp[c][j]=max(max(dp[1-c][j-1],dp[1-c][j]),dp[1-c][j+1])+get_p(i,j);
        memcpy(dp[1-c],dp[c],sizeof(cm));
        c=1-c;
    }
    return 0;
}
void work()
{
    int i,t=0;
    _dp();
    for(i=0;i<=K;i++)
        t=max(t,dp[c][i]);
    cout << t << endl;
    return;
}
int main()
{
	scanf("%d %d %d",&N,&K,&T);
	input();
	work();
    return 0;
}
