class Solution:
    def minOperations(self, logs: List[str]) -> int:
        d = 0
        for i in logs:
            if i=='../':
                d = max(0, d - 1)
            elif i!='./':
                d += 1
        return d