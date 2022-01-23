#pragma once
#include <iostream>

class Set
{
public:
    struct Item
    {
        int mValue;
        Item* mNext;
    };

    // Конструктора по умолчанию достаточно благодаря инициализации в классе
    Set() = default;
    Set(const Set& other);
    ~Set();
    
    Set& operator=(const Set& other);

    bool insert(int value);
    bool erase(int value);
    bool find(int value) const;
    bool empty() const;
    size_t size() const;

    friend std::ostream& operator << (std::ostream& out, const Set& outSet);

private:

    void clearSet();
    void copySet(const Set& other);

    size_t mSize = 0;
    Item* mFirst = nullptr;
};

std::ostream& operator << (std::ostream& out, const Set& outSet);
