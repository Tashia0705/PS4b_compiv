// Copyright Tashia Boddu 2021

#ifndef StringSound_H
#define StringSound_H

#include "CircularBuffer.h"
#include <iostream> 
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std; 

class StringSound {
    public: 
        explicit StringSound(double frequency); 
        explicit StringSound(vector<sf::Int16> init);
        StringSound(const StringSound &obj) {}; // what is this for 
        ~StringSound(); 
        void pluck(); 
        void tic();
        sf::Int16 sample();  
        int time(); 

    private:
        CircularBuffer * Cb; 
        int _time; 
};

#endif 