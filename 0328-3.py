def solution(want, number, discount):
    answer = 0
    wanted = {i: v for i, v in zip(want, number)}
    bucket = {i: 0 for i in want}
    
    def is_good():
        for key in wanted:
            if(wanted[key] > bucket.get(key, 0)): return False
        return True
    
    for i in range(len(discount)):
        if(discount[i] not in bucket):
            bucket[discount[i]] = 0
        bucket[discount[i]] += 1
        if(i >= 10):
            bucket[discount[i - 10]] -= 1
        if(is_good()): answer += 1
    return answer