#include <stdio.h>
#include <math.h>
#include<iostream>
int map[9][9];
int rx[5], ry[5], rt[5], bk1, bk2;

int vali (int x)
{
    if (x >= -4 && x <= 4) return 1;
    else return 0;
}

void radix (int *row, int y, int t, int rec)
{
    int i, phi, tm, x, dir;
    int u1, u2, d1, d2;
    phi = (t - rt[rec]) - abs(y - ry[rec]);
    if (rx[rec] < bk1)
    {
       u1 = rx[rec] - phi;
       u2 = rx[rec] + phi;
       d1 = rx[rec] - phi + 2;
       d2 = rx[rec] + phi - 2;
       if (u2 >= bk1) u2 = bk1 + bk1 - 1 - u2;
       if (d2 >= bk1) d2 = bk1 + bk1 - 1 - d2;
       if (phi >= 0 && vali(u1)) row[u1 + 4]++;
       if (phi >= 1 && vali(u2)) row[u2 + 4]++;
       if (phi >= 2 && vali(d1)) row[d1 + 4]--;
       if (phi >= 3 && vali(d2)) row[d2 + 4]--;
       return;
    }
    else if (rx[rec] > bk2)
    {
       u1 = rx[rec] - phi;
       u2 = rx[rec] + phi;
       d1 = rx[rec] - phi + 2;
       d2 = rx[rec] + phi - 2;
       if (u1 <= bk2) u1 = bk2 + bk2 + 1 - u1;
       if (d1 <= bk2) d1 = bk2 + bk2 + 1 - d1;
       if (phi >= 0 && vali(u1)) row[u1 + 4]++;
       if (phi >= 1 && vali(u2)) row[u2 + 4]++;
       if (phi >= 2 && vali(d1)) row[d1 + 4]--;
       if (phi >= 3 && vali(d2)) row[d2 + 4]--;
       return;
    }
    else
    {
       u1 = rx[rec] - phi;
       u2 = rx[rec] + phi;
       d1 = rx[rec] - phi + 2;
       d2 = rx[rec] + phi - 2;
       while (1)
       {
             if (u1 <= bk1) u1 = bk1 + bk1 + 1 - u1;
             else break;
             if (u1 >= bk2) u1 = bk2 + bk2 - 1 - u1;
             else break;
       }
       while (1)
       {
             if (d1 <= bk1) d1 = bk1 + bk1 + 1 - d1;
             else break;
             if (d1 >= bk2) d1 = bk2 + bk2 - 1 - d1;
             else break;
       }
       while (1)
       {
             if (u2 >= bk2) u2 = bk2 + bk2 - 1 - u2;
             else break;
             if (u2 <= bk1) u2 = bk1 + bk1 + 1 - u2;
             else break;
       }
       while (1)
       {
             if (d2 >= bk2) d2 = bk2 + bk2 - 1 - d2;
             else break;
             if (d2 <= bk1) d2 = bk1 + bk1 + 1 - d2;
             else break;
       }
       if (phi >= 0 && vali(u1)) row[u1 + 4]++;
       if (phi >= 1 && vali(u2)) row[u2 + 4]++;
       if (phi >= 2 && vali(d1)) row[d1 + 4]--;
       if (phi >= 3 && vali(d2)) row[d2 + 4]--;
       return;
    }
}

int main ()
{
    int p, time, t, i, j;
    scanf("%d %d %d %d", &p, &bk1, &bk2, &time);
    if (bk1 > bk2) { t = bk1; bk1 = bk2; bk2 = t; }
    for (i = 0; i < p; i++)
        scanf("%d %d %d", &rx[i], &ry[i], &rt[i]);
    memset(map, 0, sizeof(map));
    for (i = 0; i < p; i++)
    {
        for (j = -4; j <= 4; j++)
            radix(map[j + 4], j, time, i);
    }
    for (j = 8; j >= 0; j--)
    {
        for (i = 0; i < 9; i++)
        {
            if (i - 4 == bk1 || i - 4 == bk2) printf("X");
            else if (map[j][i] < 0) printf("o");
            else if (map[j][i] > 0) printf("*");
            else printf("-");
        } printf("\n");
    }
    return 0;
}

