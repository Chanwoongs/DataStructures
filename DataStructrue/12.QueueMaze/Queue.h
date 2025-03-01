﻿#pragma once

#include <iostream>

// 큐 클래스.
template<typename T, int size = 10>
class Queue
{
public:
    Queue()
    {
        // 배열의 초기 값을 0으로 설정.
        memset(data, 0, sizeof(T) * size);
    }

    // 큐가 비었는지 확인하는 함수.
    bool IsEmpty() const
    {
        return front == rear;
    }

    // 큐가 가득찼는지 확인하는 함수.
    bool IsFull() const
    {
        return (rear + 1) % size == front;
    }

    // 데이터 추가.
    bool Enqueue(const T& value)
    {
        if (IsFull())
        {
            std::cout << "Error: 큐가 가득참.\n";
            return false;
        }

        // 데이터 추가할 인덱스 계산후 삽입.
        rear = (rear + 1) % size;
        data[rear] = value;

        return true;
    }

    // 데이터 추출.
    bool Dequeue(T& outValue)
    {
        if (IsEmpty())
        {
            std::cout << "Error: 큐가 비어있음.\n";
            return false;
        }

        // 데이터 추출할 위치를 찾아서 추출.
        front = (front + 1) % size;
        outValue = data[front];
        //data[front] = T();
        memset(&data[front], 0, sizeof(T));
        return true;
    }

    // 출력.
    void Print()
    {
        std::cout << "큐 내용: ";
        int max = (front < rear) ? rear : rear + size;
        for (int ix = front + 1; ix <= max; ++ix)
        {
            std::cout << data[ix % size] << " ";
        }

        std::cout << "\n";
    }


private:
    // 데이터가 출력되는 위치.
    int front = 0;

    // 데이터가 입력되는 위치.
    int rear = 0;

    // 데이터 저장소.
    T data[size];
};