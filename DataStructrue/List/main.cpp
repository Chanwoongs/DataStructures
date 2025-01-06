#include <iostream>
#include <vector>

// 반복자 (Iterator 클래스)
template<typename Vector>
class VectorIterator
{
public:
	// 타입 지정
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{

	}
	
	// 포인터 증감 연산자 오버로딩
	// 전위 증가 연산자
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}
	// 후위 증가 연산자
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// 전위 감소 연산자
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}
	// 후위 감소 연산자
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// 인덱스 연산자 오버로딩
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// 포인터 연산자 오버로딩
	PointerType operator->()
	{
		return pointer;
	}

	// 값 반환 연산자 오버로딩
	ReferenceType operator*()
	{
		return *pointer;
	}

	// 비교 연산자
	bool operator==(const VectorIterator& other) const
	{
		return pointer == other.pointer;
	}
	bool operator!=(const VectorIterator& other) const
	{
		return pointer != other.pointer;
		//return !(*this == other);
	}

private:
	PointerType pointer;
};

// 동적 배열 (리스트) 클래스
// 템플릿
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// 초기 데이터 공간 설정
		data = new T[capacity];
	}
	~List()
	{
		// 포인터가 가리키는 힙 배열 변수 삭제
		if (data != nullptr)
		{
			delete[] data;
		}
	}
	
	// 원소 추가
	void PushBack(const T& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		data[count] = value;

		// 저장된 요소의 수 증가 처리
		++count;
	}

	// Move 추가
	void PushBack(T&& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		data[count] = std::move(value);

		// 저장된 요소의 수 증가 처리
		++count;
	}
	
	// 접근 함수
	T& At(int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}
	const T& At(int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 연산자 오버로딩
	T& operator[](int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}
	const T& operator[](int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// Iterator 관련 함수
	Iterator begin()
	{
		return Iterator(data);
	}
	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter
	// 요소 수 반환
	int Count() const { return count; }

	// 저장 용량 반환
	int Capacity() const { return capacity; }

	// 배열 주소 반환
	T* Data() const { return data; }

private:
	// 저장할 공간이 부족할 때 공간을 늘리는 함수
	void ReAllocate(int newCapacity)
	{
		// 1. 새로운 메모리 공간 할당(Allocate)
		// 2. 기존의 데이터 복사
		// 3. 기존 데이터 및 임시 데이터 삭제
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 복사
		//for (int i = 0; i < count; i++)
		//{
		//	newBlock[i] = std::move(data[i]);
		//}
		memcpy(newBlock, data, sizeof(T) * count);

		delete data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	// 데이터 선언 (힙에 할당)
	T* data = nullptr;

	// 용량
	int capacity = 2;

	// 배열 원소의 수
	int count = 0;
};

int main()
{
	List<int> list;

	for (int i = 0; i < 100; ++i)
	{
		list.PushBack(i);
	}

	std::cout << list.Count() << ", " << list.Capacity() << '\n';

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity());
	std::cout << buffer;
	//const int& value = list[128];

	std::vector<int> vector
	{
		1, 2, 3, 4, 5
	};

	snprintf(buffer, 256, "%d, %d\n", static_cast<int>(vector.size()), static_cast<int>(vector.capacity()));
	std::cout << buffer << '\n';

	// Range-Based Loop / Range Loop
	for (const auto& item : vector)
	{
		std::cout << item << ' ';
	}
	for (const auto& item : list)
	{
		std::cout << item << ' ';
	}
} 