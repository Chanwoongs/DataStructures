#pragma once

#include <vector>
#include <string>

#include "Pair.h"

class HashTable
{
    // Alias(별칭)
    using Entry = Pair<std::string, std::string>;

public:
    HashTable() = default;
    ~HashTable() = default;

    void Add(std::string key, std::string value);
    void Delete(std::string key);
    bool Find(std::string key, Entry& outValue);
    void Print();

private:
    // 내장 저장소의 크기 (소수(Prime Number)를 사용하는 것이 유리)
    static const int bucketCount = 19;
    std::vector<Entry> table[bucketCount];
};