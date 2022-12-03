def solution(board, moves):
    answer = 0
    new_board = [[]]
    basket = []
    n = len(board[0])
    for i in range(n):
        new_board.append([board[j][i] for j in range(n - 1, -1, -1) if board[j][i] > 0])

    for move in moves:
        if(new_board[move]):
            doll = new_board[move].pop()
            if(basket and basket[-1] == doll):
                answer += 2
                basket.pop()
            else:
                basket.append(doll)

    return answer