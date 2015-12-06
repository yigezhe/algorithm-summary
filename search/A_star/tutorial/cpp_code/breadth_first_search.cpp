#include "implementation.cpp"

template<typename Graph>
void breadth_first_search(Graph graph, typename Graph::Location start) {
    typedef typename Graph::Location Location;
    queue<Location> frontier;
    frontier.push(start);

    unordered_set<Location> visited;
    visited.insert(start);

    while (!frontier.empty()) {
        auto current = frontier.front();
        frontier.pop();

        std::cout << "Visiting " << current << std::endl;
        for (auto next : graph.neighbors(current)) {
            if (!visited.count(next)) {
                frontier.push(next);
                visited.insert(next);
            }
        }
    }
}


int main() {
    breadth_first_search(example_graph, 'A');
}
