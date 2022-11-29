def solution(survey, choices):
    score = [0, 3, 2, 1, 0, 1, 2, 3]
    total = { 'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    answer = ''
    for s, choice in zip(survey, choices):
        if(choice < 4):
            total[s[0]] += score[choice]
        else:
            total[s[1]] += score[choice]
    if(total['R'] < total['T']):
        answer += 'T'
    else:
        answer += 'R'
    if(total['C'] < total['F']):
        answer += 'F'
    else:
        answer += 'C'
    if(total['J'] < total['M']):
        answer += 'M'
    else:
        answer += 'J'
    if(total['A'] < total['N']):
        answer += 'N'
    else:
        answer += 'A'
    return answer