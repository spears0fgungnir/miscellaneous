#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Channel {
private:
	int val;
	bool ready = false;
	std::mutex mtx;
	std::condition_variable cv;
public:
	void send(int x){
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&] {return !ready});
		val = x;
		ready = true;
		cv.notify_one();
	}
	void receive(){
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&] {return ready};
		int x = val;
		ready = false;
		cv.notify_one();
		return x;
	}
}
void thread_A(Channel& AB, Channel& BA){
	int x = 0;
	for (int i=0; i<1'000'000; i++){
		AB.send(x);
		x = BA.receive();
	}
	AB.send(-1);
}

void thread_B(Channel& AB, Channel& BA){
	while (true){
		int x = AB.receive();
		if (x == -1){
			break;
		}
		BA.send(x+1);
	}
	
int main(){
	Channel ab, ba;
	std::thread thread_A(ab, ba);
	std::thread thread_B(ab, ba);

	thread_A.join();
	thread_B.join();

	return 0;
}
