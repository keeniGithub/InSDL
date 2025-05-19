#ifndef AUDIO
#define AUDIO

#include <SDL3/SDL.h>
#include <iostream>
#include <string>

using namespace std;

class audio {
    private:
        struct audioData {
            SDL_AudioSpec spec;
            SDL_AudioStream *stream = NULL;
            Uint8 *wav_data = NULL;
            Uint32 wav_data_len = 0;
            SDL_AudioDeviceID device = 0;
        };
    public:
        audioData data;
        string path;

        audio(const string& wavPath) : path(wavPath) {
            SDL_LoadWAV(wavPath.c_str(), &data.spec, &data.wav_data, &data.wav_data_len);

            data.stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &data.spec, NULL, NULL);
            data.device = SDL_GetAudioStreamDevice(data.stream);

            SDL_ResumeAudioDevice(data.device);
        }

        void play() {
            if (SDL_GetAudioStreamQueued(data.stream) < (int)data.wav_data_len) {
                SDL_PutAudioStreamData(data.stream, data.wav_data, data.wav_data_len);
            }
        }

        void resume(){
            SDL_ResumeAudioDevice(data.device);
        }

        void pause(){
            SDL_PauseAudioDevice(data.device);
        }

        void stop() {
            if (data.device) {
                SDL_PauseAudioDevice(data.device);
                SDL_CloseAudioDevice(data.device);
            }
            if (data.stream) {
                SDL_DestroyAudioStream(data.stream);
                data.stream = NULL;
            }
            if (data.wav_data) {
                SDL_free(data.wav_data);
                data.wav_data = NULL;
            }
        }

        audioData get() const {
            return data;
        }

        friend ostream& operator<<(ostream& os, const audio& a) {
            os << "Audio(path: \"" << a.path << "\")";
            return os;
        }
    };

#endif