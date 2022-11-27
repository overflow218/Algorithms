from collections import Counter

def solution(X, Y):
    collection_x = Counter(X)
    collection_y = Counter(Y)
    intersection = set(X) & set(Y)
    if(len(intersection) == 0): return "-1"    
    answer = ''.join(sorted([ i * min(collection_x[i], collection_y[i]) for i in intersection], reverse = True))
    return "0" if answer[0] == "0" else answer