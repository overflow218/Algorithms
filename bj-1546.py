m = int(input())
score = [int(i) for i in input().split()]
best = max(score)
print(sum([i / best * 100 for i in score])/m)