//
// Created by Pablo on 2023-06-14.
//

#ifndef MACPANIMALDETERRENT_AUDIOENGINE_H
#define MACPANIMALDETERRENT_AUDIOENGINE_H


#include <aaudio/AAudio.h>
#include "Oscillator.h"

class AudioEngine {
public:
    bool start(float frequency);
    void stop();
    void restart();
    void setToneOn(bool isToneOn);

private:
    Oscillator oscillator_;
    AAudioStream *stream_;
};

#endif //MACPANIMALDETERRENT_AUDIOENGINE_H
