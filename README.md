# CS 3251: Intermediate Software Design

## Programming Assignment 2

This assignment builds on the concepts from the SimpleArray class from Assignment 1. This assignment focuses on using templates, overloading operators and the use of const.

You have been provided with several code files:

* `include/AllocationTracker.h`
* `src/AllocationTracker.cpp`
* `tests/main.cpp`
* `tests/scopedArrayTest.cpp`

Additionally you have been given a few build-related files:

* `CMakeLists.txt`
* `.gitignore`
* `.travis.yml`

Do not alter any of these files.  You are to create `ScopedArray.h` and `ScopedArray.cpp` (based on your `SimpleArray.h`) files that will allow you to create an array of any data type. This can be achieved by templatizing your class.  Declare ScopedArray in the header file, and implement the class methods in the cpp file.  Do not use the `inline` keyword!

Make sure you pay attention to the test files. Even though your ScopedArray’s functionality is very similar to SimpleArray, its appearance has changed a fair amount.  Thus, the testing file looks different as well.  In addition, the new tests cover a bit more of the control paths in your class.  An analysis of the tests should allow you to determine which operators require overloading and how const should be used. 

For +2 points of extra credit, implement operator[] without duplicating code from operator[] const. (Hint: try casting `this` to a const pointer.)

The assignment is to be submitted using the link to github.com sent out via email to all class members. DO NOT email your assignment to the professor or the TAs.  Emailed assignments ARE NOT accepted.  We will grade the last commit to your repository before the deadline date and time.  Any commits after that moment will be ignored.  If nothing has been committed at that time you will receive a zero grade. 

### Graduate Students

You must port your extra tests developed in HW #1 to this assignment.  These tests should compile and run successfully against the new templatized ScopedArray class.  Place all of your tests in `tests/moreTests.cpp`.


### REMINDERS:

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with a recent version of `clang` and `gcc` and run successfully with Travis CI.
  * Your code will be treated as if it failed to compile if you do not turn Travis builds on.
  * You will have to turn on Travis builds for your repository and then push to trigger a Travis build.
  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository.

