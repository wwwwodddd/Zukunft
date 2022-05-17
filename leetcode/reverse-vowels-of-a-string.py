class Solution:
    def reverseVowels(self, s: str) -> str:
        i = 0
        j = len(s) - 1
        s = list(s)
        while True:
            while i < j and s[i].lower() not in 'aeiou':
                i += 1
            while i < j and s[j].lower() not in 'aeiou':
                j -= 1
            if i < j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
            else:
                break
        return ''.join(s)