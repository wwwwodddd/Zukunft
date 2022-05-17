class Solution:
    def countTriplets(self, a: List[int]) -> int:
        n = len(a)
        b = [0 for i in range(n + 1)]
        for i in range(n):
            b[i + 1] = b[i]^a[i]
        z=0
        for i in range(n):
            for j in range(i+1,n+1):
                if b[i]==b[j]:
                    z+=j-i-1
        return z