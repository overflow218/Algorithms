def solution(n):
    check = int(n ** 0.5)
    return (check + 1) ** 2 if n == check ** 2 else -1