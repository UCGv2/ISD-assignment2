//
// Created by fours on 9/11/2018.
//

#include "ScopedArray.h"

template <typename T>
ScopedArray<T>::ScopedArray(T* a)
    : mArray(a)
{
}

template <typename T> ScopedArray<T>::~ScopedArray()
{
    delete[](mArray);
    mArray = nullptr;
}

template <typename T> T* ScopedArray<T>::get() const
{
    return mArray;
}
/**
 * @brief Deletes the current array in mArray and replaces it with parameter "r"
 * @param r is a new array or nullptr
 * @post mArray points to parameter "next"
 */
template <typename T> void ScopedArray<T>::reset(T* next)
{
    if (next != mArray) {
        delete[](mArray);
        mArray = next;
    }
}
/**
 * @brief Swaps the mArray fields of two different SimpleArrays
 * @details Swaps the mArray fields of two SimpleArrays provided their mArray fields
 * are pointing to different locations. If they are the same, nothing needs to happen.
 * @param a2 is a different SimpleArray
 */
template <typename T> void ScopedArray<T>::swap(ScopedArray<T>& a2)
{
    if (mArray != a2.mArray) {
        std::swap(mArray, a2.mArray);
    }
}

/**
 * @brief Returns the T* associated with mArray and mArray
 * is pointed to nullptr
 * @return Returns the former address that mArray referenced
 */
template <typename T> T* ScopedArray<T>::release()
{
    T* hold = mArray;
    mArray = nullptr;
    return hold;
}