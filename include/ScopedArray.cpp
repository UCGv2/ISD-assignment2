// File name: ScopedArray.cpp
// Author: Christopher Glenn II
// VUnetid: glennca1
// Email: christopher.a.glenn@vanderbilt.edu
// Class: CS3251
// Date: 9/19/18
// Honor statement: I have neither given nor received unauthorized help on this assignment
// Assignment Number: 02
// Description: This is an implementation of the class template ScopedArray. Below are
// its function templates

#include "ScopedArray.h"
/**
 * @brief This is the constructor for the ScopedArray class
 * @param a is a pointer of type T and mArray will equal a.
 * If the user does not specify what a is, it defaults to nullptr
 */
template <typename T>
ScopedArray<T>::ScopedArray(T* a)
    : mArray(a)
{
}
/**
 * @brief Destructor for the ScopedArray class
 */
template <typename T> ScopedArray<T>::~ScopedArray()
{
    delete[](mArray);
    mArray = nullptr;
}

/**
 * @brief overloaded bool operator so ScopedArrays can be associated with a bool value
 * @return whether mArray is empty or not
 */
template <typename T> ScopedArray<T>::operator bool() const noexcept
{
    return mArray != nullptr;
}

/**
 * @brief overloaded[] const operator to allow the user to refer to the members
 * of the array contained within mArray
 * @param i array index
 * @return a const reference to the T type object in mArray at index i
 */
template <typename T> const T& ScopedArray<T>::operator[](size_t i) const
{
    return mArray[i];
}

/**
 * @brief overloaded[] operator to allow the user to refer to the members of
 * the array contain within mArray in non-const ScopedArray objects
 * @param i array index
 * @return a reference to the T type object in mArray at index i
 */
template <typename T> T& ScopedArray<T>::operator[](size_t i)
{
    return const_cast<T&>(const_cast<const ScopedArray<T>&>(*this)[i]);
}

/**
 * @brief Fetches mArray
 * @return mArray
 */
template <typename T> T* ScopedArray<T>::get() const
{
    return mArray;
}
/**
 * @brief Deletes the current array in mArray and replaces it with parameter "next"
 * @param next is a T pointer determined by the user, if they don't specify, it defaults to nullptr
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
 * @brief Swaps the mArray fields of two different ScopedArrays
 * @details Swaps the mArray fields of two ScopedArrays provided their mArray fields
 * are pointing to different locations. If they are the same, nothing needs to happen.
 * @param a2 is a different ScopedArray
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