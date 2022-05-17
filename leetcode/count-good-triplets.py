class Solution:
    def countGoodTriplets(self, d: List[int], a: int, b: int, c: int) -> int:
        z=0
        for k in range(len(d)):
            for j in range(k):
                for i in range(j):
                    if abs(d[i]-d[j])<=a and abs(d[j]-d[k])<=b and abs(d[i]-d[k])<=c:
                        z+=1
        return z