#include <iostream>
#include <cstring>

#include "MyString.h"

int main() {
    //(1)
    std::cout << "Testing Default Constructor" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_default;
    std::cout << std::endl;

    //(2)
    std::cout << "Testing Parameterized Constructor" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_parametrized("MyString Parametrized Constructor!");
    std::cout << std::endl;

    //(3)
    std::cout << "Testing Copy Constructor" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_copy(ms_parametrized);
    std::cout << std::endl;

    //(4)
    std::cout << "Testing Destructor" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString * ms_Pt = new MyString("MyString To Be Deleted...");
    delete ms_Pt;
    ms_Pt = NULL;
    std::cout << std::endl;

    //(5),(6)
    std::cout << "Testing Size and Length Methods" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_size_length("Size and Length Test");
    std::cout << ms_size_length.size() << std::endl;
    std::cout << ms_size_length.length() << std::endl;
    std::cout << std::endl;

    //(7)
    std::cout << "Testing C-String Method" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_toCstring("C-String Equivalent Successfully Obtained!");
    std::cout << ms_toCstring.c_str() << std::endl;
    std::cout << std::endl;

    //(8)
    std::cout << "Testing Comparison Operator" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_same1("The Same"), ms_same2("The Same");
    if (ms_same1==ms_same2) {
        std::cout << "Same Success" << std::endl;
    }
    MyString ms_different("The Same (NOT)");
    if (!(ms_same1==ms_different)) {
        std::cout << "Different Success" << std::endl;
    }
    std::cout << std::endl;

    //(9)
    std::cout << "Testing Assignment Operator" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_assign("Before Assignment");
    std::cout << ms_assign << std::endl;
    ms_assign = MyString("After Performing Assignment");
    std::cout << ms_assign << std::endl;
    std::cout << std::endl;

    //(10)
    std::cout << "Testing Concatentation Operator" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_append1("The First Part");
    MyString ms_append2(" and the Second");
    MyString ms_concat = ms_append1+ ms_append2;
    std::cout << ms_concat << std::endl;
    std::cout << std::endl;

    //(11)
    std::cout << "Testing Bracket Operator" << std::endl;
    std::cout << "===========================" << std::endl;
    MyString ms_access("Access Successful (NOT)");
    ms_access[17] = 0;
    std::cout << std::endl;

    //12
    std::cout << "Testing Insertion Operator" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << ms_access << std::endl;
    std::cout << std::endl;

    std::cout << "-- END TESTS --" << std::endl;
    std::cout << std::endl;
    return 0;
}
