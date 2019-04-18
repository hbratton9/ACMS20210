#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//declare all functions you will need
double x_mean(const vector<double> &x_obs);
double y_mean(const vector<double> &y_obs);
double x_std(const vector<double> &x_obs);
double y_std(const vector<double> &y_obs);
double xy_corr(const vector<double> &x_obs, const vector<double> &y_obs);
void lsrl(const vector<double> &x_obs, const vector<double> &y_obs);

int main() {

//creates vectors for (x, y) pairs
vector<double> x_obs;
vector<double> y_obs;

cout<<"Please enter a finite sequence of alternating (x , y) real number values. "<<endl;
cout<<"There should be an equal number of x's and y's, and if you would like to quit merely enter a string."<<endl;

//temporary scope
{
  double x;
  double y;

  //while loop to get (x, y) pairs, alternating between x & y
  while (true) {
    cout<<"Please enter an x-value: ";
    cin>>x;
    //if strings are entered, prompt terminates
    if (cin.fail()) {
      break;
    }
    else {
      //adds values to vector of obs
      x_obs.push_back(x);
    }

    cout<<"Please enter a y-value: ";
    cin>>y;
    //if strings are entered, prompt terminates
    if (cin.fail()) {
      break;
    }
    else {
        //adds values to vector of obs
      y_obs.push_back(y);
    }
  }
}
//checks if sample size, n, is too small to provide useful regression analysis
if (x_obs.size() < 2 || y_obs.size() < 2) {
  cout<<"Sorry, but your sample is too small to be useful.";
  return 0;
}
cout<<endl;
cout<<endl;
//deliver results to the user
cout<<"The sample mean of x is: "<<x_mean(x_obs)<<endl;
cout<<"The sample mean of y is: "<<y_mean(y_obs)<<endl;
cout<<"The sample standard deviation of x is: "<<x_std(x_obs)<<endl;
cout<<"The sample standard deviation of y is: "<<y_std(y_obs)<<endl;
cout<< xy_corr(x_obs, y_obs)<<endl;
lsrl(x_obs, y_obs);

  return 0;
}

//function for x mean
double x_mean(const vector<double> &x_obs) {
  double total = 0.0;
  for (int i = 0; i < x_obs.size(); i++) {
    total += x_obs[i];
  }
  return total/x_obs.size();
}

//function for y mean
double y_mean(const vector<double> &y_obs) {
  double total = 0.0;
  for (int i = 0; i < y_obs.size(); i++) {
    total += y_obs[i];
  }
  return total/y_obs.size();
}

//function for x standard deviation
double x_std(const vector<double> &x_obs) {
  double total = 0.0;
  double x_bar = x_mean(x_obs);
  for (int elem: x_obs) {
    total += pow( (elem - x_bar) , 2);
  }
  return pow( total/(x_obs.size() - 1) , .5);
}

//function for y standard deviation
double y_std(const vector<double> &y_obs) {
  double total = 0.0;
  double y_bar = y_mean(y_obs);
  for (int elem: y_obs) {
    total += pow( (elem - y_bar) , 2);
  }
  return pow( total/(y_obs.size() - 1) , .5);
}

//function to calculate correlation coefficient
double xy_corr(const vector<double> &x_obs, const vector<double> &y_obs) {
  double total = 0.0;
  double x_bar = x_mean(x_obs);
  double y_bar = y_mean(y_obs);
  double xstd = x_std(x_obs);
  double ystd = y_std(y_obs);
  double x_part;
  double y_part;

  //calculates (observation - mean)/standard deviation
  for (int i = 0; i < x_obs.size(); i++) {
    x_part = x_obs[i] - x_bar;
    x_part /= xstd;
    y_part = y_obs[i] - y_bar;
    y_part /= ystd;
    total += (x_part * y_part);
  }
  if (xstd == 0 || ystd == 0) {
    cout<<"Your sample correlation, r, is undefined."<<endl;
    return 0.0;
  }
  else {
  cout<<"Your sample correlation, r, is: ";
  return total/(x_obs.size() - 1);
  }
}

//calculates least square regression line
void lsrl(const vector<double> &x_obs, const vector<double> &y_obs) {
  double xstd = x_std(x_obs);
  double ystd = y_std(y_obs);
  double x_bar = x_mean(x_obs);
  double y_bar = y_mean(y_obs);
  if ( (xstd && ystd) != 0) {
    double m = xy_corr(x_obs, y_obs) * (ystd/xstd);
    double b = y_bar - m * x_bar;
    cout<<"The least square regression line is y_hat = "<<setprecision(3)<<fixed<<m<<"x + "<<b<<endl;
  }
  else if (xstd == 0) {
    cout<<"The least square regression line is undefined."<<endl;
  }
  else if (ystd == 0) {
    cout<<"The least square regression line is a horizontal line given by the only y value in the sample."<<endl;
  }
  return;
}
