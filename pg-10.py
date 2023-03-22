def solution(n, m, x, y, r, c, k):
    answer = ''
    # 불가능한 경우 핸들
    basic = abs(x - r) + abs(y - c)
    if(k < basic or (k - basic) % 2 == 1):
        return 'impossible'
    left = k - basic
    check = {'d': max(0, r - x), 'l': max(0, y - c), 'r': max(0, c - y), 'u': max(0, x - r)}
    cnt = 0
    
    while(cnt <= k):
        cnt += 1
        # print(f'cnt {cnt}, ans {answer}')
        if(check['d'] > 0):
            answer += 'd'
            check['d'] -= 1
            x += 1
            continue
        # 아래로 내려갈 수 있는 상황
        if(x < n and left > 0):
            answer += 'd'
            left -= 2
            check['u'] += 1
            x += 1
            continue
            
        if(check['l'] > 0):
            answer += 'l'
            check['l'] -= 1
            y -= 1
            continue
        # 왼쪽으로 갈 수 있는 상황
        if(y > 1 and left > 0):
            answer += 'l'
            left -= 2
            check['r'] += 1
            y -= 1
            continue
            
        if(check['r'] > 0):
            answer += 'r'
            check['r'] -= 1
            y += 1
            continue
        # 오른쪽으로 갈 수 있는 상황
        if(y < m and left > 0):
            answer += 'r'
            left -= 2
            check['l'] += 1
            y += 1
            continue
            
        if(check['u'] > 0):
            answer += 'u'
            check['u'] -= 1
            x -= 1
            continue
        # 위로 올라갈 수 있는 상황
        if(x > 1 and left > 0):
            answer += 'u'
            left -= 2
            check['d'] += 1
            x -= 1
            continue
    return answer