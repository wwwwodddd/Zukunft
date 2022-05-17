class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        c = Counter(s)
        z = []
        for i in s:
            if i not in z:
                while len(z) > 0 and z[-1] > i and c[z[-1]] > 0:
                    z.pop()
                z.append(i)
            c[i] -= 1
        return ''.join(z)