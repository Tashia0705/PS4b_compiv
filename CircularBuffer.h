// Copyright 2021 Tashia Boddu
#ifndef CircularBuffer_H
#define CircularBuffer_H

#include <iostream>
#include <stdint.h> // int_16t
#include <array>
using namespace std;

class CircularBuffer {
    public:
        CircularBuffer(int _capacity);
        ~CircularBuffer();
        int size();
        int Capacity() {
            return capacity;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();

    private:
        int16_t *queue;
        int _size, capacity;
        int frontIndex, rearIndex;
};

#endif