class Solution:
    def stoneGameIII(self, a: List[int]) -> str:
        f = [0] * (len(a) + 3)
        for i in range(len(a))[::-1]:
            f[i] = max(sum(a[i:i+1])-f[i+1],sum(a[i:i+2])-f[i+2],sum(a[i:i+3])-f[i+3])
        if f[0]>0:
            return 'Alice'
        elif f[0]<0:
            return 'Bob'
        else:
            return 'Tie'