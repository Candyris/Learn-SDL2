// for simplist i will be using SDL2 default music handler
// if You are making big game you should use SDL_Mixer

#include <SDL2/SDL.h>
#include <iostream>

#define SOUNDFILEPATH "sound.wav"

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        std::cout << "FAILED  INITIALIZE SDL2 AUDIO \n";
        SDL_Quit();
        return -1;
    }
    else
    {
        std::cout << "[Successful in INITALIZE SDL2 AUIDO] \n\n";
    }
    std::cout << "Hello" << std::endl;
    // Create Audio stuff for using Audio
    SDL_AudioSpec wavSpec; // it help us to describe audio format
    Uint32 wavLength;      // this is length of Audio Buffer in / convert into Bytes
    Uint8 *wavBuffer;      // this will be containing the audio data buffer

    // Loading WAV File into program
    SDL_LoadWAV(SOUNDFILEPATH, &wavSpec, &wavBuffer, &wavLength);

    // Open audio Device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, NULL, &wavSpec, NULL, NULL);
    // play audio

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
    // This line is unpausing the audio device, which means the audio will start playing.

    // 'deviceId' is the ID of the audio device that you want to unpause.
    // The second argument is 0, which means unpause. If it was 1, it would pause the device.

    SDL_Delay(3000);

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();

    return 0;
}