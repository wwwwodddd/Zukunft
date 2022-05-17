class Solution:
    def mostCommonWord(self, p: str, b: List[str]) -> str:
        a = re.findall('\w+', p.lower())
        b = set(b)
        return Counter(i for i in a if i not in b).most_common(1)[0][0]