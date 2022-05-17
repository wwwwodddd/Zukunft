class Solution:
    def countLargestGroup(self, n: int) -> int:
        d = [0 for i in range(99)]
        for i in range(1, n + 1):
            d[sum(map(int,str(i)))]+=1
        return d.count(max(d))