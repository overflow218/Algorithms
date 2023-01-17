def solution(n, m, x, y, r, c, k):
    answer = ''
    minimum = abs(x - r) + abs(y - c)
    left_count = k - minimum
    if(minimum > k or left_count % 2 == 1):
        return 'impossible'
    if(x < r):
        for i in range(r - x):
            answer += 'd'
    if(c < y):
        for i in range(y - c):
            answer += 'l'
    if(y < c):
        for i in range(c - y):
            answer += 'r'
    if(r < x):
        for i in range(x - r):
            answer += 'u'

    while(left_count >= 4):
        if(r <= n - 2):
            cnt = min(n - r, left_count // 2)
            answer += 'd' * cnt
            answer += 'u' * cnt
            left_count  -= 2 * cnt
        elif(r == n - 1):
            if(c == 1):
                answer += 'drlu'
            else:
                answer += 'dlru'
            left_count -= 4
        else:
            if(c == 1):
                answer += 'rlrl'
                left_count -= 4
            else:
                cnt = min(c - 1, left_count // 2)
                answer += 'l' * cnt
                answer += 'r' * cnt
                left_count  -= 2 * cnt
    
    if(left_count == 2):
        if(r < n):
                answer += 'du'
        elif(c == 1):
                answer += 'rl'
        else:
                answer += 'lr'
            
    return answer