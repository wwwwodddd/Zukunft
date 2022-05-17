class Solution:
    def alphabetBoardPath(self, t: str) -> str:
        sx, sy = 0, 0
        z = ''
        for i in t:
            tx = (ord(i)-97)//5
            ty = (ord(i)-97)%5
            z += (sx-tx)*'U'+(sy-ty)*'L'+(tx-sx)*'D'+(ty-sy)*'R'+'!'
            sx, sy = tx, ty
        return z