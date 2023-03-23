def solution(id_list, report, k):
    check = {id: set() for id in id_list}
    count = {id: 0 for id in id_list}
    for r in report:
        a, b = r.split()
        check[b].add(a)
    for key in check:
        if(len(check[key]) >= k):
            for a in check[key]:
                count[a] += 1
    answer = [count[id] for id in id_list]
    return answer