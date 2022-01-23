#ifndef TEMPLATESET_H
#define TEMPLATESET_H

#include <iostream>

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

    friend std::ostream& operator<< (std::ostream& out, const TemplateSet<T>& outTemplateSet)
    {
        TemplateSet<T>::Item* current = outTemplateSet.mFirst;

        out << "TemplateSet (size = " << outTemplateSet.mSize << "): ";

        while (current->mNext != nullptr)
        {
            out << current->mValue << ", ";
            current = current->mNext;
        }

        out << current->mValue << std::endl;

        return out;
    }

private:

    void clearTemplateSet();
    void copyTemplateSet(const TemplateSet& other);

    size_t mSize = 0;
    Item* mFirst = nullptr;
};

#endif

#include "TemplateSet_Impl.h"
