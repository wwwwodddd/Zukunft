class Solution:
    def wordSubsets(self, a: List[str], b: List[str]) -> List[str]:
        c = Counter()
        for s in b:
            c |= Counter(s)
        return [s for s in a if not c - Counter(s)]