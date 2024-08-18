import heapq

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, node, neighbors):
        self.graph[node] = neighbors

def best_first_search(graph, heuristic, start, goal):
    visited = set()
    priority_queue = [(heuristic[start], start)]

    while priority_queue:
        (h, current_node) = heapq.heappop(priority_queue)

        if current_node in visited:
            continue

        print("Visited:", current_node)

        if current_node == goal:
            print("Goal reached!")
            break

        visited.add(current_node)
        neighbors = graph.graph[current_node]

        for neighbor, cost in neighbors.items():
            if neighbor not in visited:
                heapq.heappush(priority_queue, (heuristic[neighbor], neighbor))

if __name__ == "__main__":
    graph = Graph()

    # User input for graph edges
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        node = input("Enter source node: ")
        neighbors_input = input("Enter neighbors and their costs (format: neighbor1 cost1 neighbor2 cost2): ")
        neighbors = dict(zip(neighbors_input.split()[::2], map(int, neighbors_input.split()[1::2])))
        graph.add_edge(node, neighbors)

    # User input for heuristic values
    heuristic = {}
    for node in graph.graph:
        heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))

    start_node = input("Enter the start node: ")
    goal_node = input("Enter the goal node: ")

    best_first_search(graph, heuristic, start_node, goal_node)
