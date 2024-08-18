EMPTY = ' '
PLAYER_X = 'X'
PLAYER_O = 'O'

def print_board(board):
    for row in board:
        print('|'.join(row))
        print('-' * 5)

def is_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def is_full(board):
    return all(cell != EMPTY for row in board for cell in row)

def evaluate(board):
    if is_winner(board, PLAYER_X):
        return 1
    elif is_winner(board, PLAYER_O):
        return -1
    elif is_full(board):
        return 0
    else:
        return None

def minimax(board, depth, is_maximizing):
    score = evaluate(board)

    if score is not None:
        return score

    if is_maximizing:
        max_eval = float('-inf')
        for i in range(3):
            for j in range(3):
                if board[i][j] == EMPTY:
                    board[i][j] = PLAYER_X
                    eval = minimax(board, depth + 1, False)
                    board[i][j] = EMPTY
                    max_eval = max(max_eval, eval)
        return max_eval
    else:
        min_eval = float('inf')
        for i in range(3):
            for j in range(3):
                if board[i][j] == EMPTY:
                    board[i][j] = PLAYER_O
                    eval = minimax(board, depth + 1, True)
                    board[i][j] = EMPTY
                    min_eval = min(min_eval, eval)
        return min_eval

def find_best_move(board):
    best_val = float('-inf')
    best_move = (-1, -1)

    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                board[i][j] = PLAYER_X
                move_val = minimax(board, 0, False)
                board[i][j] = EMPTY

                if move_val > best_val:
                    best_move = (i, j)
                    best_val = move_val

    return best_move

def main():
    board = [[EMPTY] * 3 for _ in range(3)]

    while True:
        print_board(board)
        row, col = map(int, input("Enter your move (row and column, separated by a space): ").split())

        if board[row][col] != EMPTY:
            print("Invalid move. Cell already occupied. Try again.")
            continue

        board[row][col] = PLAYER_O

        if is_winner(board, PLAYER_O):
            print_board(board)
            print("You win!")
            break

        if is_full(board):
            print_board(board)
            print("It's a draw!")
            break

        print("Computer is making a move...")
        best_move = find_best_move(board)
        board[best_move[0]][best_move[1]] = PLAYER_X

        if is_winner(board, PLAYER_X):
            print_board(board)
            print("Computer wins!")
            break

        if is_full(board):
            print_board(board)
            print("It's a draw!")
            break

if __name__ == "__main__":
    main()