#pragma once
#include <chrono>
#include <functional>
#include <thread>

struct TimerInternalState {
    std::function<void(void)> callback;
    std::chrono::milliseconds interval = std::chrono::milliseconds{1000};
    bool running = false;
    bool pause = false;
};

// Reference: https://gist.github.com/zekroTJA/00317b41aa69f38090071b6c8065272b
class Timer {
   public:
    // delete copy and move constructor
    Timer(const Timer&) = delete;
    Timer(Timer&&) = delete;
    // delete copy and move assignment
    Timer& operator=(const Timer&) = delete;
    Timer& operator=(Timer&&) = delete;

    Timer(std::function<void(void)> callback, const long& interval = 1000)
    {
        _state->callback = callback;
        _state->interval = std::chrono::milliseconds{interval};
    }

    inline void Start()
    {
        _state->running = true;
        auto state = _state;
        _thread = std::thread([state] {
            while (state->running) {
                auto nextInterval =
                    std::chrono::steady_clock::now() + state->interval;
                if (!state->pause) {
                    state->callback();
                }
                std::this_thread::sleep_until(nextInterval);
            }
        });
        _thread.detach();
    }

    inline void Stop() { _state->running = false; }

    inline void Restart()
    {
        Stop();
        Start();
    }

    inline void Pause() { _state->pause = true; }

    inline void Continued() { _state->pause = false; }

    inline bool isRunning() { return _state->running && !_state->pause; }

    inline long long getInterval()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   _state->interval
        )
            .count();
    }

    inline ~Timer() { Stop(); }

   private:
    std::thread _thread;

    std::shared_ptr<TimerInternalState> _state =
        std::make_shared<TimerInternalState>();
};