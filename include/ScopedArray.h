//
// Created by fours on 9/11/2018.
//

#ifndef ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H
#define ASSIGNMENT2_SOLUTION_SCOPEDARRAY_H

#include "AllocationTracker.h"
/**
 * @brief Simulates a simplified array structure
 * @details Simulates the referential nature of arrays by pointing an AllocationTracker* to an
 * array of AllocationTracker objects. SimpleArrays can be constructed but not assigned or copied.
 */
template <typename T> class ScopedArray {
public:
    /*** Add some constructors/destructor goodness here ***/

    /**
     * @brief Constructor for the ScopedArray class
     */
    explicit ScopedArray(T* a = nullptr);

    /**
     *
     * @param noCopy
     */
    ScopedArray(const ScopedArray<T>& noCopy) = delete;

    /**
     * @brief Destructor for the Simple Array class
     */
    ~ScopedArray();

    /**
     *
     * @param noAssign
     * @return
     */
    ScopedArray<T>& operator=(const ScopedArray<T>& noAssign) = delete;

    /*** Need to add some things here ***/

    /**
     * @brief Fetches mArray
     * @return mArray
     */
    T* get() const;
    /**
     * @brief Deletes the current array in mArray and replaces it with parameter "r"
     * @param r is a new array or nullptr
     * @post mArray points to parameter "r"
     */
    void reset(T* next = nullptr);
    /**
     * @brief Swaps the mArray fields of two different SimpleArrays
     * @details Swaps the mArray fields of two SimpleArrays provided their mArray fields
     * are pointing to different locations. If they are the same, nothing needs to happen.
     * @param a2 is a different SimpleArray
     */
    void swap(ScopedArray<T>& a2);

    /**
     * @brief Returns the AllocationTracker* associated with mArray and mArray
     * is pointed to nullptr
     * @return Returns the former address that mArray referenced
     */
    T* release();
    /**
     * @brief returns whether or not mArray equals nullptr
     * @return the evaluation of the equivalence between mArray and nullptr
     */
    bool isNonNull() const;

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