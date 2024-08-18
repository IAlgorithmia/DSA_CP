import random

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj_list = {vertex: [] for vertex in range(vertices)}

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def bfs(graph, start, visited):
        queue = [start]
        visited[start] = True
        while queue:
            current_node = queue.pop(0)
            print(f"Visiting node {current_node}")
            for neighbor in graph.adj_list[current_node]:
                if not visited[neighbor]:
                    queue.append(neighbor)
                    visited[neighbor] = True

def main():
    num_vertices = 5
    graph = Graph(num_vertices)

    for _ in range(num_vertices * 2):
        u, v = random.sample(range(num_vertices), 2)
        graph.add_edge(u, v)

    print("Random Graph:")
    for vertex, neighbors in graph.adj_list.items():
        print(f"{vertex}: {neighbors}")

    for start_node in range(num_vertices):
        print("\nBFS starting from node", start_node)
        visited = [False] * num_vertices
        graph.bfs(start_node, visited)

if __name__ == "__main__":
    main()
