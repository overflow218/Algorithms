input = input().split()
print(">" if int(input[0]) > int(input[1]) else "==" if int(input[0]) == int(input[1]) else "<")