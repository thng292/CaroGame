#pragma once
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class Timer {
public:
	Timer(std::function<void(void)> callback, const long& interval = 1000);
	void Start();
	void Stop();
	void Restart();
	void TogglePause();
	bool isRunning();
	long long getInterval();
	~Timer();
private:
	std::function<void(void)> _callback;
	std::chrono::milliseconds _interval;
	std::thread _thread;
	bool _running = false;
	bool _pause = false;
};