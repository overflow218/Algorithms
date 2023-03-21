def solution(queue1, queue2):
    s1 = sum(queue1)
    s2 = sum(queue2)
    # 이미 합이 같을때
    if(s1 == s2):
        return 0
    # 합이 홀수라서 불가능한 경우
    if((s1 + s2) % 2 == 1):
        return -1
    
    target = (s1 + s2) // 2
    answer = -1
    
    check = queue1 + queue2
    total = check[0]
    start, end = 0, 0
    n = len(queue1)
    while(True):
        if(total == target):
            # print(f'start {start}, end {end}')
            if(end < n):
                if(start == 0):
                    answer = n + end + 1
                elif(end == n - 1):
                    answer = start
                else:
                    # error();
                    answer = end + 1 + n + start
            elif(start < n and end >= n):
                if(start == 0):
                    answer = end - n + 1
                # 세분화 필요
                if(end < 2 * n - 1):
                    answer = start + end - n + 1
                else:
                    answer = 2 * n - 1
            else:
                # 세분화 필요
                end -= n
                start -= n
                if(start == 0 and end < n - 1):
                    answer = n + end + 1
                elif(start > 0 and end == n -1):
                    answer = start
                else:
                    # error();
                    answer = start + end + 1 + n
            break
        elif(total < target):
            if(end + 1 < 2 * n):
                end += 1
                total += check[end]
            # 불가능함
            else:
                break
        elif(total > target):
            # 불가능함 종료
            if(start == end):
                break
            else:
                total -= check[start]
                start += 1
    return answer

'''
이게 맨 먼저 찾은게 최소값이 아닐수도 있어서 문제인거 같은데?
계산이 틀린거같지는 않음 왜냐면 계산이 틀렸으면 그것도 틀려야함.
'''