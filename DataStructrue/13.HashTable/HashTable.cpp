#include "HashTable.h"

#include <iostream>

// 해시 함수
int GenerateHash(const char* keyString)
{
    // 전달 받은 문자열 길이 확인
    int length = strlen(keyString);

    // 생성할 키
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = hash * 31 + keyString[i];
    }

    return hash;
}

void HashTable::Add(const char* key, const char* value)
{
    // 인덱스 구하기
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 저장할 위치에 있는 컨테이너 가져오기
    auto& position = table[bucketIndex];

    // 검색
    // 해시 테이블은 중복을 허용하지 않음
    for (int i = 0; i < (int)position.size(); i++)
    {
        // 키 비교
        if (strcmp(position[i].key, key) == 0)
        {
            std::cout << "이미 같은 키가 저장되어 있어 삽입 실패\n";
            return;
        }
    }

    // 데이터 삽입
    position.push_back(Entry(key, value));
}

void HashTable::Delete(const char* key)
{
    // 인덱스 구하기
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 삭제할 위치에 있는 컨테이너 가져오기
    auto& position = table[bucketIndex];

    // 검색
    for (int i = 0; i < (int)position.size(); i++)
    {
        // 키 비교
        if (strcmp(position[i].key, key) == 0)
        {
            position.erase(position.begin() + i);
            std::cout << "키: " << key << " 항목을 삭제\n";
            return;
        }
    }
    
    // 검색 실패
    std::cout << "삭제할 항목을 찾지 못했습니다\n";
}

bool HashTable::Find(const char* key, Entry& outValue)
{  
    // 인덱스 구하기
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 삭제할 위치에 있는 컨테이너 가져오기
    auto& position = table[bucketIndex];

    // 예외 처리
    if (position.size() == 0)
    {
        std::cout << "해당 키로 항목을 찾지 못했습니다.";
    }

    // 검색
    for (int i = 0; i < (int)position.size(); i++)
    {
        // 키 비교
        if (strcmp(position[i].key, key) == 0)
        {
            outValue = position[i];

            std::cout << "키: " << key << " 를 찾았습니다.\n";
            return true;
        }
    }
    std::cout << "해당 키로 항목을 찾지 못했습니다.";

    return false;
}

void HashTable::Print()
{
    for (int i = 0; i < bucketCount; i++)
    {
        // 건너뛰기
        if (table[i].size() == 0)
        {
            continue;
        }

        for (auto& entry : table[i])
        {
            std::cout << "키: " << entry.key << " 값: " << entry.value << '\n';
        }
    }
}
