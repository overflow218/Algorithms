def solution(elements):
    limit = len(elements)
    elements = elements + elements[:-1]
    s = set()
    for i in range(limit):
        for j in range(1, limit + 1):
            s.add(sum(elements[i:i + j]))    
    return len(s)