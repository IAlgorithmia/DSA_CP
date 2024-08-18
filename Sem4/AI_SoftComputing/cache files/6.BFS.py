import random

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj_list = {vertex: [] for vertex in range(vertices)}

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

def dfs(graph, start, visited):
    if not visited[start]:
        print(f"Visiting node {start}")
        visited[start] = True
        for neighbor in graph.adj_list[start]:
            dfs(graph, neighbor, visited)

def main():
    num_vertices = 4
    graph = Graph(num_vertices)

    for _ in range(num_vertices * 2):
        u, v = random.sample(range(num_vertices), 2)
        graph.add_edge(u, v)

    print("Random Graph:")
    for vertex, neighbors in graph.adj_list.items():
        print(f"{vertex}: {neighbors}")

    for start_node in range(num_vertices):
        print("\nDFS starting from node", start_node)
        visited = [False] * num_vertices
        dfs(graph, start_node, visited)

if __name__ == "__main__":
    main()
