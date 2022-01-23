#include "Set.h"

Set::Set(const Set& other)
{
    clearSet();
    copySet(other);
}

Set::~Set()
{
    clearSet();
}

Set& Set::operator=(const Set& other)
{
    clearSet();

    copySet(other);

    return *this;
}

bool Set::insert(int value)
{
    Set::Item* current = mFirst;

    if (mFirst == nullptr)
    {
        // Create new item using initializer list
        mFirst = new Set::Item { value, nullptr};
        mSize++;
        return true;
    }

    // Вставка в конец не самая оптимальная с точки зрения реализации множества,
    // но самая наглядная
    while (current->mNext != nullptr)
    {
        if (current->mValue == value)
        {
            // Элемент уже есть в множестве
            return false;
        }

        current = current->mNext;
    }

    if (current->mValue == value)
    {
        // Элемент уже есть в множестве и он последний
        return false;
    }

    Set::Item* newItem = new Set::Item{ value, nullptr };
    current->mNext = newItem;
    mSize++;

    return true;
}

bool Set::erase(int value)
{
    if (mFirst == nullptr)
    {
        // Set is empty
        return false;
    }

    Set::Item* current = mFirst;
    Set::Item* prev = nullptr;


    while (current != nullptr)
    {
        // Если элемент найден
        if (current->mValue == value)
        {
            // Если найденный - первый элемент
            if (prev == nullptr)
            {
                mFirst = current->mNext;
            }
            else
            {
                prev->mNext = current->mNext;
            }

            delete current;
            
            return true;
        }

        prev = current;
        current = current->mNext;
    }

    return false;
}

bool Set::find(int value) const
{
    if (mFirst == nullptr)
    {
        return false;
    }

    Set::Item* current = mFirst;

    while (current != nullptr)
    {
        if (current->mValue == value)
        {
            return true;
        }

        current = current->mNext;
    }

    return false;
}

bool Set::empty() const
{
    return mFirst == nullptr;
}

size_t Set::size() const
{
    return mSize;
}

void Set::clearSet()
{
    mSize = 0;

    Set::Item* current = mFirst;

    while (current != nullptr)
    {
        Set::Item* deletable = current;
        current = current->mNext;
        delete deletable;
    }

    mFirst = nullptr;
}

void Set::copySet(const Set& other)
{
    mFirst = new Item{ other.mFirst->mValue, nullptr};
    mSize = other.mSize;

    Set::Item* currentOther = other.mFirst;
    Set::Item* current = mFirst;

    while (currentOther->mNext != nullptr)
    {
        current->mNext = new Item{ currentOther->mNext->mValue, nullptr };
        currentOther = currentOther->mNext;
        current = current->mNext;
    }

}

std::ostream& operator << (std::ostream& out, const Set& outSet)
{
    Set::Item* current = outSet.mFirst;

    out << "Set (size = " << outSet.mSize << "): ";
    
    while (current->mNext != nullptr)
    {
        out << current->mValue << ", ";
        current = current->mNext;
    }

    out << current->mValue << std::endl;

    return out;
}
