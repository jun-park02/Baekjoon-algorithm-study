#include <iostream>
#include <stdexcept>

class Queue {
private:
    int arr[100];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == 100;
    }

    void push(int value) {
        if (full()) {
            throw std::overflow_error("Queue is full");
        }

        arr[rear] = value;

        // 인덱스가 배열 크기 100을 넘지 않게 하고,
        // 끝까지 가면 다시 0번 인덱스로 돌아가게 하는 것
        rear = (rear + 1) % 100;
        count++;
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        front = (front + 1) % 100;
        count--;
    }

    int peek() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        return arr[front];
    }

    int size() const {
        return count;
    }
};

int main(void) {
    return 0;
}