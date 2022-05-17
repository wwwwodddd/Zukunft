class Solution:
    def numSmallerByFrequency(self, a: List[str], b: List[str]) -> List[int]:
        a = [i.count(min(i)) for i in a]
        b = [i.count(min(i)) for i in b]
        c = [0 for i in range(12)]
        for i in b:
            c[i] += 1
        for i in range(11)[::-1]:
            c[i] += c[i + 1]
        return [c[i + 1] for i in a]