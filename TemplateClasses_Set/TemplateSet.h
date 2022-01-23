#ifndef TEMPLATESET_H
#define TEMPLATESET_H

#include <iostream>

template <typename T>
class TemplateSet;

template <typename T>
std::ostream& operator<< (std::ostream& out, const TemplateSet<T>& outTemplateSet);

template<class T>
class TemplateSet
{
public:
    struct Item
    {
        T mValue;
        Item* mNext;
    };

    // Конструктора по умолчанию достаточно благодаря инициализации в классе
    TemplateSet() = default;
    TemplateSet(const TemplateSet& other);
    ~TemplateSet();

    TemplateSet& operator=(const TemplateSet& other);

    bool insert(T value);
    bool erase(T value);
    bool find(T value) const;
    bool empty() const;
    size_t size() const;

    friend std::ostream& operator<< <> (std::ostream& out, const TemplateSet<T>& outTemplateSet);

private:

    void clearTemplateSet();
    void copyTemplateSet(const TemplateSet& other);

    size_t mSize = 0;
    Item* mFirst = nullptr;
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const TemplateSet<T>& outTemplateSet)
{
    auto* current = outTemplateSet.mFirst;

    out << "TemplateSet (size = " << outTemplateSet.mSize << "): ";

    while (current->mNext != nullptr)
    {
        out << current->mValue << ", ";
        current = current->mNext;
    }

    out << current->mValue << std::endl;

    return out;
}

#endif

#include "TemplateSet_Impl.h"
