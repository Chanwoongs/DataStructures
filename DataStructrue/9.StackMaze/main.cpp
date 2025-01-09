#include <iostream>

#include "Location2D.h"
#include "Stack.h"

// 맵 데이터 선언.
const size_t MAZE_SIZE = 20;
char map[MAZE_SIZE][MAZE_SIZE] =
{
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
    {'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// 이동하려는 위치가 유효한 위치인지 확인.
bool IsValidLocation(int row, int column)
{
    // 맵의 범위를 벗어났는지 확인.
    // 벗어 났으면 오류.
    if (row >= MAZE_SIZE || column >= MAZE_SIZE)
    {
        return false;
    }
    if (row < 0 || column < 0)
    {
        return false;
    }

    // 유효성 확인.
    // 이동하려는 위치가 0(이동 가능)이거나 e(목표 위치)라면 이동 가능 반환.
    return map[row][column] == '0' || map[row][column] == 'e';
}

int main()
{
    // 시작 위치 검색.
    int startRow = 0;
    int startColumn = 0;
    
    // 미로의 시작 지점 검색.
    for (int i = 0; i < MAZE_SIZE; ++i)
    {
        for (int j = 0; j< MAZE_SIZE; j++)
        {
            // 출력.
            std::cout << map[i][j] << ' ';

            // 시작 위치 탐색.
            if (map[i][j] == 's')
            {
                startRow = i;
                startColumn = j;
            }
        }
        std::cout << '\n';
    }

    // 시작 지점을 탐색하기 위해 스택에 삽입.
    Stack<Location2D> stack;
    stack.Push(Location2D(startRow, startColumn));

    //  미로 탐색.
    while (!stack.IsEmpty())
    {
        Location2D current;
        stack.Pop(current);
        
        int row = current.row;
        int column = current.column;

        // 탐색한 위치 출력.
        std::cout << "(" << row << ", " << column << ") ";

        // 도착했는지 확인.
        if (map[row][column] == 'e')
        {
            std::cout << "\n미로 탐색 성공\n";
            std::cin.get();
            return 0;
        }

        // 방문한 곳은 다른 문자로 설정
        map[row][column] = '.';

        // 상 하 좌 우 순서로 스택에 넣기
        if (IsValidLocation(row - 1, column))
        {
            stack.Push(Location2D(row - 1, column));
        }
        if (IsValidLocation(row + 1, column))
        {
            stack.Push(Location2D(row + 1, column));
        }
        if (IsValidLocation(row, column - 1))
        {
            stack.Push(Location2D(row, column - 1));
        }
        if (IsValidLocation(row, column + 1))
        {
            stack.Push(Location2D(row, column + 1));
        }
    }

    std::cout << "\n미로 탐색 실패\n";

    return 0;
}