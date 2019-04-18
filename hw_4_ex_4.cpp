#include <iostream>
#include <iomanip>

using namespace std;

bool prime_check (int N);
double Bruns_constant (int p);
int main() {

  int N;
  cout<<"Please enter a positive integer, N, that will be used as a threshold: ";
  cin>>N;

  //returns Brun's Constant to user
  cout<<"The approximation of Brun's Constant is: "<<setprecision(12)<<fixed<<Bruns_constant(N);

  return 0;
}

//function simply checks if a number is prime or not
bool prime_check (int N) {
  //flag variable isPrime
  bool isPrime = true;
  for (int i = 2; i < N; i++) {
    if (N % i == 0) {
      isPrime = false;
      break;
    }
  }
  return isPrime;
}

//function to calculate Brun's Constant
double Bruns_constant (int p) {
  //initialize sum to 0.0
  double total = 0.0;
  //loop from 2 to threshold p
  for (int i = 2; i <= p; i++) {
    //intialize variable and twin variable to check for primeness
    int prime = i;
    int twin_prime = i + 2;
    //if both variables are prime, then add together their reciprocals
    if (prime_check(prime) && prime_check(twin_prime)) {
      total += (1.0/prime + 1.0/twin_prime);
    }
  }
  return total;
}
