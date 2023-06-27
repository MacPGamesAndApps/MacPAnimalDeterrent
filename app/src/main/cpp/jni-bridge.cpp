#include <jni.h>
#include <android/input.h>
#include "AudioEngine.h"

static AudioEngine *audioEngine = new AudioEngine();

extern "C" {

JNIEXPORT void JNICALL
Java_com_macpgames_macpanimaldeterrent_MainActivity_startEngine(JNIEnv *env, jobject /* this */, float frequency) {
    audioEngine->start(frequency);
}

JNIEXPORT void JNICALL
Java_com_macpgames_macpanimaldeterrent_MainActivity_stopEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->stop();
}

JNIEXPORT void JNICALL
        Java_com_macpgames_macpanimaldeterrent_MainActivity_switchSoundOn(JNIEnv *env, jobject /* this */) {
audioEngine->setToneOn(true);
}

JNIEXPORT void JNICALL
Java_com_macpgames_macpanimaldeterrent_MainActivity_switchSoundOff(JNIEnv *env, jobject /* this */) {
    audioEngine->setToneOn(false);
}

}