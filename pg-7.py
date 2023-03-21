def solution(gems):
    gem_count = len(set(gems))
    check = {}
    s, e = 0, 0
    ans = [1, len(gems)]
    while(e < len(gems)):
        if(gems[e] not in check):
            check[gems[e]] = 1
        else:
            check[gems[e]] += 1
        while(len(check) == gem_count):
            if(ans[1] - ans[0] > e - s):
                ans[1] = e + 1
                ans[0] = s + 1
            check[gems[s]] -= 1
            if(check[gems[s]] == 0):
                del check[gems[s]]
            s += 1
        e += 1
    return ans