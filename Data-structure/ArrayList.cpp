#include <iostream>
#include <stdexcept>

// rule of 3

class ArrayList {
private:
    int* data;
    int size_; // 실제로 들어있는 원소 개수
    int capacity_; // 현재 내부 배열이 담을 수 있는 최대 공간 크기

    void resize() {
        capacity_ *= 2;

        int* newData = new int[capacity_];

        for (int i = 0; i < size_; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    ArrayList() {
        size_ = 0;
        capacity_ = 4;
        data = new int[capacity_];
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(int value) {
        if (size_ == capacity_) {
            resize();
        }

        data[size_++] = value;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size_) {
            throw std::out_of_range("Invalid index");
        }

        if (size_ == capacity_) {
            resize();
        }

        // 끝쪽 원소부터 해서 한 칸씩 당기는
        // 반대로 밀면 값이 중복됨
        for (int i = size_; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size_++;
    }

    void remove(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        // size_ - 1인건 실제로 지우는게 아니고 그냥 size_를 줄임
        for (int i = index; i < size_ - 1; i++) {
            data[i] = data[i + 1];
        }
        
        size_--;
    }

    // const는 이 멤버 함수 안에서는 객체의 멤버 변수를 변경하지 않겠다는 의미
    int get(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Invalid index");
        }

        data[index] = value;
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }
};