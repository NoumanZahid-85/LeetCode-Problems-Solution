#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <climits> // for INT_MAX

using namespace std;

struct State {
    string node;
    vector<string> path;
    int cost;
};

pair<vector<string>, int> bfs_path_with_cost(
    unordered_map<string, vector<pair<string, int>>> &graph,
    string start,
    string goal
) {
    queue<State> q;
    q.push({start, {start}, 0});
    set<string> visited;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.node == goal) {
            return make_pair(current.path, current.cost);
        }

        if (visited.find(current.node) == visited.end()) {
            visited.insert(current.node);
            for (auto &neighbor : graph[current.node]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    vector<string> new_path = current.path;
                    new_path.push_back(neighbor.first);
                    q.push({neighbor.first, new_path, current.cost + neighbor.second});
                }
            }
        }
    }
    return make_pair(vector<string>(), INT_MAX);
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graph = {
        {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
        {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
        {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
        {"Sibiu", {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
        {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
        {"Lugoj", {{"Timisoara", 111}, {"Mehadia", 70}}},
        {"Mehadia", {{"Lugoj", 70}, {"Drobeta", 75}}},
        {"Drobeta", {{"Mehadia", 75}, {"Craiova", 120}}},
        {"Craiova", {{"Drobeta", 120}, {"Rimnicu Vilcea", 146}, {"Pitesti", 138}}},
        {"Rimnicu Vilcea", {{"Sibiu", 80}, {"Craiova", 146}, {"Pitesti", 97}}},
        {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}},
        {"Pitesti", {{"Rimnicu Vilcea", 97}, {"Craiova", 138}, {"Bucharest", 101}}},
        {"Bucharest", {{"Fagaras", 211}, {"Pitesti", 101}, {"Giurgiu", 90}, {"Urziceni", 85}}},
        {"Giurgiu", {{"Bucharest", 90}}},
        {"Urziceni", {{"Bucharest", 85}, {"Hirsova", 98}, {"Vaslui", 142}}},
        {"Hirsova", {{"Urziceni", 98}, {"Eforie", 86}}},
        {"Eforie", {{"Hirsova", 86}}},
        {"Vaslui", {{"Urziceni", 142}, {"Iasi", 92}}},
        {"Iasi", {{"Vaslui", 92}, {"Neamt", 87}}},
        {"Neamt", {{"Iasi", 87}}}
    };

    string start = "Arad", goal = "Bucharest";
    auto result = bfs_path_with_cost(graph, start, goal);

    cout << "Path from " << start << " to " << goal << ": ";
    for (const auto &city : result.first) cout << city << " ";
    cout << "\nTotal distance: " << result.second << endl;

    return 0;
}
