#ifndef AUDIO
#define AUDIO

#include <SDL3/SDL.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Class for working with WAV audio files
 * 
 * Allows loading WAV files, playing, pausing, resuming, and stopping audio
 * Uses SDL_AudioStream and SDL_AudioDevice to manage sound
 */
class audio {
    private:
        struct audioData {
            SDL_AudioSpec spec;
            SDL_AudioStream* stream = NULL;
            Uint8* wav_data = NULL;
            Uint32 wav_data_len = 0;
            SDL_AudioDeviceID device = 0;
            string path;
        };

        audioData data;
    public:
        /**
         * @brief Constructor, loads a WAV file and initializes the audio device
         * 
         * @param wavPath Path to the WAV file
         */
        audio(const string& wavPath) {
            SDL_LoadWAV(wavPath.c_str(), &data.spec, &data.wav_data, &data.wav_data_len);

            data.stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &data.spec, NULL, NULL);
            data.device = SDL_GetAudioStreamDevice(data.stream);
            data.path = wavPath;

            SDL_ResumeAudioDevice(data.device);
        }

        /**
         * @brief Plays the audio
         */
        void play() {
            if (SDL_GetAudioStreamQueued(data.stream) < (int)data.wav_data_len) {
                SDL_PutAudioStreamData(data.stream, data.wav_data, data.wav_data_len);
            }
        }

        /**
         * @brief Resumes audio playback
         */
        void resume() {
            SDL_ResumeAudioDevice(data.device);
        }

        /**
         * @brief Pauses audio playback
         */
        void pause() {
            SDL_PauseAudioDevice(data.device);
        }

        /**
         * @brief Stops playback and frees resources
         * 
         * Closes the device, destroys the stream, and frees WAV data
         */
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

        /**
         * @brief Returns the structure with audio data
         * 
         * @return audioData Structure with current audio parameters
         */
        audioData get() const {
            return data;
        }

        /**
         * @brief Overloaded output operator to display audio information
         * 
         * Outputs the file path
         */
        friend ostream& operator<<(ostream& os, const audio& a) {
            os << "Audio(path: \"" << a.data.path << "\")";
            return os;
        }
};

#endif