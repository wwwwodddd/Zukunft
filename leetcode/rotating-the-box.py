class Solution:
    def rotateTheBox(self, b: List[List[str]]) -> List[List[str]]:
        n = len(b)
        m = len(b[0])
        a = [[b[n-1-i][j]for i in range(n)]for j in range(m)]
        for j in range(n):
            k = m - 1
            for i in range(m)[::-1]:
                if a[i][j] == '#':
                    a[k][j] = a[i][j]
                    k -= 1
                elif a[i][j] == '*':
                    while k > i:
                        a[k][j] = '.'
                        k -= 1
                    a[k][j] = '*'
                    k -= 1
            while k >= 0:
                a[k][j] = '.'
                k -= 1
        return a