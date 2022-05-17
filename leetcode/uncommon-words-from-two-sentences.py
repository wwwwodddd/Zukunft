class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        a = Counter(s1.split()+s2.split())
        return [i for i in a if a[i]==1]