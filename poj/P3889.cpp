#include<stdio.h>
#include<math.h>
typedef long long ll;
ll n,i,j,px,py,qx,qy,n1,n2,cases,b[70];
void S(ll n,ll z,ll &x,ll &y){if(n==0){x=y=0;return;}
ll next=z%b[2*n-2];ll dx,dy;S(n-1,next,dx,dy);
ll dir=(z/b[2*n-2])%4;if(dir==0){x=dy;y=dx;}
else if(dir==1){x=b[n-1]+dx;y=dy;}else if(dir==2){x=b[n-1]+dx;y=b[n-1]+dy;}
else if(dir==3){x=b[n-1]-dy-1;y=b[n]-dx-1;}return;}
double sqr(ll x){return (double)x*x;}int main(){scanf("%I64d",&cases);
b[0]=1;for(i=1;i<=63;i++)b[i]=b[i-1]*2;while(cases--){scanf("%I64d",&n);
scanf("%I64d %I64d",&n1,&n2);n1--;n2--;S(n,n1,px,py);S(n,n2,qx,qy);
printf("%.0f\n",10*sqrt(sqr(px-qx)+sqr(py-qy)));}return 0;}
