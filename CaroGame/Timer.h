#pragma once
#include <chrono>
#include <thread>
#include <functional>

//Reference: https://gist.github.com/zekroTJA/00317b41aa69f38090071b6c8065272b
class Timer {
public:
	Timer(std::function<void(void)> callback, const long& interval = 1000);
	void Start();
	void Stop();
	void Restart();
	void Pause();
	void Continued();
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