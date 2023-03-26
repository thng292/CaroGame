#include "BackgroundAudioService.h"

std::unique_ptr<BackgroundAudioService>
    BackgroundAudioService::singletonInstance = nullptr;
std::mutex BackgroundAudioService::locker{};
