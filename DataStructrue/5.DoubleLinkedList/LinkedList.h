#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
public:
	// 오류가 발생했을 때 실행할 함수를 저장할 함수 포인터 변수
	using ListEmptyErrorEvent = void(*)();

public:
	LinkedList()
		: first(new Node<T>()), last(new Node<T>())
	{
		// 시작할 때는 first와 last가 서로 가리키도록 설정
		first->next = last;
		last->next = first;
	}

	LinkedList(ListEmptyErrorEvent errorHandler)
		: LinkedList<T>()
	{
		errorEvent = errorHandler;
	}

	~LinkedList()
	{
		if (count > 0)
		{
			Clear();
		}

		delete first;
		delete last;
	}

	// 리스트 안에 모든 노드를 제거하는 함수
	void Clear()
	{
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 첫 노드에서 부터 시작
		Node<T>* current = first->next;

		// 모든 노드 삭제
		while (current != last)
		{
			// 삭제 로직
			Node<T>* next = current->next;
			delete current;
			current = next;
		}

		// 남은 데이터 정리
		count = 0;
		first->next = last;
		last->previous = first;
	}

	// 리스트가 비어있을 때 오류 이벤트를 발생시키는 함수
	void RaiseEmptyErrorEvent()
	{
		// 함수 포인터가 설정되었으면 해당 함수 호출
		if (errorEvent != nullptr)
		{
			errorEvent();
		}
	}

	// 헤드에 추가하는 함수
	void AddToFirst(const T& data)
	{
		// 새 노드 생성
		Node<T>* newNode = new Node<T>(data);

		Node<T>* next = first->next;
		newNode->next = next;
		newNode->previous = first;
		first->next = newNode;
		next->previous = newNode;
		
		// 저장된 노드 수 증가
		++count;
	}

	// 맨 뒤에 삽입하는 함수
	void AddToLast(const T& data)
	{
		// 새 노드 생성
		Node<T>* newNode = new Node<T>(data);

		Node<T>* previous = last->previous;
		newNode->next = last;
		newNode->previous = previous;
		last->previous = newNode;
		previous->next = newNode;

		// 저장된 노드 수 증가
		++count;
	}

	// 데이터를 지정해 검색 후 삭제하는 함수
	void Delete(const T& data)
	{
		// 예외 처리
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}
		
		// 삭제할 노드 검색
		Node<T>* deleteNode = first->next;
		while (deleteNode != last)
		{
			if (deleteNode->data == data) 
			{
				break;
			}
			// 다음 노드로 이동
			deleteNode = deleteNode->next;
		}

		if (deleteNode == nullptr)
		{
			std::cout << "값 " << data << "를 찾지 못했습니다.\n";
			return;
		}
		else
		{
			deleteNode->previous->next = deleteNode->next;
			deleteNode->next->previous = deleteNode->previous;

			delete deleteNode;
			--count;
		}
	}

	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;

		while (current != nullptr && current != last)
		{
			if (current->data == data) 
			{
				return current;
			}

			current = current->next;
		}

		return nullptr;
	}

	// 저장된 요소 출력 함수
	void Print()
	{
		Node<T>* current = first->next;

		while (current != nullptr && current != last)
		{
			std::cout << "Data: " << current->data << '\n';
			current = current->next;
		}
	}

	// 저장된 요소의 수 반환(Getter)
	__forceinline int Count() const { return count; }

private:
	// 헤드 노드
	Node<T>* first = nullptr;

	// 테일 노드
	Node<T>* last = nullptr;

	// 저장된 자료 수
	int count = 0;

	// 함수 포인터 변수
	ListEmptyErrorEvent errorEvent = nullptr;
}; 