#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

std::mutex mtx;

void print_block (int n, char c) {
  mtx.lock();
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << std::endl;
  mtx.unlock();
}

void MutexExample()
{
    std::thread th1 (print_block, 50, '*');
    std::thread th2 (print_block, 52, '$');
    th1.join();
    th2.join();
}

std::recursive_mutex rmtx;

void r_print_block(int n, char c)
{
    rmtx.lock();
    for (int i=0; i<n; ++i) { std::cout << c; }
    std::cout << std::endl;
    rmtx.unlock();
}

void recursive_print_block (int n, char c) {
  rmtx.lock();
  r_print_block(n, c);
  rmtx.unlock();
}

void RecursiveMutexExample()
{
    std::thread th1 (recursive_print_block, 50, '*');
    std::thread th2 (recursive_print_block, 52, '$');
    th1.join();
    th2.join();
}

std::timed_mutex tmtx;

void fireworks () {
  /* waiting to get a lock every 200ms */
  while (!tmtx.try_lock_for(std::chrono::milliseconds(200))) {
    std::cout << "-";
  }
  /* got a lock! - wait for 1s */
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "*" << std::endl;
  tmtx.unlock();
}

void TimedMutexExample()
{
    std::thread threads[10];
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(fireworks);
    for (auto& th : threads) th.join();
}

std::mutex lock_mtx;

void print_even (int x) {
  if (x%2==0) std::cout << x << " is even\n";
  else throw (std::logic_error("not even"));
}

void print_thread_id (int id) {
    try {
        std::lock_guard<std::mutex> lck (lock_mtx);
        print_even(id);
    }
    catch (std::logic_error&) {
        std::cout << "[exception caught]" << std::endl;
    }
}

void LockGardExample()
{
    std::thread threads[10];
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_thread_id,i+1);

    for (auto& th : threads) th.join();
}

int main (int argc, char *argv[])
{
    MutexExample();
    RecursiveMutexExample();
    TimedMutexExample();
    LockGardExample();
    return 0;
}
