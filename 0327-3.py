def solution(n, k, cmd):
    is_removed = [False] * n
    pre_idx = [i - 1 if i > 0 else 0 for i in range(n)]
    next_idx = [i + 1 if i < n - 1 else n - 1 for i in range(n)]
    
    # 제일 최근에 삭제된 번호 담아주는 배열
    recovery = []
    for command in cmd:
        # 현재행 삭제. 커서 변경 있음.
        if(command == 'C'):
            if(k != pre_idx[k]):
                next_idx[pre_idx[k]] = next_idx[k]
            if(k != next_idx[k]):
                pre_idx[next_idx[k]] = pre_idx[k]
            is_removed[k] = True
            recovery.append(k)

            # 마지막 행인 경우 이전으로, 그게 아니면 다음 행으로 넘어감
            k = pre_idx[k] if is_removed[next_idx[k]] else next_idx[k]
            continue
        
        # 최근 삭제항 복구. 커서 변경 없음.
        if(command == 'Z'):
            last = recovery.pop()
            if(last != pre_idx[last]):
                next_idx[pre_idx[last]] = last
            if(last != next_idx[last]):
                pre_idx[next_idx[last]] = last
            is_removed[last] = False
            continue
        
        parsed = command.split()
        c, v = parsed[0], int(parsed[1])
        if(c == 'U'):
            for i in range(v):   
                k = pre_idx[k]
        if(c == 'D'):
            for i in range(v):   
                k = next_idx[k]
        
    answer = ['O' if not flag else 'X' for flag in is_removed]
    return ''.join(answer)