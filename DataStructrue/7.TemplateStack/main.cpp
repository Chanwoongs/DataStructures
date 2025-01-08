#include <iostream>

#include "Stack.h"

int main()
{
    // 스택 객체
    Stack<float, 20> stack;

    if (stack.Push(140.0f))
    {
        std::cout << "첫 번째 게임 종료 - 경험치 140\n";
    }
    if (stack.Push(180.0f))
    {
        std::cout << "두 번째 게임 종료 - 경험치 180\n";
    }
    if (stack.Push(200.0f))
    {
        std::cout << "세 번째 게임 종료 - 경험치 200\n";
    }

    while (!stack.IsEmpty())
    {
        float value;
        if (stack.Pop(value))
        {
            std::cout << "현재 경험치: " << value << '\n';
        }
    }
}