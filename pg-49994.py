def solution(dirs):
    answer = 0
    check = set()
    position = [0, 0]
        
    for d in dirs:
        current_position = ','.join([str(i) for i in position])
        if(d == 'U'):
            position = [position[0], min(5, position[1] + 1)]
        if(d == 'D'):
            position = [position[0], max(-5, position[1] - 1)]
        if(d == 'L'):
            position = [max(- 5, position[0] - 1), position[1]]
        if(d == 'R'):
            position = [min(5, position[0] + 1), position[1]]
        next_position = ','.join([str(i) for i in position])

        if(current_position != next_position):
            p1 = current_position + next_position
            p2 = next_position + current_position
            if(p1 not in check and p2 not in check):
                check.add(p1)
                check.add(p2)
                answer += 1
    return answer