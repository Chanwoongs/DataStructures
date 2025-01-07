﻿#include <iostream>
#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LinkedList list;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(40);
	list.Insert(50);

	std::cout << "---------- 리스트 데이터 출력 ----------\n";
	list.Print();

	list.Delete(30);
	list.Delete(50);
	list.Delete(500);

	std::cout << "---------- 리스트 데이터 삭제 후 출력 ----------\n";

	list.Print();
}