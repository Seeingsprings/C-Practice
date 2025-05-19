#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>  // 用于_getch()
using namespace std;

// 迷宫类 - 封装游戏逻辑
class MazeGame {
private:
    vector<vector<int>> maze;  // 迷宫布局
    int rows, cols;            // 迷宫大小
    int playerX, playerY;      // 玩家位置
    int exitX, exitY;          // 出口位置
    int steps;                 // 步数记录
    bool gameOver;             // 游戏状态

public:
    MazeGame(int r = 20, int c = 20) : rows(r), cols(c), steps(0), gameOver(false) {
        srand(time(nullptr));
        initializeMaze();
    }

    // 初始化迷宫
    void initializeMaze() {
        // 创建全墙迷宫
        maze.assign(rows, vector<int>(cols, 1));
        
        // 生成随机通路 (使用深度优先搜索算法)
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> stack;
        
        // 起点
        playerX = 1;
        playerY = 1;
        maze[playerX][playerY] = 0;
        visited[playerX][playerY] = true;
        stack.push_back({playerX, playerY});
        
        // 方向数组: 上、右、下、左
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while (!stack.empty()) {
            int x = stack.back().first;
            int y = stack.back().second;
            stack.pop_back();
            
            // 随机打乱方向顺序
            vector<int> dirs = {0, 1, 2, 3};
            for (int i = 0; i < 4; ++i) {
                int j = rand() % 4;
                swap(dirs[i], dirs[j]);
            }
            
            bool hasNeighbor = false;
            for (int dir : dirs) {
                int nx = x + 2 * dx[dir];
                int ny = y + 2 * dy[dir];
                
                if (nx > 0 && nx < rows - 1 && ny > 0 && ny < cols - 1 && !visited[nx][ny]) {
                    // 打通墙壁
                    maze[x + dx[dir]][y + dy[dir]] = 0;
                    maze[nx][ny] = 0;
                    visited[nx][ny] = true;
                    stack.push_back({x, y});
                    stack.push_back({nx, ny});
                    hasNeighbor = true;
                    break;
                }
            }
        }
        
        // 设置出口
        exitX = rows - 2;
        exitY = cols - 2;
        maze[exitX][exitY] = 3; // 3表示出口
    }

    // 绘制迷宫
    void draw() const {
        system("cls"); // Windows清屏
        cout << "迷宫游戏 - 按 WASD 移动，Q 退出" << endl;
        cout << "步数: " << steps << endl << endl;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == playerX && j == playerY)
                    cout << '@'; // 玩家
                else if (maze[i][j] == 0)
                    cout << ' '; // 通路
                else if (maze[i][j] == 1)
                    cout << '#'; // 墙
                else if (maze[i][j] == 3)
                    cout << 'E'; // 出口
            }
            cout << endl;
        }
    }

    // 处理用户输入
    void handleInput(char input) {
        if (gameOver) return;
        
        int newX = playerX;
        int newY = playerY;
        
        switch (input) {
            case 'w': newX--; break;
            case 's': newX++; break;
            case 'a': newY--; break;
            case 'd': newY++; break;
            case 'q': gameOver = true; return;
            default: return;
        }
        
        // 边界检查
        if (newX < 0 || newX >= rows || newY < 0 || newY >= cols)
            return;
            
        // 碰撞检测
        if (maze[newX][newY] == 1) // 墙
            return;
            
        // 更新位置
        playerX = newX;
        playerY = newY;
        steps++;
        
        // 检查是否到达出口
        if (playerX == exitX && playerY == exitY) {
            gameOver = true;
        }
    }

    // 检查游戏是否结束
    bool isGameOver() const {
        return gameOver;
    }

    // 获取步数
    int getSteps() const {
        return steps;
    }
};

int main() {
    MazeGame game(15, 30); // 创建15x30的迷宫
    
    while (!game.isGameOver()) {
        game.draw();
        char input = tolower(_getch()); // 无回车输入
        game.handleInput(input);
    }
    
    game.draw(); // 显示最终状态
    cout << "\n恭喜你！用了 " << game.getSteps() << " 步成功走出迷宫！" << endl;
    
    return 0;
}