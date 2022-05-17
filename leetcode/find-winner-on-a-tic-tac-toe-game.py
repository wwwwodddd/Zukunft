class Solution:
    def tictactoe(self, b: List[List[int]]) -> str:
        a = [['' for j in range(3)]for i in range(3)]
        def win():
            if a[0][0] == a[0][1] == a[0][2] != '':
                return a[0][0]
            if a[1][0] == a[1][1] == a[1][2] != '':
                return a[1][0]
            if a[2][0] == a[2][1] == a[2][2] != '':
                return a[2][0]
            if a[0][0] == a[1][0] == a[2][0] != '':
                return a[0][0]
            if a[0][1] == a[1][1] == a[2][1] != '':
                return a[0][1]
            if a[0][2] == a[1][2] == a[2][2] != '':
                return a[0][2]
            if a[0][0] == a[1][1] == a[2][2] != '':
                return a[0][0]
            if a[0][2] == a[1][1] == a[2][0] != '':
                return a[0][2]
        for i in range(len(b)):
            a[b[i][0]][b[i][1]] = 'AB'[i % 2]
            w = win()
            if w:
                return w
        if len(b) < 9:
            return 'Pending'
        else:
            return 'Draw'