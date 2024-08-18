import heapq

def heuristic(state, goal_state):
    return sum(1 for i, j in zip(state, goal_state) if i != j)

def solve_puzzle(initial_state, goal_state):
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    size = int(len(initial_state) ** 0.5)

    def is_valid_move(x, y):
        return 0 <= x < size and 0 <= y < size

    def get_neighbors(current):
        x, y = current.index(0) % size, current.index(0) // size
        neighbors = []

        for dx, dy in directions:
            new_x, new_y = x + dx, y + dy
            if is_valid_move(new_x, new_y):
                neighbor = list(current)
                neighbor[x + y * size], neighbor[new_x + new_y * size] = neighbor[new_x + new_y * size], neighbor[x + y * size]
                neighbors.append((neighbor, 1))

        return neighbors

    def a_star():
        open_set = [(heuristic(initial_state, goal_state), 0, initial_state)]
        closed_set = set()

        while open_set:
            _, g, current = heapq.heappop(open_set)
            if current == goal_state:
                return g

            if tuple(current) in closed_set:
                continue

            closed_set.add(tuple(current))

            for neighbor, cost in get_neighbors(current):
                if tuple(neighbor) not in closed_set:
                    h = heuristic(neighbor, goal_state)
                    f = g + cost + h
                    heapq.heappush(open_set, (f, g + cost, neighbor))

        return None

    return a_star()

# Example usage:
initial_state = [1, 2, 3, 4, 5, 6, 0, 7, 8]
goal_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]

result = solve_puzzle(initial_state, goal_state)
print(f"Minimum number of moves: {result}")
