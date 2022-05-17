class Solution:
    def sumOfUnique(self, a: List[int]) -> int:
        a.sort()
        a.append(0)
        return sum(a[i] for i in range(len(a)-1)if a[i]!=a[i-1] and a[i]!=a[i+1])
        