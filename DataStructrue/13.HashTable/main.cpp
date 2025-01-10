#include <iostream>

#include "HashTable.h"

int main()
{
    // 해시 테이블 객체
    HashTable table;

    table.Add("Chan", "01012312312");
    table.Add("Chan", "01023123122");
    table.Add("Woong", "01068786442");
    table.Add("Bang", "01018790782");
    table.Add("Chanwoong", "01097665845");

    table.Print();
}