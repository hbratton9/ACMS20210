#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> process_line (const string &line);

int main (int argc, char* argv[]) {

  //writes to a file
  ofstream ofs("hw_5_ex_5_solution.dat");

  //define ifs and open file
  ifstream ifs(argv[1]);

  //checks if file can be opened
  if (!ifs.is_open()) {
    cout<<"The file could not be opened!"<<endl;
    return 0;
  }

  vector<vector<int>> matrix_1;
  vector<vector<int>> matrix_2;
  vector<vector<int>> matrix_result;

  string line;
  //goes through file and adds each value to vectors
  while (getline(ifs, line)) {
    //when empty line is encountered, break
    if (line.size() == 0) {
      break;
    }
    matrix_1.push_back(process_line(line));
  }
  while (getline(ifs,line)) {
    matrix_2.push_back(process_line(line));
  }

  //loops through each line
  for(int i = 0; i < matrix_1.size(); i++) {
    //to hold sum of each row
    vector<int>row = { };
    for(int j = 0; j < matrix_1[i].size(); j++){
      //adds together numbers in each line
      row.push_back(matrix_1[i][j] + matrix_2[i][j]);
    }
    //add sums to the result matrix
    matrix_result.push_back(row);
  }
  ifs.close();

  for(int i = 0; i < matrix_result.size(); i++){
    for(int j = 0; j <matrix_result[i].size(); j++){
      ofs << matrix_result[i][j] << ' ';
    }
    ofs << endl;
  }

  ofs.close(); 
  return 0;
}

vector<int> process_line (const string &line) {

  //define iss variable and open string line to use
  istringstream iss(line);

  string elem;
  //vector to hold processed data
  vector<int> p_line;

  //processes lines (send elem into iss separated by ;)
  while (getline(iss, elem, ' ')) {
    //add each element back to some vector p_line
    p_line.push_back(stoi(elem));
  }

  return p_line;
}
