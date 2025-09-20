#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <climits>

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
        {"A", {{"B", 6}, {"C", 9}, {"E", 1}}},
        {"B", {{"A", 6}, {"D", 3}, {"E", 4}}},
        {"C", {{"A", 9}, {"F", 2}, {"G", 3}}},
        {"D", {{"B", 3}, {"E", 5}, {"F", 7}}},
        {"E", {{"A", 1}, {"B", 4}, {"D", 5}, {"F", 6}}},
        {"F", {{"C", 2}, {"E", 6}, {"D", 7}}},
        {"G", {{"C", 3}}}
    };

    string start = "A", goal = "G";
    auto result = bfs_path_with_cost(graph, start, goal);

    cout << "Path from " << start << " to " << goal << ": ";
    for (const auto &node : result.first) cout << node << " ";
    cout << "\nTotal cost: " << result.second << endl;

    return 0;
}
