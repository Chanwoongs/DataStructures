#include <iostream>

#include "ExpStack.h"

int main()
{
    // 스택 개체
    ExpStack stack;

    std::cout << "첫 번째 게임 종료 - 경험치 140\n";
    stack.Push(140.0f);

    std::cout << "두 번째 게임 종료 - 경험치 180\n";
    stack.Push(180.0f);

    std::cout << "세 번째 게임 종료 - 경험치 200\n";
    stack.Push(200.0f);
   
    while (!stack.IsEmpty())
    {
        float value;
        if (stack.Pop(value))
        {
            std::cout << "현재 경험치: " << value << '\n';
        }
    }

}