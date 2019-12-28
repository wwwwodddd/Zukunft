#include<iostream>
#define F(x,z) for(x=0;x<z;x++)
using namespace std;
int K,C,M,n,m,u,g[250][250],a[205][700],v[700],l[700];
int dfs(int x){int i;F(i,m)if(a[x][i]&&v[i]==0){v[i]=1;if(l[i]==-1||dfs(l[i])){l[i]=x;return 1;}}return 0;}
int can(int z){int i,j,k;F(i,C)F(j,K)F(k,M)a[i][j+k*K]=g[K+i][j]<=z;memset(l,-1,sizeof(l));F(i,n){memset(v,0,sizeof(v));if(!dfs(i))return 0;}return 1;}
int main(){int i,j,k;while(scanf("%d%d%d",&K,&C,&M)+1){u=K+C;F(i,u)F(j,u){scanf("%d",&g[i][j]);if(g[i][j]==0)g[i][j]=0xfffffff;}n=C;m=M*K;F(k,u)F(i,u)F(j,u)if(g[i][j]>g[i][k]+g[k][j])g[i][j]=g[i][k]+g[k][j];int l=1,r=20000;while(l<r)if(can((l+r)/2))r=(l+r)/2;else l=(l+r)/2+1;printf("%d\n",l);}}