// Copyright Tashia Boddu 2021

#include "CircularBuffer.h"
#include <stdexcept>  // std::invalid_arg

CircularBuffer::CircularBuffer(int _capacity) {
    if (_capacity < 1) {
        throw invalid_argument(
            "CircularBuffer constructor: capacity must be greater than zero");
    }
    capacity = _capacity;
    _size = 0;
    rearIndex = 0;
    frontIndex = 0;
    queue = new int16_t[capacity];
}

CircularBuffer::~CircularBuffer() {
    delete[] queue;
}

int CircularBuffer::size() {
    return _size;
}

bool CircularBuffer::isEmpty() {
    return _size == 0;
}

bool CircularBuffer::isFull() {
    return _size == capacity;
}

void CircularBuffer::enqueue(int16_t x) {
    if (_size == capacity) {
        throw runtime_error("Can't enqueue to a full ring");
    }
    queue[rearIndex % capacity] = x;
    rearIndex++;
    _size++;
}

int16_t CircularBuffer::dequeue() {
    if (_size == 0) {
        throw runtime_error("Can't dequeue from an empty ring");
    }
    queue[frontIndex % capacity] = 0;
    frontIndex++;
    _size--;
    return queue[frontIndex % capacity];
}

int16_t CircularBuffer::peek() {
    if (_size == 0) {
        throw runtime_error("Can't peek from an empty ring");
    }
    return queue[frontIndex % capacity]; 
}