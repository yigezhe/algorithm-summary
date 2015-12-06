
/*
 * 
The following pseudocode shows IDDFS implemented in terms of a recursive depth-limited DFS (called DLS).

procedure IDDFS(root)
    for depth from 0 to ∞
        found ← DLS(root, depth)
        if found ≠ null
            return found

procedure DLS(node, depth)
    if depth = 0 and node is a goal
        return node
    else if depth > 0
        foreach child of node
            found ← DLS(child, depth−1)
            if found ≠ null
                return found
    return null
*/
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	return 0;
}
