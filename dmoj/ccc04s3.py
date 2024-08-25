g = []
for _ in range(10):
    g.append(input().split())

while True:
    changed = False
    for r in range(10):
        for c in range(9):
            if isinstance(g[r][c], str):
                if g[r][c].isdigit():
                    g[r][c] = int(g[r][c])
                    changed = True
                else:
                    gv = g[r][c].split('+')
                    cur_sum = 0
                    for cell in gv:
                        x = ord(cell[0]) - 65
                        y = ord(cell[1]) - 49
                        if isinstance(g[x][y], str):
                            break
                        else:
                            cur_sum += g[x][y]
                    else:
                        g[r][c] = cur_sum
                        changed = True
    if not changed:
        break
 
for r in range(10):
    for c in range(9):
        if isinstance(g[r][c], str):
            g[r][c] = '*'
    print(*g[r])
