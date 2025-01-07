#pragma once

#include <iostream>

template<typename T>
// Linked List의 요소인 Node 클래스
class Node
{
	// std::cout에 쉽게 출력할 수 있도록 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// 예외
	template<typename T>
	friend class LinkedList;

public:
	Node()
		: data()
	{

	}
	Node(T data)
		: data(data)
	{

	}

private:
	// 데이터 필드
	T data;

	// 링크 필드
	Node<T>* next = nullptr;
};