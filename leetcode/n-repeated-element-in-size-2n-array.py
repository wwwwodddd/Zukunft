class Solution:
    def repeatedNTimes(self, a: List[int]) -> int:
        for i in range(len(a)):
            if a[i]==a[i-1] or a[i]==a[i-2]:
                return a[i]