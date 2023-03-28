def solution(elements):
    s = set()
    n = len(elements)
    elements = [0] + elements + elements
    pSum = [0] * len(elements) 
    pSum[0] = elements[0]
    for i in range(1, len(elements)):
        pSum[i] = elements[i] + pSum[i - 1]
    
    for i in range(1, n + 1):
        for j in range(n):
            s.add(pSum[i + j] - pSum[i - 1])
            
    return len(s)