def solution(name):
    num = [min(abs(ord('A') - ord(i)), abs(ord('Z') - ord(i)) + 1) for i in name]
    limit = len(name)
    alpha_cnt = sum(num)
    move_cnt = 0
    current = 0
    while(True):
        num[current] = 0
        if(sum(num) == 0): break
        left = 0
        while(num[(limit + current - left) % limit] == 0):
            left += 1
        right = 0
        while(num[(current + right) % limit] == 0):
            right += 1
        if(left < right):
            current = (limit + current - left) % limit
            move_cnt += left
        else:
            current = (current + right) % limit
            move_cnt += right
    return alpha_cnt + move_cnt