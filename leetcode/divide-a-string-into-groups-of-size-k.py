class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        while len(s)%k:
            s += fill
        return [s[i:i+k]for i in range(0,len(s),k)]