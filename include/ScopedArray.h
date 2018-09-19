// File name: ScopedArray.h
// Author: Christopher Glenn II
// VUnetid: glennca1
// Email: christopher.a.glenn@vanderbilt.edu
// Class: CS3251
// Date: 9/19/18
// Honor statement: I have neither given nor received unauthorized help on this assignment
// Assignment Number: 02
// Description: This is a declaration of the class template ScopedArray

#ifndef ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#define ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H

#include "AllocationTracker.h"
/**
 * @brief This is yet another simplified array structure, but this time it is implemented
 * using templates, so the array can hold more than just AllocationTracker objects
 * @tparam T this is the type of item the array will hold as defined by the user
 */
template <typename T> class ScopedArray {
public:
    /*** Add some constructors/destructor goodness here ***/

    /**
     * @brief This is the constructor for the ScopedArray class
     * @param a is a pointer of type T and mArray will equal a.
     * If the user does not specify what a is, it defaults to nullptr
     */
    explicit ScopedArray(T* a = nullptr);

    /**
     * @brief This is the deleted Copy Constructor
     * @param noCopy nothing can be copied
     */
    ScopedArray(const ScopedArray<T>& noCopy) = delete;

    /**
     * @brief Destructor for the ScopedArray class
     */
    ~ScopedArray();

    /**
     * @brief overloaded bool operator so ScopedArrays can be associated with a bool value
     * @return whether mArray is empty or not
     */
    operator bool() const noexcept;

    /**
     * @brief overloaded[] const operator to allow the user to refer to the members
     * of the array contained within mArray
     * @param i array index
     * @return a const reference to the T type object in mArray at index i
     */
    const T& operator[](size_t i) const;

    /**
     * @brief overloaded[] operator to allow the user to refer to the members of
     * the array contain within mArray in non-const ScopedArray objects
     * @param i array index
     * @return a reference to the T type object in mArray at index i
     */
    T& operator[](size_t i);

    /**
     * the deleted assignment operator
     * @param noAssign cannot assign anything
     * @return can't return anything
     */
    ScopedArray<T>& operator=(const ScopedArray<T>& noAssign) = delete;

    /*** Need to add some things here ***/

    /**
     * @brief Fetches mArray
     * @return mArray
     */
    T* get() const;
    /**
     * @brief Deletes the current array in mArray and replaces it with parameter "next"
     * @param next is a T pointer determined by the user, if they don't specify, it defaults to
     * nullptr
     * @post mArray points to parameter "next"
     */
    void reset(T* next = nullptr);
    /**
     * @brief Swaps the mArray fields of two different ScopedArrays
     * @details Swaps the mArray fields of two ScopedArrays provided their mArray fields
     * are pointing to different locations. If they are the same, nothing needs to happen.
     * @param a2 is a different ScopedArray
     */
    void swap(ScopedArray<T>& a2);

    /**
     * @brief Returns the T* associated with mArray and mArray
     * is pointed to nullptr
     * @return Returns the former address that mArray referenced
     */
    T* release();

private:
    /*** Maybe some things here too ***/

    // Data members
    /**
     * @brief a pointer that points to an array of any specified type
     */
    T* mArray;
};

#include "ScopedArray.cpp"
#endif // ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H