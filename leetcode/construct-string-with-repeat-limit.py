class Solution:
    def repeatLimitedString(self, s: str, m: int) -> str:
        c = Counter(s)
        a = sorted(c)
        z = ''
        for i in a[::-1]:
            while c[i] > m:
                z += i * m
                c[i] -= m
                for j in a[::-1]:
                    if j != i and c[j] > 0:
                        z += j
                        c[j] -= 1
                        break
                else:
                    return z
            z += i * c[i]
            c[i] = 0
        return z