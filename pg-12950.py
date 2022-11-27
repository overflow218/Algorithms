def solution(arr1, arr2):
    return [[pi + pj for pi, pj in zip(i, j)] for i, j in zip(arr1, arr2)]