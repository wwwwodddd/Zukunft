class Solution:
    def makeEqual(self, w: List[str]) -> bool:
        return gcd(*Counter(''.join(w)).values())%len(w)==0