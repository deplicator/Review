// steady_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono> //requires c++11 standard

using namespace std;
using namespace std::chrono;

int main () {
  
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

  cout << "printing out 1000 stars...\n";
  for (int i=0; i<1000; ++i) cout << "*";
  cout << std::endl;

  steady_clock::time_point t2 = steady_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  cout << "It took me " << time_span.count() << " seconds.";
  cout << endl;

  return 0;
}
