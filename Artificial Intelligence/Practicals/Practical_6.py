import random

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def get_empty_cells(board):
    return [(i, j) for i in range(3) for j in range(3) if board[i][j] == " "]

def minimax(board, depth, maximizing_player):
    if check_winner(board, "X"):
        return -1
    if check_winner(board, "O"):
        return 1
    if len(get_empty_cells(board)) == 0:
        return 0

    if maximizing_player:
        max_eval = float("-inf")
        for i, j in get_empty_cells(board):
            board[i][j] = "O"
            eval = minimax(board, depth + 1, False)
            board[i][j] = " "
            max_eval = max(max_eval, eval)
        return max_eval
    else:
        min_eval = float("inf")
        for i, j in get_empty_cells(board):
            board[i][j] = "X"
            eval = minimax(board, depth + 1, True)
            board[i][j] = " "
            min_eval = min(min_eval, eval)
        return min_eval

def find_best_move(board):
    best_move = None
    best_eval = float("-inf")
    for i, j in get_empty_cells(board):
        board[i][j] = "O"
        eval = minimax(board, 0, False)
        board[i][j] = " "
        if eval > best_eval:
            best_eval = eval
            best_move = (i, j)
    return best_move

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    
    print("Welcome to Tic-Tac-Toe!")
    print_board(board)
    
    while True:
        player_move = input("Enter your move (row and column, e.g., '1 2'): ")
        row, col = map(int, player_move.split())
        
        if board[row-1][col-1] == " ":
            board[row-1][col-1] = "X"
        else:
            print("Invalid move. Try again.")
            continue
        
        print_board(board)
        
        if check_winner(board, "X"):
            print("You win!")
            break
        
        if len(get_empty_cells(board)) == 0:
            print("It's a draw!")
            break
        
        print("Computer's turn:")
        computer_move = find_best_move(board)
        board[computer_move[0]][computer_move[1]] = "O"
        print_board(board)
        
        if check_winner(board, "O"):
            print("Computer wins!")
            break

if __name__ == "__main__":
    main()
