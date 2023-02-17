#include "Timer.h"

Timer::Timer(std::function<void(void)> callback, const long& interval = 1000) {
    _callback = callback;
    _interval = std::chrono::milliseconds{ interval };
}

void Timer::Start() {
    _running = true;
    _thread = std::thread([&]() {
        while (_running) {
            std::this_thread::sleep_for(_interval);
            if (!_pause) {
                _callback();
            }
        }
        });
    _thread.detach();
}

void Timer::Stop() {
    _running = false;
    _thread.~thread();
}

void Timer::Restart() {
    Stop();
    Start();
}

void Timer::TogglePause() {
    _pause = !_pause;
}

bool Timer::isRunning() {
    return _running && !_pause;
}

long long Timer::getInterval() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(_interval).count();
}

Timer::~Timer() {
    Stop();
}
