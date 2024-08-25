linksGoTo = {}
links = int(input())
for i in range(links):
    link = input()
    linksGoTo[link] = []
    while True:
        x = input()
        while '<A HREF=' in x:
            split = x.split("\"")
            linksGoTo[link].append(split[1])
            x = "\"".join(split[2:])
        if "</HTML>" in x:
            break
for link in linksGoTo:
    for v in linksGoTo[link]:
        print(f'Link from {link} to {v}')


vis = set()
def dfs(t, cur):
    global possible
    if cur == t:
        possible = True
        return 1
    if cur in vis:
        return
    vis.add(cur)
    if cur in webs:
        for v in webs[cur]:
            dfs(t, v)

while True:
    x = input()
    if x == "The End":
        break
    y = input()
    valid = []
    queue = []
    if check(x, y) == "yes":
        print("Can surf from {} to {}.".format(x, y))
    else:
        print("Can't surf from {} to {}.".format(x, y))