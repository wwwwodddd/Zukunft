class Solution:
    def expand(self, s: str) -> List[str]:
        z = {''}
        i = 0
        while i < len(s):
            if s[i].isalpha():
                z = {j + s[i] for j in z}
                i += 1
            else:
                j = i
                while s[j] != '}':
                    j += 1
                t = s[i+1 : j].split(',')
                z = {j + k for j in z for k in t}
                i = j + 1
        return sorted(z)