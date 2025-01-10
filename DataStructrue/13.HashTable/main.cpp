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

    Pair<std::string, std::string> value;
    if (table.Find("Chan", value))
    {
        std::cout << "키: Chan 항목을 찾았습니다\n";
    }
    else
    {
        std::cout << "키: Chan 항목을 못 찾았습니다\n";
    }
    
    table.Delete("Bang");

    table.Print();
}