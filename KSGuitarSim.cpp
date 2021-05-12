// Copyright Tashia Boddu 2021

#include "CircularBuffer.h"
#include "StringSound.h"

#include <exception>
#include <vector>
#include <cmath> // pow
#include <string> 

const unsigned SAMPLE_RATE = 44100;

vector<sf::Int16> makeSamples(StringSound *gs) {
  std::vector<sf::Int16> samples;
  gs->pluck();
  int duration = 8;  // seconds
  
  for (unsigned i = 0; i < SAMPLE_RATE * duration; i++) {
    gs->tic();
    samples.push_back(gs->sample());
  }
  return samples;
}

int main() {
    vector<vector<sf::Int16>> samples(37);
    vector<sf::SoundBuffer> soundBuff(37);
    vector<sf::Sound> sound(37);
    string keys = "q2we4r5ty7u8i90p-[=zxdcfvgbnjmk,.;/' ";

    for (int i = 0; i < 37; i++) {
        double frequency = 440 * pow(2, (i - 24.0) / 12.0);
        StringSound StrS(frequency);

        samples[i] = makeSamples(&StrS);
        if (!soundBuff[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, SAMPLE_RATE)) {
            throw runtime_error("sf::SoundBuffer: Failed");
        }
        sound[i].setBuffer(soundBuff[i]);
    }

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML KSGuitarSim");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // use loop along with string of keys to play sounds;
            // event obj will access text (actual key)
            if (event.type == sf::Event::TextEntered) {
                for (int i = 0; i < 37; i++) {
                    if (static_cast<char>(event.text.unicode) == keys[i]) {
                        cout << "Playing " << keys[i] << " note" << endl;
                        sound[i].play();
                        break;
                    }
                }
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}