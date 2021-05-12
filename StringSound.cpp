// Copyright Tashia Boddu 2021

#include "StringSound.h"
#include <math.h> // ceil
#include <stdlib.h> // rand
#include <stdint.h> // int16_t

const int samplingRate = 44100;
const double energyDecayFacor = 0.996;

StringSound::StringSound(double frequency) {
    int N = ceil(samplingRate/frequency);
    Cb = new CircularBuffer(N);
    _time = 0;
}

StringSound::StringSound(vector<sf::Int16> init) {
    int N = init.size();
    Cb = new CircularBuffer(N);
    _time = 0;

    for (long unsigned int i = 0; i < init.size(); i++) {
        Cb->enqueue(init[i]);
    }
}

void StringSound::pluck() {
        while (!Cb->isEmpty()) {
            Cb->dequeue(); 
        }
        while (!Cb->isFull()) {
            Cb->enqueue(rand());
        }
}

void StringSound::tic() {
    int16_t index1 = Cb->peek();
    Cb->dequeue();
    int16_t index2 = Cb->peek();
    int16_t result = energyDecayFacor * 0.5 * (index1  + index2);
    Cb->enqueue(result);
    _time++;
}

int StringSound::time() {
    return _time;
}

sf::Int16 StringSound::sample() {
    return static_cast<sf::Int16>(Cb->peek());
}

StringSound::~StringSound() {
    delete Cb;
}     