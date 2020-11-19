#include<stdio.h>
struct N{
	long long x;
	int y;
	N(){
	}
	N(long long x,int y):x(x),y(y){
	}
}f[19][170][1002],ans;
int v[19][170][1002];
int n,m;
N operator+(const N&a,const N&b){
	return N(a.x+b.x,b.y);
}
N F(int x,int y,int z){
	if(v[x][y][z])
		return f[x][y][z];
	v[x][y][z]=1;
	if(x==0){
		if(y+z>=m)
			return f[x][y][z]=N(1,0);
		else
			return f[x][y][z]=N(0,y+z);
	}
	f[x][y][z].y=z;
	for(int i=0;i<10;i++)
		f[x][y][z]=f[x][y][z]+F(x-1,y+i,f[x][y][z].y);
	return f[x][y][z];
}
int main(){
	long long l,r,s,q;
	int x,t;
	scanf("%lld%lld%d",&l,&r,&m);
	while(l<=r){
		s=1,x=0;
		while(l%(s*10)==0&&l+10*s<=r+1)
			s*=10,x++;
		t=0;
		for(q=l;q;q/=10)
			t+=q%10;
		ans=ans+F(x,t,ans.y);
		l+=s;
	}
	printf("%lld",ans.x);
}
