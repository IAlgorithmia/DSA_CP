class WumpusWorld:
    def __init__(self, size):
        self.size = size
        self.grid = [[' '] * size for _ in range(size)]
        self.agent_pos = (0, 0)

    def initialize(self):
        pass

    def move(self, direction):
        pass

    def dfs(self, x, y, visited):
        if (x, y) == (self.size - 1, self.size - 1):
            return True

        visited.add((x, y))

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            new_x, new_y = x + dx, y + dy
            if 0 <= new_x < self.size and 0 <= new_y < self.size and (new_x, new_y) not in visited:
                if self.dfs(new_x, new_y, visited):
                    return True

        return False

    def solve(self):
        self.initialize()
        visited = set()
        result = self.dfs(0, 0, visited)
        return result


if __name__ == "__main__":
    size = 4
    world = WumpusWorld(size)
    solution = world.solve()
    if solution:
        print("Solution found!")
    else:
        print("No solution found!")
