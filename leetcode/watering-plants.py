class Solution:
    def wateringPlants(self, a: List[int], c: int) -> int:
        s = c
        z = 0
        for i in range(len(a)):
            if s<a[i]:
                z+=2*i
                s=c
            z+=1
            s-=a[i]
        return z
        