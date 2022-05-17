class Solution:
    def uniqueOccurrences(self, a: List[int]) -> bool:
        a = Counter(a).values()
        return len(set(a)) == len(a)