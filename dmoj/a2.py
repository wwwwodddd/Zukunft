print('Ready')
while True:
    s = input()
    if s == '  ':
        break
    if s in ['pq', 'qp', 'bd', 'db']:
        print('Mirrored pair')
    else:
        print('Ordinary pair')
