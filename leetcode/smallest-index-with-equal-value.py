class Solution:
    def smallestEqual(self, a: List[int]) -> int:
        for i in range(len(a)):
            if a[i] == i % 10:
                return i
        return -1