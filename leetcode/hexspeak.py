class Solution:
    def toHexspeak(self, x: str) -> str:
        x = hex(int(x))[2:].upper().replace('0', 'O').replace('1', 'I')
        for i in x:
            if i not in 'ABCDEFIO':
                return 'ERROR'
        return x