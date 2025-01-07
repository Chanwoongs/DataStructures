#pragma once

class Node;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// 헤드에 추가하는 함수
	void AddToHead(int data);

	// 맨 뒤에 삽입하는 함수
	void Insert(int data);

	// 데이터를 지정해 검색 후 삭제하는 함수
	void Delete(int data);

	// 저장된 요소 출력 함수
	void Print();

	// 저장된 요소의 수 반환(Getter)
	__forceinline int Count() const { return count; }

private:
	// 헤드 노드
	Node* head = nullptr;

	// 저장된 자료 수
	int count = 0;
};