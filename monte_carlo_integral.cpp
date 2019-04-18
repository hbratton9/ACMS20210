#include <iostream>
#include <string>
#include <random>
//for bind()
#include <functional>
//for header file
#include "hw_6_ex_2_f.h"

using namespace std;

int main (int argc, char* argv[]) {

  double a = stod(argv[1]);
  double b = stod(argv[2]);
  long long int N = stoll(argv[3]);

  //seed value is from where to start number generation
  int seed_value;
  random_device rd;

  //seed value from random device
  seed_value = rd();
  //produces sequences of random numbers
  mt19937 generator(seed_value);
  //distribution to choose from a to b, given by user
  uniform_real_distribution<double>distribution(a, b);
  //bind makes drawing from distribution "more natural"; allows to repeatedly generate random numbers
  //auto is for automatic type deduction by compiler
  auto draw = bind(distribution, generator);

  //initial sum is 0.0
  double total = 0.0;
  double x;
  for (int i = 1; i <= N; i++) {
    //draws random value between a and b
    x = draw();
    //adds to running total
    total += f(x);
  }
  //integral calculation
  double I = ((b-a)/double(N)) * total;

  cout<<"The integral from "<<a<<" to "<<b<<" is: "<<I;

  return 0;
}
