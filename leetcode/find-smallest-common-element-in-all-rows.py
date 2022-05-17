class Solution:
    def smallestCommonElement(self, a: List[List[int]]) -> int:
        c = [0 for i in range(10001)]
        for i in a:
            for j in i:
                c[j] += 1
        for i in range(10001):
            if c[i] == len(a):
                return i
        return -1