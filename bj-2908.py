input = input().split()
print(input[0][::-1] if input[0][::-1] > input[1][::-1] else input[1][::-1])