'''
이게 공백포함해서 빼줘야함. 
5, 30 = 5 * 6, 155 = 5 * 31, 780 = 5 * 156 
5 + 1, 5^2 + 5 + 1, 5 ^ 3 + 5^ 2 + 1, 5 ^ 4 + 5 ^ 3 + 5 ^ 2 + 5 + 1
6, 31, 156, 781
'''

def solution(word):
    check = { 'A': 0, 'E': 1, 'I': 2, 'O': 3, 'U': 4}
    lis = [1, 6, 31, 156, 781]
    answer = 0
    for i in range(len(word)):
        answer += 1 + lis[4 - i] * check[word[i]]
    return answer