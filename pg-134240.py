def solution(food):
    answer = ''
    for i, value in enumerate(food[1:], start = 1):
        answer += str(i) * int(value // 2)
    return answer + '0' + answer[::-1]