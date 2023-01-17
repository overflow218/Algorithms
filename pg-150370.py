def convert(str_day):
    year, month, day = map(int, str_day.split('.'))
    return 12 * 28 * year + (month - 1) * 28 + day

def solution(today, terms, privacies):
    answer = []
    check = {}
    for term in terms:
        key, val = term.split(' ')
        check[key] = int(val)
    
    for idx, privacy in enumerate(privacies):
        date, term = privacy.split(' ')
        due = convert(date) + check[term] * 28
        if(convert(today) >= due):
            answer.append(idx + 1)
    return answer