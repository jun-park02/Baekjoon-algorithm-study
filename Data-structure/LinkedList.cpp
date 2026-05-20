#include <iostream>

// Rule of 3

class LinkedList {
    private: 
        struct Node {
            int data;
            Node* next;
            Node(int value) : data(value), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(void);
        ~LinkedList(void);
        void push_back(int value);
        void push_front(int value);
        void pop_back(void);
        void pop_front(void);
        void print(void);
        void get_last(void);
        void get_first(void);
        int size() const;
};

LinkedList::LinkedList(void) {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

LinkedList::~LinkedList(void) {
    Node* ptr = this->head;
    Node* next = nullptr;

    while (ptr) {
        next = ptr->next;
        std::cout << "(메모리 해제) data = " << ptr->data << std::endl;
        delete ptr;
        ptr = next;
    }

    std::cout << "\n메모리 해제 완료";
}

void LinkedList::push_back(int value) {
    Node* new_node = new Node(value); 

    if (this->tail != nullptr) {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    else {
        this->tail = new_node;
        this->head = new_node;
    }

    this->length += 1;
}

void LinkedList::push_front(int value) {
    Node* new_node = new Node(value);

    if (this->head) {
        new_node->next = this->head;
    }
    else {
        this->tail = new_node;
    }
    
    this->head = new_node;
    this->length += 1;
}

void LinkedList::pop_back() {
    if (this->length == 0) {
        return;
    }

    if (this->length == 1) {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        this->length -= 1;
        return;
    }

    Node* prev = nullptr;
    Node* cur = this->head;

    while (cur != this->tail) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = nullptr;

    delete cur;
    this->tail = prev;
    this->length -= 1;
}

void LinkedList::pop_front() {
    if (this->length == 0) {
        return;        
    }

    if (this->length == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->length -= 1;
        return;
    }

    Node* head_next = this->head->next;

    delete this->head;
    this->head = head_next;
    this->length -= 1;
}

void LinkedList::print() {
    Node* ptr = this->head;
    
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}

void LinkedList::get_last(void) {
    if (this->tail == nullptr)
        return;

    std::cout << this->tail->data << std::endl;
}

void LinkedList::get_first(void) {
    if (this->head == nullptr)
        return;

    std::cout << this->head->data << std::endl;
}

int LinkedList::size() const {
    return this->length;
}


int main(void) {
    LinkedList ll = LinkedList();

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // ll.get_last();
    ll.print();

    return 0;
}