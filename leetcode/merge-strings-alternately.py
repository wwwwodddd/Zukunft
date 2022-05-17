class Solution:
    def mergeAlternately(self, a: str, b: str) -> str:
        return ''.join(a[i:i+1]+b[i:i+1]for i in range(100))