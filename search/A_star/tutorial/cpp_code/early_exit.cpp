#include "implementation.cpp"

template<typename Graph>
unordered_map<typename Graph::Location, typename Graph::Location>
breadth_first_search(Graph graph,
                     typename Graph::Location start,
                     typename Graph::Location goal) {
    typedef typename Graph::Location Location;
    queue<Location> frontier;
    frontier.push(start);

    unordered_map<Location, Location> came_from;
    came_from[start] = start;

    while (!frontier.empty()) {
        auto current = frontier.front();
        frontier.pop();

        if (current == goal) {
            break;
        }

        for (auto next : graph.neighbors(current)) {
            if (!came_from.count(next)) {
                frontier.push(next);
                came_from[next] = current;
            }
        }
    }
    return came_from;
}

int main() {
    SquareGrid grid = make_diagram1();
    auto parents = breadth_first_search(grid, SquareGrid::Location{8, 7}, SquareGrid::Location{17, 2});
    draw_grid(grid, 2, nullptr, &parents);
}
