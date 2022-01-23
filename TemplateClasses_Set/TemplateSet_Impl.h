#ifndef TEMPLATESET_IMPL_H
#define TEMPLATESET_IMPL_H

#include "TemplateSet.h"

template <class T>
TemplateSet<T>::TemplateSet(const TemplateSet<T>& other)
{
    clearTemplateSet();
    copyTemplateSet(other);
}

template <class T>
TemplateSet<T>::~TemplateSet()
{
    clearTemplateSet();
}

template <class T>
TemplateSet<T>& TemplateSet<T>::operator=(const TemplateSet<T>& other)
{
    clearTemplateSet();

    copyTemplateSet(other);

    return *this;
}

template <class T>
bool TemplateSet<T>::insert(T value)
{
    TemplateSet<T>::Item* current = mFirst;

    if (mFirst == nullptr)
    {
        // Create new item using initializer list
        mFirst = new TemplateSet<T>::Item{ value, nullptr };
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

    TemplateSet<T>::Item* newItem = new TemplateSet<T>::Item{ value, nullptr };
    current->mNext = newItem;
    mSize++;

    return true;
}

template <class T>
bool TemplateSet<T>::erase(T value)
{
    if (mFirst == nullptr)
    {
        // TemplateSet is empty
        return false;
    }

    TemplateSet<T>::Item* current = mFirst;
    TemplateSet<T>::Item* prev = nullptr;

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

template <class T>
bool TemplateSet<T>::find(T value) const
{
    if (mFirst == nullptr)
    {
        return false;
    }

    TemplateSet<T>::Item* current = mFirst;

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

template <class T>
bool TemplateSet<T>::empty() const
{
    return mFirst == nullptr;
}

template <class T>
size_t TemplateSet<T>::size() const
{
    return mSize;
}

template <class T>
void TemplateSet<T>::clearTemplateSet()
{
    mSize = 0;

    TemplateSet<T>::Item* current = mFirst;

    while (current != nullptr)
    {
        TemplateSet::Item* deletable = current;
        current = current->mNext;
        delete deletable;
    }

    mFirst = nullptr;
}

template <class T>
void TemplateSet<T>::copyTemplateSet(const TemplateSet<T>& other)
{
    mFirst = new Item{ other.mFirst->mValue, nullptr };
    mSize = other.mSize;

    TemplateSet<T>::Item* currentOther = other.mFirst;
    TemplateSet<T>::Item* current = mFirst;

    while (currentOther->mNext != nullptr)
    {
        current->mNext = new Item{ currentOther->mNext->mValue, nullptr };
        currentOther = currentOther->mNext;
        current = current->mNext;
    }

}

#endif