#include<stdio.h>
#define N 100
struct point {
    int x,y;
};
int main() {
    //我先用dfs，bfs来找到这个路径！
    char map[N][N];
    int m,n;
    scanf("%d%d",&m,&n);
    int i,j;
    struct point start;
    struct point goal;
    for(i=0; i<m; i++) {
        char line[N+1];
        scanf("%s",line);
        for(j=0; j<n; j++) {
            map[i][j]=line[j];
            if(map[i][j]=='s') {
                start.x=i;
                start.y=j;
            }
            if(map[i][j]=='t') {
                goal.x=i;
                goal.y=j;
            }

        }
    }
    printf("(%d,%d)-(%d,%d)\n",start.x,start.y,goal.x,goal.y);
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }

    int visit[N][N];
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            visit[i][j]=0;
        }
    }
    struct point queue[2*N];
    int begin=0;
    int end=0;
    queue[end].x=start.x;
    queue[end].y=start.y;
    visit[start.x][start.y]=1;
    end++;
    printf("%d < %d\n",begin,end);
    while (begin < end) {
	    /*
        for(i=begin; i<end; i++) {
            printf("(%d,%d)-",queue[i].x,queue[i].y);
        }
        printf("\n");
	*/

        struct point top;
        top.x=queue[begin].x;
        top.y=queue[begin].y;
        begin++;

        if(goal.x==top.x && goal.y==top.y) {
            break;
        }
        //先实现上下左右四个方向！
        if(top.x+1<m && !visit[top.x+1][top.y] ) {
            queue[end].x=top.x+1;
            queue[end].y=top.y;
            visit[top.x+1][top.y]=visit[top.x+1][top.y]+1;
            end++;
        }
        if( top.x-1>=0 && !visit[top.x-1][top.y]) {
            queue[end].x=top.x-1;
            queue[end].y=top.y;
            visit[top.x-1][top.y]=visit[top.x][top.y]+1;
            end++;
        }
        if(top.y-1>=0 && !visit[top.x][top.y-1] ) {
            queue[end].x=top.x;
            queue[end].y=top.y-1;
            visit[top.x][top.y-1]=visit[top.x][top.y]+1;
            end++;
        }
        if( top.y+1<n && !visit[top.x][top.y+1]) {
            queue[end].x=top.x;
            queue[end].y=top.y+1;
            visit[top.x][top.y+1]=visit[top.x][top.y]+1;
            end++;
        }
    }
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%3d",visit[i][j]);
        }
        printf("\n");
    }

    return 0;
}
