#include "MyString.h"
#include <cstring>
MyString::MyString() {
    std::cout << "MyString Default Constructor" << std::endl;
    m_buffer = NULL;
    m_size = 0;
}

MyString::MyString(const char *str) {
    std::cout << "MyString Parameterized Constructor" << std::endl;
    size_t len = strlen(str);

    try {
        buffer_allocate(len);
        strcpy(m_buffer, str);
    } catch (const std::bad_alloc& e) {
        std::cout << "Failed Parameterized Constructor" << std::endl;
    }
}

MyString::MyString(const MyString &other_myStr) {
    std::cout << "MyString Copy Constructor" << std::endl;
    try {
        buffer_allocate(other_myStr.m_size);
        strcpy(m_buffer, other_myStr.m_buffer);
    } catch (const std::bad_alloc& e) {
        std::cout << "Failed Copy Constructor" << std::endl;
    }
}

MyString::~MyString() {
    std::cout << "MyString Destructor" << std::endl;
    buffer_deallocate();
}

size_t MyString::size() const {
    std::cout << "MyString Size: " << std::endl;
    return m_size;
}

size_t MyString::length() const {
    std::cout << "MyString Length: " << std::endl;
    return strlen(m_buffer);
}

const char *MyString::c_str() const {
    std::cout << "MyString C-String" << std::endl;
    return m_buffer;
}

bool MyString::operator==(const MyString &other_myStr) const {
    std::cout << "MyString Comparison Operator" << std::endl;
    return !strcmp(m_buffer, other_myStr.c_str());
}

MyString &MyString::operator=(const MyString &other_myStr) {
    std::cout << "MyString Assignment Operator" << std::endl;
    if (this != &other_myStr) {
        if (other_myStr.size() != m_size) {
            buffer_deallocate();
            buffer_allocate(strlen(other_myStr.c_str()));
        }

        strcpy(m_buffer, other_myStr.c_str());
    }
    return *this;
}

MyString MyString::operator+(const MyString &other_myStr) const {
    std::cout << "MyString Concat Operator" << std::endl;
    char str[m_size + other_myStr.size()];
    strcpy(str, c_str());
    strcat(str, other_myStr.c_str());
    return MyString(str);
}

char &MyString::operator[](size_t index) {
    std::cout << "MyString Bracket Operator" << std::endl;
    return m_buffer[index];
}

const char &MyString::operator[](size_t index) const {
    std::cout << "MyString Constant Bracket Operator" << std::endl;
    return m_buffer[index];
}

std::ostream &operator<<(std::ostream &os, const MyString &myStr) {
    os << myStr.c_str();
    return os;
}

void MyString::buffer_deallocate() {
    std::cout << "MyString Deallocate Buffer" << std::endl;
    delete [] m_buffer;
    m_buffer = NULL;
    m_size = 0;
}

void MyString::buffer_allocate(size_t size) {
    std::cout << "MyString Allocate Buffer" << std::endl;
    try {
        m_buffer = new char[size + 1];  // include null-terminator
        m_size = size + 1;
    } catch (std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}
