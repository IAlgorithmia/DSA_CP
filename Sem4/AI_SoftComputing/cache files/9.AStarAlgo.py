import heapq

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, start, end, cost):
        if start not in self.graph:
            self.graph[start] = []
        self.graph[start].append((end, cost))

    def astar_search(self, start, goal):
        open_set = [(0, start, [])]
        closed_set = set()

        while open_set:
            f_cost, current, path = heapq.heappop(open_set)

            if current == goal:
                return path + [current]

            if current in closed_set:
                continue

            closed_set.add(current)

            for neighbor, cost in self.graph.get(current, []):
                if neighbor not in closed_set:
                    g_cost = f_cost + cost
                    h_cost = self.heuristic(neighbor, goal)
                    heapq.heappush(open_set, (g_cost + h_cost, neighbor, path + [current]))

        return None

    def heuristic(self, node, goal):
        # Replace this with your own heuristic function
        # For simplicity, this example returns 0, which makes A* behave like Dijkstra's algorithm
        return 0

# Example usage
if __name__ == "__main__":
    g = Graph()
    g.add_edge('A', 'B', 4)
    g.add_edge('A', 'C', 2)
    g.add_edge('B', 'C', 5)
    g.add_edge('B', 'D', 10)
    g.add_edge('C', 'D', 3)
    g.add_edge('D', 'E', 7)

    start_node = 'A'
    goal_node = 'E'

    result = g.astar_search(start_node, goal_node)

    if result:
        print(f"Shortest path from {start_node} to {goal_node}: {result}")
        
    else:
        print(f"No path found from {start_node} to {goal_node}")
