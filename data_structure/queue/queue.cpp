class StateNode {
    int xPos;
    int yPos;
    int moveCount;
}

class MyQueue {
    StateNode[] queueData = new StateNode[2500];
    int queueFront = 0;
    int queueBack = 0;

    void Enqueue(StateNode node) {
        queueData[queueBack] = node;
        queueBack++;
    }

    StateNode Dequeue() {
        StateNode returnValue = null;
        if (queueBack > queueFront) {
            returnValue = queueData[queueFront];
            QueueFront++;
        }
        return returnValue;
    }

    boolean isNotEmpty() {
        return (queueBack > queueFront);
    }
}
MyQueue queue = new MyQueue();
queue.Enqueue(initialState);
while (queue.isNotEmpty()) {
    StateNode curState = queue.Dequeue();
    if (curState == destState)
        return curState.moveCount;
    for (int dir = 0; dir < 3; dir++) {
        if (CanMove(curState, dir))
            queue.Enqueue(MoveState(curState, dir));
    }
}
