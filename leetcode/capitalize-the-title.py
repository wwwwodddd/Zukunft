class Solution:
    def capitalizeTitle(self, a: str) -> str:
        b = []
        for i in a.split():
            if len(i) < 3:
                b.append(i.lower())
            else:
                b.append(i.capitalize())
        return ' '.join(b)