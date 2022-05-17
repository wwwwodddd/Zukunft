class Solution:
    def replaceWords(self, d: List[str], a: str) -> str:
        d.sort(key=len)
        a = a.split()
        for i in range(len(a)):
            for p in d:
                if a[i].startswith(p):
                    a[i] = p
                    break
        return ' '.join(a)