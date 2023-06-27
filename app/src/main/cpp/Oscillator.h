//
// Created by Pablo on 2023-06-14.
//

#ifndef MACPANIMALDETERRENT_OSCILLATOR_H
#define MACPANIMALDETERRENT_OSCILLATOR_H

#include <atomic>
#include <stdint.h>

class Oscillator {
public:
    void setWaveOn(bool isWaveOn);
    void setSampleRate(int32_t sampleRate, float frequency);
    void render(float *audioData, int32_t numFrames);

private:
    std::atomic<bool> isWaveOn_{false};
    double phase_ = 0.0;
    double phaseIncrement_ = 0.0;
};


#endif //MACPANIMALDETERRENT_OSCILLATOR_H
