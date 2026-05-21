#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* arr ;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;

        int* newArr = new int[capacity];

        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;

        arr = newArr;
    }
public:
    Stack() {
        capacity = 4;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // 매개변수 이름은 생략된 것
    // 컴파일러 입장에서는 함수 호출을 구분할 때 매개변수 이름이 아니라
    // 매개변수 타입을 봄
    // void print(int); 이런식으로 선언 가능하죠?
    // value라는 이름은 함수 안에서 그 값을 사용할 때 필요한 이름일 뿐
    // = delete는 "이 함수는 삭제된 함수다"라는 뜻
    // 함수는 존재하지만 사용할 수 없다고 표시
    Stack(const Stack&) = delete; 
    // 위 코드는 이런 코드를 금지함
    // Stack s1;
    // Stack s2 = s1; -> 불가능
    // Stack s3(s1); -> 불가능
    Stack& operator=(const Stack&) = delete;
    // 위 코드는 이런 코드를 금지함
    // Stack s1;
    // Stack s2;
    // s2 = s1; -> 불가능

    void push(int value) {
        if (topIndex + 1 == capacity) {
            resize();
        }

        arr[++topIndex] = value;
    }

    void pop() {
        if (topIndex == -1) {
            throw std::out_of_range("Invalid index");
        }

        topIndex--;
    }

    int top() const {
        if (topIndex == -1) {
            throw std::out_of_range("Invalid index");
        }

        return arr[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }
};

int main(void) {
    return 0;
}