def solution(dartResult):
    score = [0]
    idx = 0
    mapping = {'S': 1, 'D': 2, 'T': 3}
    print(mapping)
    while(idx < len(dartResult)):
        # 숫자
        if(dartResult[idx: idx + 2] == '10'):
            score.append(int(dartResult[idx: idx + 2]))
            idx += 2
        else:
            score.append(int(dartResult[idx]))
            idx += 1
        # S, D, T
        score[-1] = score[-1] ** mapping[dartResult[idx]]
        idx += 1
        # *, # 있는지 확인
        if(idx < len(dartResult)):
            if(dartResult[idx] == '*'):
                score[-1] *= 2
                score[-2] *= 2
                idx += 1
            elif(dartResult[idx] == '#'):
                score[-1] = - score[-1]
                idx += 1
    return sum(score)