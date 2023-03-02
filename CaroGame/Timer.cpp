#include "Timer.h"

Timer::Timer(std::function<void(void)> callback, const long& interval) {
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
    //_thread.detach();
}

void Timer::Stop() {
    _running = false;
    if (_thread.joinable()) {
        _thread.join();
    }
    _thread.~thread();
}

void Timer::Restart() {
    Stop();
    Start();
}

void Timer::Pause() {
    _pause = true;
}

void Timer::Continued() {
    _pause = false;
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
