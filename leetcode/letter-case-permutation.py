class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        f = ['']
        for i in s:
            if i.isdigit():
                f = [j + i for j in f]
            else:
                f = [j + i.lower() for j in f] + [j + i.upper() for j in f]
        return f