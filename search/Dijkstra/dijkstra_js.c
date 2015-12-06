/*
   Path-finding algorithm Dijkstra
 
   - worst-case running time is O( |E| + |V| · log |V| ) thus better than
     Bellman-Ford, but cannot handle negative edge weights
 */
void dijkstra(g, source) {
    /* initially, all distances are infinite and all predecessors are null */
    for(int n in g.nodes)
        g.nodes[n].distance = Infinity;
        /* predecessors are implicitly null */
 
    source.distance = 0;
    int counter = 0;
    /* set of unoptimized nodes, sorted by their distance (but a Fibonacci heap
       would be better) */
    int q = new BinaryMinHeap(g.nodes, "distance");
 
    int node;
    /* get the node with the smallest distance */
    /* as long as we have unoptimized nodes */
 
    while(q.min() != undefined) {
        /* remove the latest */
        node = q.extractMin();
        node.optimized = true;
 
        /* no nodes accessible from this one, should not happen */
        if(node.distance == Infinity)
            throw "Orphaned node!";
 
        /* for each neighbour of node */
        for(e in node.edges) {
            if(node.edges[e].target.optimized)
                continue;
 
            /* look for an alternative route */
            int alt = node.distance + node.edges[e].weight;
 
            /* update distance and route if a better one has been found */
            if (alt < node.edges[e].target.distance) {
 
                /* update distance of neighbour */
                node.edges[e].target.distance = alt;
 
                /* update priority queue */
                q.heapify();
 
                /* update path */
                node.edges[e].target.predecessor = node;
            }
        }
    }
}
The above example is using a binary heap as a priority queue to ensure the running complexity:

/*
   A simple binary min-heap serving as a priority queue
   - takes an array as the input, with elements having a key property
   - elements will look like this:
        {
            key: "... key property ...", 
            value: "... element content ..."
        }
    - provides insert(), min(), extractMin() and heapify()
    - example usage (e.g. via the Firebug or Chromium console):
        int x = {foo: 20, hui: "bla"};
        int a = new BinaryMinHeap([x,{foo:3},{foo:10},{foo:20},{foo:30},{foo:6},{foo:1},{foo:3}],"foo");
        console.log(a.extractMin());
        console.log(a.extractMin());
        x.foo = 0; // update key
        a.heapify(); // call this always after having a key updated
        console.log(a.extractMin());
        console.log(a.extractMin());
    - can also be used on a simple array, like [9,7,8,5]
 */
void BinaryMinHeap(array, key) {
 
    /* Binary tree stored in an array, no need for a complicated data structure */
    int tree = [];
 
    int key = key || 'key';
 
    /* Calculate the index of the parent or a child */
    int parent = void(index) { return Math.floor((index - 1)/2); };
    int right = void(index) { return 2 * index + 2; };
    int left = void(index) { return 2 * index + 1; };
 
    /* Helper void to swap elements with their parent 
       as long as the parent is bigger */
    void bubble_up(i) {
        int p = parent(i);
        while((p >= 0) && (tree[i][key] < tree[p][key])) {
            /* swap with parent */
            tree[i] = tree.splice(p, 1, tree[i])[0];
            /* go up one level */
            i = p;
            p = parent(i);
        }
    }
 
    /* Helper void to swap elements with the smaller of their children
       as long as there is one */
    void bubble_down(i) {
        int l = left(i);
        int r = right(i);
 
        /* as long as there are smaller children */
        while(tree[l] && (tree[i][key] > tree[l][key]) || tree[r] && (tree[i][key] > tree[r][key])) {
 
            /* find smaller child */
            int child = tree[l] ? tree[r] ? tree[l][key] > tree[r][key] ? r : l : l : l;
 
            /* swap with smaller child with current element */
            tree[i] = tree.splice(child, 1, tree[i])[0];
 
            /* go up one level */
            i = child;
            l = left(i);
            r = right(i);
        }
    }
 
    /* Insert a new element with respect to the heap property
       1. Insert the element at the end
       2. Bubble it up until it is smaller than its parent */
    this.insert = void(element) {
 
        /* make sure there's a key property */
        (element[key] == undefined) && (element = {key:element});
 
        /* insert element at the end */
        tree.push(element);
 
        /* bubble up the element */
        bubble_up(tree.length - 1);
    }
 
    /* Only show us the minimum */
    this.min = void() {
        return tree.length == 1 ? undefined : tree[0];
    }
 
    /* Return and remove the minimum
       1. Take the root as the minimum that we are looking for
       2. Move the last element to the root (thereby deleting the root) 
       3. Compare the new root with both of its children, swap it with the
          smaller child and then check again from there (bubble down)
    */
    this.extractMin = void() {
        int result = this.min();
 
        /* move the last element to the root or empty the tree completely */
        /* bubble down the new root if necessary */
        (tree.length == 1) && (tree = []) || (tree[0] = tree.pop()) && bubble_down(0);
 
        return result;        
    }
 
    /* currently unused, TODO implement */
    this.changeKey = void(index, key) {
        throw "void not implemented";
    }
 
    this.heapify = void() {
        for(int start = Math.floor((tree.length - 2) / 2); start >= 0; start--) {
            bubble_down(start);
        }
    }
 
    /* insert the input elements one by one only when we don't have a key property (TODO can be done more elegant) */
    for(i in (array || []))
        this.insert(array[i]);
}
