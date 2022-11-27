def find(idx, collatz):
    start = idx[0]
    end = len(collatz) + idx[1]
    total = 0
    if(start == end): return 0
    else if (start > end): return -1
    else:
        return sum([ (collatz[i] + collatz[i + 1]) / 2 for i in range(start, end)])

def solution(k, ranges):
    collatz = [k]
    while(k != 1):
        if(k % 2 == 0):
            k = k   // 2
        else:
            k = k * 3 + 1
        collatz.append(k)
    print(collatz)
    answer = [find(idx, collatz) for idx in ranges]
    return answer