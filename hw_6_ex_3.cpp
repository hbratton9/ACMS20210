#include <iostream>
#include <random>
#include <functional>
#include <string>
#include <cmath>

bool is_valid(double x, double y);

using namespace std;

int main (int argc, char* argv[]) {

  double a = stod(argv[1]);
  double b = stod(argv[2]);

  int N = stoi(argv[3]);
  int seed_value;
  random_device rd;

  seed_value = rd();

  mt19937 generator(seed_value);

  //two distributions from which to sample: one for x and one for y
  uniform_real_distribution<double>distribution_x(-1,1);
  uniform_real_distribution<double>distribution_y(-1,1);

  //when using multiple distribution, ref() ensures that the values do not become correlated
  auto draw_x = bind(distribution_x, ref(generator));
  auto draw_y = bind(distribution_y, ref(generator));

  //total distance
  double total_distance = 0.0;
  double x, y;

  //Monte Carlo loop over number of trials
  for (int i = 0; i < N; i++) {
    //this will draw an x and y
    x = draw_x();
    y = draw_y();

    //use this to check whether x and y are inside the circle!
    while (!is_valid(x, y)) {
      //redraws x and y
      x = draw_x();
      y = draw_y();
    }

    total_distance += pow( pow(x-a, 2) + pow(y-b, 2), .5);
  }
  double average_distance = total_distance/N;

  cout<<"The average distance from is "<<average_distance<<endl;
  return 0;
}

//function to check if points are within the circle 
bool is_valid(double x, double y) {
  if ((x*x + y*y) <= 1) {
    return true;
  }
  return false;
}
