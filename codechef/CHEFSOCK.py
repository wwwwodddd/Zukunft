x, y, z = map(int, input().split())
print(['Lucky Chef', 'Unlucky Chef'][(z - x) // y % 2])