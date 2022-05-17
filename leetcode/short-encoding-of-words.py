class Solution:
    def minimumLengthEncoding(self, a: List[str]) -> int:
        a = [i[::-1] for i in a]
        a.sort()
        z = 0
        for i in range(len(a)):
            if i + 1 < len(a) and a[i + 1].startswith(a[i]):
                pass
            else:
                z += len(a[i]) + 1
        return z