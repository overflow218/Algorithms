input = input().split()
h, m = int(input[0]), int(input[1]) - 45
print(f"{h if m >= 0 else h - 1 if h >= 1 else 23} {m if m >= 0 else 60 + m}")