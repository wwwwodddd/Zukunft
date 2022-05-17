class Solution:
    def sortFeatures(self, a: List[str], s: List[str]) -> List[str]:
        c = Counter(j for i in s for j in set(i.split()))
        a.sort(key=lambda x:-c[x])
        return a