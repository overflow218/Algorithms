from collections import Counter

def solution(topping):
    answer = 0
    s = set()
    total = Counter(topping)
    
    for t in topping:
        total[t] -= 1
        if(total[t] == 0):
            del total[t]
        if t not in s:
            s.add(t)
        if(len(total) == len(s)): 
            answer += 1
    return answer