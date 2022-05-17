class Solution:
    def countArrangement(self, n: int) -> int:
        f = [0 for i in range(2**n)]
        f[0] = 1
        for i in range(2**n):
            k = bin(i).count('1')
            for j in range(n):
                if ~i>>j&1:
                    if (k+1)%(j+1)==0 or (j+1)%(k+1)==0:
                        f[i|1<<j] += f[i]
        return f[2**n-1]