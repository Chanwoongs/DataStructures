#pragma once

#include <vector>

#include "Pair.h"

class HashTable
{
    // Alias(별칭)
    using Entry = Pair<const char*, const char*>;

public:
    HashTable() = default;
    ~HashTable() = default;

    void Add(const char* key, const char* value);
    void Delete(const char* key);
    bool Find(const char* key, Entry& outValue);
    void Print();

private:
    // 내장 저장소의 크기 (소수(Prime Number)를 사용하는 것이 유리)
    static const int bucketCount = 19;
    std::vector<Entry> table[bucketCount];
};