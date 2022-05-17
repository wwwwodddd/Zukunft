class Solution:
    def firstPalindrome(self, a: List[str]) -> str:
        for i in a:
            if i == i[::-1]:
                return i
        return ''