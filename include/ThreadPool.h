#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <thread>

#define NUM_THREADS std::thread::hardware_concurrency()

class ThreadPool
{
private:
	// static ThreadPool instance = NULL;
	
	// temporary int
	// TODO: change int ot ThreadSafeQueue
	static int high_priority_queue;
	static int medium_priority_queue;
	static int low_priority_queue;

	static bool stop_flag;
	static bool *stop_flags;

	static void worker (int id);

	// static void set_start_values();
	static void kill_all_threads();

	ThreadPool(int number_of_thread) {
		ThreadPool::stop_flag = false;
		ThreadPool::stop_flags = new bool[thread_number];
	}

	ThreadPool() {};
	~ThreadPool() {};
	ThreadPool(ThreadPool const&);

	void operator=(ThreadPool const&);

public:
	// creates instance if not exists, and run teh threadpool
	// with amounts of threads equal amounts of logical thread
	static void start();
	// With the number of threads given.
	static void start(int number_of_threads);
	
	static void stop(bool force);
	static void stop();

	static ThreadPool& get_instance(int& number_of_thread) {
		static ThreadPool instance((number_of_thread > 0) ? number_of_thread : (NUM_THREADS + number_of_thread));

		return instance;
	}

	ThreadPool(ThreadPool const&) = delete;
	void operator=(ThreadPool const&) = delete;
}

// endif ifndef _THREAD_POOL_H_
#endif