#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	if (head != nullptr)
	{
		Node* current = head;
		Node* deleteNode = nullptr;

		while (current != nullptr)
		{
			deleteNode = current;
			current = current->next;

			delete deleteNode;
		}
	}
}

void LinkedList::AddToHead(int data)
{
	// 새 노드 생성
	Node* newNode = new Node(data);
	
	// 1. 헤드가 없는 경우
	if (head == nullptr)
	{
		head = newNode;
	}
	// 2. 헤드가 있는 경우
	else
	{
		// 새 노드의 다음 노드를 기존의 헤드 노드로 설정
		newNode->next = head;
		// 헤드 노드를 새 노드로 교체
		head = newNode;
	}

	// 저장된 노드 수 증가
	++count;
}

void LinkedList::Insert(int data)
{
	// 새 노드 생성
	Node* newNode = new Node(data);

	// 삽입할 위치 찾기
	// 1. Head가 비어있는 경우
	if (head == nullptr)
	{
		head = newNode;
	}
	// 삽입할 위치를 검색 후 노드 삽입
	else
	{
		// 노드 포인터 2개를 사용해 검색
		Node* current = head;
		Node* trail = nullptr;

		// 위치 검색
		while (current != nullptr)
		{
			// 값 비교
			if (data <= current->data)
			{
				break;
			}

			// 다음 노드로 이동
			// trail에 위치 저장
			trail = current;
			current = current->next;
		}

		// 검색된 결과를 확인해서 처리
		if (current == head)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			trail->next = newNode;
			newNode->next = current;
		}
	}
	// 요소 수 증가
	++count;
}

void LinkedList::Delete(int data)
{
	// 예외 처리
	if (head == nullptr)
	{
		std::cout << "리스트가 비어있어 삭제가 불가능합니다.\n";
		return;
	}

	// 삭제할 노드 찾기
	Node* current = head;
	Node* trail = nullptr;

	while (current != nullptr)
	{
		if (current->data == data)
		{
			break;
		}

		trail = current;
		current = current->next;		
	}

	if (current == nullptr)
	{
		std::cout << "값 " << data << "를 찾지 못했습니다.\n";
		return;
	}

	if (current == head)
	{
		head = head->next;
	} 
	else
	{
		trail->next = current->next;
	}
	delete current;
	
	--count;
}

void LinkedList::Print()
{
	Node* current = head;

	while (current != nullptr)
	{
		std::cout << *current << '\n';
		current = current->next;
	}
}
