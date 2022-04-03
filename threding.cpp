#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <queue>

std::mutex mutex_;
std::condition_variable condVar;
std::queue<int> queue;
int item = 0;

void func1(){
    std::cout << "Producer Start\n";
    while (item < 50) 
    {
        std::unique_lock<std::mutex> lck(mutex_);
        condVar.wait(lck, [] { return queue.size() == 0 ; } );
         
        item++;
        queue.push(item);
        
       mutex_.unlock();
       condVar.notify_one();
    }

       
}

void func2(){
    std::cout << "Consumer Start\n";
    while (item < 50) 
    {
        std::unique_lock<std::mutex> lck(mutex_);
        condVar.wait(lck, [] { return !queue.empty(); } );    
        
        while (!queue.empty()) {
            auto item = queue.front(); 
            queue.pop();
            std::cout << item << "\n";
        }
        mutex_.unlock();
       condVar.notify_one();
    }
}

int main(){
  std::thread t1(func1);
  std::thread t2(func2);

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}
