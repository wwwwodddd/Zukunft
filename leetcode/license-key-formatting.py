class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace('-', '').upper()
        i = (len(s) - 1) % k + 1
        z = s[:i]
        while i < len(s):
            z += '-' + s[i : i + k]
            i += k
        return z