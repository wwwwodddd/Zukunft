#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
char s[100];
int main()
{
    while (scanf("%s%d", s, &n) != EOF)
    {
        n &= 7;
        int l = strlen(s);
        if (n >= 4)
        {
            n -= 4;
            reverse(s, s + l);
        }
        if (n == 0)
        {
            printf("%s\n", s);
        }
        else if (n == 1)
        {
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < l - i - 1; j++)
                {
                    printf(" ");
                }
                printf("%c\n", s[l - i - 1]);
            }
        }
        else if (n == 2)
        {
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < l / 2; j++)
                {
                    printf(" ");
                }
                printf("%c\n", s[l - i - 1]);
            }
        }
        else if (n == 3)
        {
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    printf(" ");
                }
                printf("%c\n", s[l - i - 1]);
            }
        }
    }
    return 0;
}