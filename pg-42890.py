'''
최대 입력개수가 그렇게 안큼. 
칼럼의 최대개수 8개 -> 2^8 가지 경우로 조합가능.
'''

def solution(relation):
    candidate_key = []
    column_number = len(relation[0])

    def is_minimum(chosen):
        for key in candidate_key:
            check = sum([1 if k in chosen else 0 for k in key])
            if(check == len(key)):
                return False
        return True

    def is_unique(chosen):
        candidate = []
        for row in relation:
            tmp_row = '-'.join([row[i] for i in chosen])
            candidate.append(tmp_row)
        candidate_set = set(candidate)
        return len(candidate_set) == len(candidate)

    def find(idx, limit, chosen):
        # 다 고른경우 -> 체크
        if(len(chosen) == limit):
            if(is_unique(chosen) and is_minimum(chosen)):
                candidate_key.append(chosen[:])
        elif(idx == column_number):
            return
        else:
            chosen.append(idx)
            find(idx + 1, limit, chosen)
            chosen.pop()
            find(idx + 1, limit, chosen)

    for i in range(1, column_number + 1):
        find(0, i, [])
    return len(candidate_key)