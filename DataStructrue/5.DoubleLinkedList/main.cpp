﻿#include <iostream>
#include "LinkedList.h"

// 오류함수
// 이벤트 리스너(Listener) 함수
void OnListEmptyError()
{
	std::cout << "데이터가 없습니다.\n";
}

int main()
{
	LinkedList<int> list(OnListEmptyError);

	list.Delete(100);

	list.AddToFirst(10);
	list.AddToFirst(20);
	list.AddToFirst(30);
	list.AddToFirst(40);
	list.AddToFirst(50);

	std::cout << "리스트 출력\n";
	list.Print();

	list.AddToLast(100);
	list.AddToLast(90);
	list.AddToLast(80);
	list.AddToLast(70);
	list.AddToLast(60);

	std::cout << "리스트 출력\n";
	list.Print();

	list.Delete(10);
	list.Delete(30);
	list.Delete(60);
	list.Delete(90);

	std::cout << "삭제 후 리스트 출력\n";
	list.Print();
}