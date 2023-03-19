def solution(survey, choices):
    score = {i: 0 for i in 'RTCFJMAN'}
    check = [0, 3, 2, 1, 0, 1, 2, 3]

    for s, c in zip(survey, choices):
        if(c > 4):
            score[s[1]] += check[c]
        else:
            score[s[0]] += check[c]
    answer = 'R' if(score['R'] >= score['T']) else 'T'
    answer += 'C' if(score['C'] >= score['F']) else 'F'
    answer += 'J' if(score['J'] >= score['M']) else 'M'
    answer += 'A' if(score['A'] >= score['N']) else 'N'
    return answer