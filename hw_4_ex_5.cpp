#include <iostream>
#include <vector>

using namespace std;

int euclid_algo (int x, int y);
int tot_func(int N);

int main() {

  int N;
  cout<<"Please enter a positive integer, N: ";
  cin>>N;

  cout<<"The totient function evaluated at N = "<<N<<" is: "<<tot_func(N)<<endl;

  //sum up values of the totient function
  int total = 0;
  for (int i = 1; i <= N; i++) {
    total += tot_func(i);
  }

  cout<<"The summatory totient function evaluated at N = "<<N<<" is: "<<total<<endl;

  return 0;
}

//function to find the gcd between two numbers using euclidean algorithm
int euclid_algo (int x, int y) {
  //when one number is 0, the gcd is the other number (base case)
  if (x == 0) {
    return y;
  }
  //recursion until y % x == 0
  //when this happens, gcd is simply x
  //ex (20 , 12) = 4
  return euclid_algo (y % x, x);
}

//function to find totient for a value N
int tot_func(int N) {
  int total = 0;
  //loop through primes starting with 1 until some number N
  for (int i = 1; i <= N; i++) {
    //if the gcd is 1, then the numbers are relatively prime (ie, no int > 1 that divides both)
    if (euclid_algo (i, N) == 1) {
      //increase total by 1, indicating pair of relative primeness has been found
      total += 1;
    }
  }
  return total;
}
