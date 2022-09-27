class Node():
    def __init__(self, links, is_little=False):
        self.is_little = is_little
        self.links = links 
        self.visited = False

    def __repr__(self):
        return f"Node {'small' if self.is_little else 'big'} cave \n Links: {self.links} \n Visited: {self.visited}\n"


def get_input():
    first, second = input().split("-")
    map_cave = dict()

    def add_map(first, second):
        if first not in map_cave:
            new_node = Node([second], first.islower())
            map_cave[first] = new_node
        elif second not in map_cave[first].links:
            map_cave[first].links.append(second)

    while (first != '0'):
        add_map(first, second)
        add_map(second, first)
        first, second = input().split("-")

    return map_cave

def first_star_dfs(maps, curr_node: str = "start"):
    if curr_node == "end": return 1

    count = 0
    for path in maps[curr_node].links:
        to_visit = maps[path]
        if to_visit.is_little and not to_visit.visited:
            to_visit.visited = True
            count += first_star_dfs(maps, path)
            to_visit.visited = False
        elif not to_visit.is_little:
            count += first_star_dfs(maps, path)

    return count

def second_star_dfs(maps, visited = ["start"], curr_node: str = "start", has_twiced = False):
    if curr_node == "end": 
        # print(visited)
        return 1

    count = 0
    for path in maps[curr_node].links:
        to_visit = maps[path]
        if to_visit.is_little and not to_visit.visited:
            to_visit.visited = True
            count += second_star_dfs(maps, visited + [path], path, has_twiced)
            to_visit.visited = False
        elif to_visit.is_little and path != "start" and not has_twiced:
            count += second_star_dfs(maps, visited + [path], path, True)
        elif not to_visit.is_little:
            count += second_star_dfs(maps, visited + [path], path, has_twiced)

    return count

maps = get_input()
maps["start"].visited = True

print(second_star_dfs(maps))