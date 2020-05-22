s = raw_input()
print ['No', 'Yes'][('N' in s) == ('S' in s) and ('W' in s) == ('E' in s)]