class Solution:
    def twoOutOfThree(self, a: List[int], b: List[int], c: List[int]) -> List[int]:
        d = Counter()
        for i in set(a):
            d[i] += 1
        for i in set(b):
            d[i] += 1
        for i in set(c):
            d[i] += 1
        return list(i for i in d if d[i] >= 2)