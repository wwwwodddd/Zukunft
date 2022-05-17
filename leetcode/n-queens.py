class Solution(object):
    n = 0
    a = []
    y = []
    z = []
    xplusy = []
    xminusy = []
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.n = n
        self.a = [0 for i in range(n)]
        self.y = [0 for i in range(2 * n)]
        self.z = []
        self.xplusy = [0 for i in range(2 * n)]
        self.xminusy = [0 for i in range(2 * n)]
        self.dfs(0)
        return self.z
    def dfs(self, x):
        if x == self.n:
            t = []
            for i in range(self.n):
                r = ''
                for j in range(self.n):
                    if j != self.a[i]:
                        r += '.'
                    else:
                        r += 'Q'
                t.append(r)
            self.z.append(t)
            return
        for i in range(self.n):
            if not self.y[i] and not self.xplusy[x + i] and not self.xminusy[x - i]:
                self.y[i] = self.xplusy[x + i] = self.xminusy[x - i] = True
                self.a[x] = i
                self.dfs(x + 1)
                self.y[i] = self.xplusy[x + i] = self.xminusy[x - i] = False
