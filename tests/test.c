#include <stdio.h>
#include <stdbool.h>

// Structure to store coordinates
typedef struct {
    int x;
    int y;
} Point;

// Function to check if a given point is within the map boundaries
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Function to perform breadth-first search
bool canReachExit(char** map, int rows, int cols, Point start) {
    // Create a queue for BFS
    Point queue[rows * cols];
    int front = 0, rear = 0;

    // Array to keep track of visited cells
    bool visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    // Define possible movements (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Enqueue the starting point and mark it as visited
    queue[rear++] = start;
    visited[start.x][start.y] = true;

    // Perform BFS
    while (front < rear) {
        Point current = queue[front++];

        // Check if the current point is the exit 'E'
        if (map[current.x][current.y] == 'E') {
            return true;
        }

        // Explore the neighboring cells
        for (int i = 0; i < 4; i++) {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];

            // Check if the next point is valid and can be moved into
            if (isValid(nextX, nextY, rows, cols) &&
                (map[nextX][nextY] == '0' || map[nextX][nextY] == 'C' || map[nextX][nextY] == 'E') &&
                !visited[nextX][nextY]) {
                // Enqueue the next point and mark it as visited
                Point nextPoint = {nextX, nextY};
                queue[rear++] = nextPoint;
                visited[nextX][nextY] = true;
            }
        }
    }

    // Exit 'E' was not reached
    return false;
}

int main() {
    // char* map[] = {
    //     "1111111111111111111111111111111111",
    //     "10P100000100000C000001000C00001001",
    //     "101001C100100000101001010010010101",
    //     "101001001010101000100101010001E101",
    //     "1000C1000C00C0000000000100010000C1",
    //     "1111111111111111111111111111111111"
    // };
    char* map[] = {
        "11111111111111111111",
        "10P00C01E0010C010C01",
        "11111111111111111111"
    };

    int rows = 6;
    int cols = 35;
    Point start = {1, 2};  // Starting position of the player

    bool canReach = canReachExit(map, rows, cols, start);
    if (canReach) {
        printf("The player can reach the exit.\n");
    } else {
        printf("The player cannot reach the exit.\n");
    }

    return 0;
}
