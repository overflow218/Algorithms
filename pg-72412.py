import bisect
def solution(info, query):
    db = {}
    answer = []
    for i in ["cpp", "java", "python"]:
        for j in ["backend", "frontend"]:
            for k in ["junior", "senior"]:
                for l in ["chicken", "pizza"]:
                    db[i + j + k + l] = []
    for i in info:
        parsing = i.split(' ')
        db[parsing[0] + parsing[1] + parsing[2] + parsing[3]].append(int(parsing[4]))
    for k in db.keys():
        db[k].sort()

    for q in query:
        parsing = q.split(" ")
        request = [parsing[0], parsing[2], parsing[4], parsing[6], int(parsing[7])]
        real_query = [""]
        language = [request[0]] if request[0] != '-' else ["cpp", "java", "python"]
        end = [request[1]] if request[1] != '-' else ["backend", "frontend"]
        level = [request[2]] if request[2] != '-' else ["junior", "senior"]
        food = [request[3]] if request[3] != '-' else ["chicken", "pizza"]

        for i in range(len(real_query)):
            tmp = real_query.pop(0)
            for l in language:
                real_query.append(tmp + l)
        for i in range(len(real_query)):
            tmp = real_query.pop(0)
            for l in end:
                real_query.append(tmp + l)
        for i in range(len(real_query)):
            tmp = real_query.pop(0)
            for l in level:
                real_query.append(tmp + l)
        for i in range(len(real_query)):
            tmp = real_query.pop(0)
            for l in food:
                real_query.append(tmp + l)
        
        tmp_ans = 0
        for i in real_query:
            idx = bisect.bisect_left(db[i], request[4])
            tmp_ans += len(db[i]) - idx

        answer.append(tmp_ans)
    return answer