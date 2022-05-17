class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        c=Counter(s[i-minSize:i]for i in range(minSize,len(s)+1))
        return max([0]+[c[i]for i in c if len(set(i))<=maxLetters])