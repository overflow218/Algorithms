asc = ['1', '2', '3', '4', '5', '6', '7', '8']
music = input().split()
print("ascending" if asc == music else "descending" if asc[::-1] == music else "mixed")