class Solution:
    def asteroidsDestroyed(self, m: int, a: List[int]) -> bool:
        a.sort()
        for i in a:
            if i > m:
                return False
            m += i
        return True