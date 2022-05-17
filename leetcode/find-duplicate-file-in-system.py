class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        g = {}
        for info in paths:
            tokens = info.split()
            for file in tokens[1:]:
                filename, content = file.split('(')
                if content not in g:
                    g[content] = []
                g[content].append(tokens[0] + '/' + filename)
        return list(g[i] for i in g if len(g[i]) > 1)