#include "BackgroundAudioService.h"

BackgroundAudioService* BackgroundAudioService::singletonInstance = nullptr;

std::mutex BackgroundAudioService::locker;