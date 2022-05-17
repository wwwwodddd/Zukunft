class Solution:
    def maxSubsequence(self, a: List[int], k: int) -> List[int]:
        b = sorted((a[i],i)for i in range(len(a)))
        c = []
        for i in range(len(a)):
            if (a[i],i)>=b[-k]:
                c.append(a[i])
        return c