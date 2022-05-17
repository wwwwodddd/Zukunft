class Solution:
    def checkSubarraySum(self, a: List[int], k: int) -> bool:
        s = 0
        t = set()
        for i in a:
            if (s + i) % k in t:
                return True
            t.add(s)
            s = (s + i) % k
        return False