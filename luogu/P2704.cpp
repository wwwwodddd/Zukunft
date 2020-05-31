#include<iostream>
using namespace std;
int f[103][61][61],g[103],s[61],a[61],n,m,ss;
// int F(int x,int y,int z)
// {
//     if(f[x][y][z]!=-1)
//         return f[x][y][z];
//     if(x==1)
//     {
//         if (z == 0)
//         {
//             return f[x][y][z]=a[y];
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     for(int i=0;i<k;i++)
//         if(!(s[i]&(s[y]|s[z])||g[x-2]&s[i]))
//             f[x][y][z]=max(f[x][y][z],F(x-1,z,i));
//     f[x][y][z]+=a[y];
//     return f[x][y][z];
// }
char c[20];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        for(int j=0;j<m;j++)
            if(c[j]=='H')
                g[i]+=1<<j;
    }
    for(int i=0;i<1<<m;i++)
        if(!((i<<1)&i)&&!((i<<2)&i))
        {
            a[ss]=__builtin_popcount(i);
            s[ss++]=i;
        }
    for (int i = 1; i <= n + 2; i++)
    {
        for (int j = 0; j < ss; j++)
        {
            for (int k = 0; k < ss; k++)
            {
                for (int l = 0; l < ss; l++)
                {
                    if ((s[j] & s[k]) == 0 && (s[j] & s[l]) == 0 && (s[j] & g[i]) == 0)
                    {
                        f[i][j][k] = max(f[i][j][k], f[i-1][k][l] + a[j]);
                    }
                }
            }
        }
    }
    printf("%d\n",f[n + 2][0][0]);
    return 0;
}