score = [0] * 11 #현재까지 최고답
answer = [] # 현재까지 최고 점수차
best_score = 1 
apeach = []

def find(idx, left_count):
    global answer
    global score
    global best_score
    global apeach
    if(idx == 11 or left_count == 0):
        if(left_count > 0):
            score[10] += left_count
        rion_score = sum([10 - i if score[i] > apeach[i] and score[i] > 0 else 0 for i in range(11)])
        apeach_score = sum([10 - i if score[i] <= apeach[i] and apeach[i] > 0 else 0 for i in range(11)])
        if(best_score < rion_score - apeach_score):
            best_score = rion_score - apeach_score
            answer = score[:]
        elif(best_score == rion_score - apeach_score):
            for prev, new in zip(reversed(answer), reversed(score)):
                if(new > 0 and new > prev):
                    answer = score[:]
                    break
                if(prev > 0 and prev > new):
                    break

        if(left_count > 0):
            score[10] -= left_count
    else:
        #이길수 있는 경우 
        if(apeach[idx] + 1 <= left_count):
            score[idx] = apeach[idx] + 1
            find(idx + 1, left_count - 1 - apeach[idx])
            score[idx] = 0
        # 어차피 질거면 하나도 안쏘고 지는게 나음
        find(idx + 1, left_count)
        
def solution(n, info):
    global apeach
    apeach = info
    find(0, n)
    return [-1] if not answer else answer