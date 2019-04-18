#include <iostream>
#include <cmath>

using namespace std;

int main() {

  double tol;
  cout<<"Enter your tolerance: ";
  cin>>tol;

  while (tol <= 0)
    {
  cout<<"Please enter another tolerance:";
  cin>>tol;
    }

  double term = tol + 1;
  double sum = 0;
  int k = 0;

  while(abs(term) > tol)
    {
   term = pow(-1, k)/( k+2 + log( pow(k , 2.5) + 1 ) );
   sum += term;
   k++;
    }

  cout<<"The total sum is: "<<sum<<endl;
  cout<<"The number of terms used is: "<<k<<endl;

  return 0;

}
