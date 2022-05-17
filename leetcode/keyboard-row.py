class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        def gan(s):
            a = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
            b = []
            for i in s:
                for j in range(3):
                    if i in a[j]:
                        b.append(j)
            return max(b) == min(b)
        return [w for w in words if gan(w)]