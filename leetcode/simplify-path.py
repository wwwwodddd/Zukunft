class Solution:
    def simplifyPath(self, path: str) -> str:
        a = []
        for i in path.split('/'):
            if i == '.' or i == '':
                pass
            elif i == '..':
                if len(a):
                    a.pop()
            else:
                a.append(i)
        return '/' + '/'.join(a)
            