class Solution:
    def sortedSquares(self, a: List[int]) -> List[int]:
        n = len(a)
        b = []
        i = -1
        j = 0
        for k in range(n):
            if a[k]<0:
                i=k
                j=i+1
            else:
                break
        while 0<=i or j<n:
            if i<0 or (j<n and a[j]**2<a[i]**2):
                b.append(a[j]**2)
                j+=1
            else:
                b.append(a[i]**2)
                i-=1
        return b