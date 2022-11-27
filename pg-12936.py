import math
def solution(n, k):
    answer = []
    facto = [math.factorial(i) for i in range(0, n + 1)]
    lis = [i for i in range(1, n + 1)]
    while(lis):
        n = len(lis)
        idx = 0
        while(idx * facto[n - 1] < k):
            idx += 1
        k -= (idx - 1) * facto[n - 1]
        answer.append(lis.pop(idx - 1))
    return answer