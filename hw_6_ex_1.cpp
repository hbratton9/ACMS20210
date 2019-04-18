#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//header file
#include "hw_6_ex_1_f.h"

using namespace std;

int main (int argc, char* argv[]) {

  double y0 = stod(argv[1]);
  double b = stod(argv[2]);
  int N = stoi(argv[3]);
  ofstream ofs(argv[4]);

  //interval width
  double h = b/double(N);
  double x0 = 0.0;

  for (int i = 1; i <= N; i++) {
    //equation for Euler's method
    y0 += h * f(x0, y0);
    //update x0
    x0 +=h;
    //report results to an output file
    ofs<<x0<<" "<<setprecision(10)<<fixed<<y0<<'\n';
  }
  return 0;
}
