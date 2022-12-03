def solution(skill, skill_trees):
    answer = 0
    skill_map = {}
    for i in range(len(skill)):
        skill_map[skill[i]] = i

    for tree in skill_trees:
        check = []
        for skill in tree:
            if(skill in skill_map):
                check.append(skill_map[skill])
        if(not check or check == [i for i in range(len(check))]):
            answer += 1

    return answer