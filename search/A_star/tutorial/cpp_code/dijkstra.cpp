#include "implementation.cpp"

int main() {
    GridWithWeights grid = make_diagram4();
    SquareGrid::Location start{1, 4};
    SquareGrid::Location goal{8, 5};
    unordered_map<SquareGrid::Location, SquareGrid::Location> came_from;
    unordered_map<SquareGrid::Location, int> cost_so_far;
    dijkstra_search(grid, start, goal, came_from, cost_so_far);
    draw_grid(grid, 2, nullptr, &came_from);
    std::cout << std::endl;
    draw_grid(grid, 3, &cost_so_far, nullptr);
    std::cout << std::endl;
    vector<SquareGrid::Location> path = reconstruct_path(start, goal, came_from);
    draw_grid(grid, 3, nullptr, nullptr, &path);
}
