class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        return ''.join(sorted(s,key=lambda x:(c[x],x),reverse=True))