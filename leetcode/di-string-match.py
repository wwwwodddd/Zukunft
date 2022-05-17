class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        l = r = 0
        a = [0]
        for i in s:
            if i == 'I':
                r += 1
                a.append(r)
            else:
                l -= 1
                a.append(l)
        return [i - l for i in a]