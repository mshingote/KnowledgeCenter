#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;


void print(int& start, int& end, condition_variable& cond, mutex& m, bool is_even) {
	while (start < end) {
		unique_lock<mutex> ulock(m);
		
		//Waits until predicate returns true
		cond.wait(ulock, [&]() { return start % 2 == is_even; });
		cout << this_thread::get_id() << " " << start << endl;
		++start;

		//notify all threads which on waiting on cond
		cond.notify_all();
	}
}

int main() {
	mutex m;
	int start = 0, end = 10;
	condition_variable cond;
	thread odd(print, ref(start), ref(end), ref(cond), ref(m), false);
	thread even(print, ref(start), ref(end), ref(cond), ref(m), true);
	odd.join();
	even.join();
	return 0;
}
