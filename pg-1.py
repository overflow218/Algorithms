def solution(today, terms, privacies):
    # year, month, day = list(map(int, today.split('.')))
    today = ''.join(today.split('.'))
    parsed = [term.split(' ') for term in terms]
    checker = {term: int(val) for term, val in parsed}
    answer = []
    for i in range(len(privacies)):
        date, term = privacies[i].split()
        y, m, d = list(map(int, date.split('.')))
        m += checker[term]
        while(m > 12):
            y += 1
            m -= 12
        ho = str(y) + str(m).zfill(2) + str(d).zfill(2)
        if(today >= ho):
            answer.append(i + 1)
    return answer