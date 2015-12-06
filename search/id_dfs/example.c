//http://stackoverflow.com/questions/10872398/creating-path-array-using-iddfs
int DLS(int node, int goal, int depth,int adj[9][9]) {
    int i,x;
    if ( depth >= 0 ) {
        if ( node == goal )
            return node;

        for(i=0; i<nodes; i++) {
            if(adj[node][i] == 1) {
                child = i;
                x = DLS(child, goal, depth-1,adj);

                if(x == goal)
                    return goal;
            }
        }
    }
    return 0;
}

int IDDFS(int root,int goal,int adj[9][9]) {
    depth = 0;
    solution = 0;
    while(solution <= 0 && depth < nodes) {
        solution = DLS(root, goal, depth,adj);
        depth++;
    }
    if(depth  == nodes)
        return inf;

    return depth-1;
}

int main() {
    int i,u,v,source,goal;

    int adj[9][9] = {{0,1,0,1,0,0,0,0,0},
        {1,0,1,0,1,0,0,0,0},
        {0,1,0,0,0,1,0,0,0},
        {1,0,0,0,1,0,1,0,0},
        {0,1,0,1,0,1,0,1,0},
        {0,0,1,0,1,0,0,0,1},
        {0,0,0,1,0,0,0,1,0},
        {0,0,0,0,1,0,1,0,1},
        {0,0,0,0,0,1,0,1,0}
    };

    nodes=9;
    edges=12;

    source=0;
    goal=8;

    depth = IDDFS(source,goal,adj);

    if(depth == inf)printf("No solution Exist\n");
    else printf("Solution Found in depth limit ( %d ).\n",depth);
    return 0;
}
