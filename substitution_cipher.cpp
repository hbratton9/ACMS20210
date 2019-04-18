#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main () {

  //opens key file
  ifstream ifs("key.txt");
  //file to which output is written
  ofstream ofs("decrypted_text.txt");

  //initializes map for key value pairs
  map<char, char> key;
  char x, y;
  while (ifs>>x>>y) {
    //builds map for whatever key is passed in
    //fills up the map
    key[x] = y;
    }
  //opens file to be decrypted
  ifstream ifs_1("encrypted_text.txt");
  string word;

  //reads through each word passed in from encrypted text
  while(getline(ifs_1, word)) {
      for (int i = 0; i < word.length(); i++) {
            //decryption
            word[i] = key[word[i]];
            //outputs results to the file
            ofs<<word[i];
          }
          ofs<<'\n';
        }
  return 0;
}
