# https://leetcode.com/problems/bus-routes/
from itertools import combinations


def add_vertex_to_graph(graph, pair):
    if graph.get(pair[0]):
        graph[pair[0]].append(pair[1])
    else:
        graph[pair[0]] = [pair[1]]


def num_buses_to_destination(routes, S, T):
    if S == T:
        return 0
    route_map = {}
    for i, route in enumerate(routes):
        for point in route:
            if route_map.get(point):
                route_map[point].add(i)
            else:
                route_map[point] = {i}
    graph = {}
    for value in route_map.values():
        for pair in list(combinations(value, 2)):
            add_vertex_to_graph(graph, pair)
            add_vertex_to_graph(
                graph, list(reversed(pair)))

    distance = 1
    visited = set()
    cur = route_map[S]
    fin = route_map[T]

    while not bool(cur & fin):
        adj = []
        if not bool(cur):
            return -1
        for node in cur:
            if graph.get(node):
                for elem in graph[node]:
                    if not bool(visited & {elem}):
                        adj.append(elem)
                        visited.add(elem)
        cur = set(adj)
        distance += 1
    return distance


if __name__ == '__main__':
    routes = [[1], [15, 16, 18], [10], [3, 4, 12, 14]]
    num_buses_to_destination(
        routes=routes, S=3, T=15)
