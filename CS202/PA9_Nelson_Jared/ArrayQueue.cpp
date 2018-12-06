#include "ArrayQueue.h"

//Default constructor for NodeQueue 
ArrayQueue::ArrayQueue() {
    m_front = 0;
    m_back = 0;
    m_size = 0;
}

//Parameterized constructor for NodeQueue
ArrayQueue::ArrayQueue(size_t count, const DataType &value) {
    m_front = 0;
    m_back = 0;
    m_size = 0;

    for (size_t i = 0; i < count; i++) {
        push(value);
    }
}

//Copy constructor for NodeQueue
ArrayQueue::ArrayQueue(const ArrayQueue &other) {

    m_front = other.m_front;
    m_back = other.m_front;
    m_size = 0;

    for (size_t i = 0; i < other.m_size; i++) {
        push(other.m_array[i + other.m_front]);
    }
}

//Destructor for NodeQueue 
ArrayQueue::~ArrayQueue() {
    
}

//Assignment operator overload for NodeQueue
ArrayQueue &ArrayQueue::operator=(const ArrayQueue &rhs) {
    if (this != &rhs) {

       clear();

        m_front = rhs.m_front;
        m_back = rhs.m_front;
        m_size = 0;

        for (size_t i = 0; i < rhs.m_size; i++) {
            push(rhs.m_array[i + rhs.m_front]);
        }
    }

    return *this;
}

//Get DataType obj at front of queue
DataType &ArrayQueue::front() {
    return m_array[m_front];
}

//Get DataType obj at front of queue
const DataType &ArrayQueue::front() const {
    return m_array[m_front];
}

//Get DataType obj at back of queue
DataType &ArrayQueue::back() {
    return m_array[m_back];
}

//Get DataType obj at back of queue
const DataType &ArrayQueue::back() const {
    return m_array[m_back];
}

//Add an element to the back of the queue
void ArrayQueue::push(const DataType &value) {
    if (m_size != ARRAY_MAX) {

        if (!empty()) {
            m_back = (m_back + 1) % ARRAY_MAX;
        }


        m_array[m_back] = value;
        m_size++;
    }
}

//Remove an element from the front of the queue
void ArrayQueue::pop() {
    if (!empty()) {
        m_front = (m_front + 1) % ARRAY_MAX;
        m_size--;
    }
}

//Get the total number of elements in the queue
size_t ArrayQueue::size() const {
    return 0;
}

//Empty queue
bool ArrayQueue::empty() const {
    return m_size == 0;
}

//Full queue
bool ArrayQueue::full() const {
    return m_size == ARRAY_MAX;
}

//Reset queue to empty state
void ArrayQueue::clear() {
    m_front = 0;
    m_back = 0;
    m_size = 0;
}

//Print contents of queue to ostream
void ArrayQueue::serialize(std::ostream &os) const {
    for (size_t i = 0; i < m_size; i++) {
        os << i << ": " << m_array[i + m_front];

        if (i != m_size - 1) {
            os << std::endl;
        }
    }
}

//Print contents of queue to ostream
std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue) {
    arrayQueue.serialize(os);
    return os;
}
