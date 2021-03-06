#pragma once
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <vector>
namespace util
{
	template<typename Condition>
	void wait_for(std::chrono::milliseconds sleep_for, std::chrono::milliseconds time_out, Condition condt)
	{
		auto start = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff;
		while (!condt())
		{
			auto end = std::chrono::steady_clock::now();
			diff = end - start;
			if ((diff.count() * 1000/*from seconds to milisecond*/) >= time_out)
			{
				return;
			}

			if (sleep_for.count())
			{
				std::this_thread::sleep_for(sleep_for);
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}

	template<typename Condition>
	void wait_for(std::chrono::milliseconds sleep_for, Condition condt)
	{
		while (!condt())
		{
			if (sleep_for.count())
			{
				std::this_thread::sleep_for(sleep_for);
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}

	template<class T>
	T ConvertToType(std::string& strVal)
	{
		std::stringstream sstream(strVal);
		T value;
		sstream >> value;
		return value;
	}
}