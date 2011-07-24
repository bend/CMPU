/**
 *
 *       @file  test.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  03.07.2011 10:03:57
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <tests/testlibrary.h>
#include <tests/testsqliteadapter.h>
#include <iostream>
using namespace std;
#define TEST_LIB "lib.db"
int main() {
    TestLibrary l(TEST_LIB);
    testSqliteAdapter();
    cout << "All tests Succeded" << endl;
}
