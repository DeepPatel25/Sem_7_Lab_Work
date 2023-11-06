import heapq

# Define the goal state
goal_state = [1, 2, 3, 8, 0, 4, 7, 6, 5]

# Define the possible moves
moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def is_valid(x, y):
    return 0 <= x < 3 and 0 <= y < 3

def heuristic(state):
    # Calculate the Manhattan distance heuristic
    h = 0
    for i in range(9):
        if state[i] == 0:
            continue
        x, y = i // 3, i % 3
        gx, gy = (state[i] - 1) // 3, (state[i] - 1) % 3
        h += abs(x - gx) + abs(y - gy)
    return h

def a_star(initial_state):
    open_set = [(heuristic(initial_state), 0, initial_state)]
    visited = set()
    
    while open_set:
        _, g, current_state = heapq.heappop(open_set)
        visited.add(tuple(current_state))
        
        if current_state == goal_state:
            return current_state
        
        for dx, dy in moves:
            x, y = current_state.index(0) // 3 + dx, current_state.index(0) % 3 + dy
            if is_valid(x, y):
                new_state = current_state[:]
                index1, index2 = current_state.index(0), 3 * x + y
                new_state[index1], new_state[index2] = new_state[index2], new_state[index1]
                if tuple(new_state) not in visited:
                    heapq.heappush(open_set, (g + heuristic(new_state), g + 1, new_state))
    
    return None

def print_puzzle(puzzle):
    for i in range(0, 9, 3):
        print(puzzle[i], puzzle[i + 1], puzzle[i + 2])

initial_state = [2, 8, 3, 1, 0, 4, 7, 6, 5]
print("Initial State:")
print_puzzle(initial_state)

solution = a_star(initial_state)

if solution:
    print("\nSolution:")
    print_puzzle(solution)
else:
    print("\nNo solution found.")
