#pragma once
#include <chrono>
#include <thread>
#include <functional>

//Reference: https://gist.github.com/zekroTJA/00317b41aa69f38090071b6c8065272b
class Timer {
public:
	inline Timer(std::function<void(void)> callback, const long& interval = 1000) {
		_callback = callback;
		_interval = std::chrono::milliseconds{ interval };
	}

	inline void Start() {
		_running = true;
		_thread = std::thread([&]() {
			while (_running) {
				auto nextInterval = std::chrono::system_clock::now() + _interval;
				if (!_pause) {
					_callback();
				}
				std::this_thread::sleep_until(nextInterval);
			}
			});
		//_thread.detach();
	}

	inline void Stop() {
		_running = false;
		if (_thread.joinable()) {
			_thread.join();
		}
		_thread.~thread();
	}

	inline void Restart() {
		Stop();
		Start();
	}

	inline void Pause() {
		_pause = true;
	}

	inline void Continued() {
		_pause = false;
	}

	inline bool isRunning() {
		return _running && !_pause;
	}

	inline long long getInterval() {
		return std::chrono::duration_cast<std::chrono::milliseconds>(_interval).count();
	}

	inline ~Timer() {
		Stop();
	}

private:
	std::function<void(void)> _callback;
	std::chrono::milliseconds _interval;
	std::thread _thread;
	bool _running = false;
	bool _pause = false;
};