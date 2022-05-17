class Solution:
    def removeAnagrams(self, w: List[str]) -> List[str]:
        z = []
        for i in range(len(w)):
            if i == 0 or sorted(w[i]) != sorted(w[i - 1]):
                z.append(w[i])
        return z