from collections import Counter


def solution(k, tangerine):
    answer = 0
    counter = Counter(tangerine)
    check = [counter[i] for i in counter]
    check.sort(reverse=True)
    cnt = 0
    for i in check:
        if(cnt >= k): break
        cnt += i
        answer += 1
    return answer