/*!
 * @file main.cpp
 *
 * @brief Simple example for getting started with threads.
 *
 * @details Poco provides abstraction for threads of many platforms
 * and systems. We first need to implement our own Runnable worker class, then
 * create a Thread and start the worker.
 */
#include <Poco/Runnable.h>
#include <Poco/Thread.h>
#include <iostream>

using namespace Poco;
using namespace std;

class MyWorker : public Runnable {
 public:
  MyWorker(int k = -1) : Runnable(), n(k) {}

  virtual void run() {
    for (int i = 1; i <= 10; i++) {
      for (int j = 0; j < 1000000; j++)
        ;  // do nothing
      cout << n << " ";
    }
  }

 private:
  int n;
};

int main() {
  const int N = 5;

  MyWorker w[N];
  for (int i = 0; i < N; i++)
    w[i] = MyWorker(i);

  Thread t[N];
  for (int i = 0; i < N; i++)
    t[i].start(w[i]);
  for (int i = 0; i < N; i++)
    t[i].join();  // wait for all threads to end

  cout << endl << "Threads joined" << endl;

  return 0;
}