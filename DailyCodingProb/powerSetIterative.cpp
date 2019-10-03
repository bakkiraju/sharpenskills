#include <bits/c++config.h>
#include <bits/stdc++.h>

using namespace std;

/*
  Ex: {1,2} -> {{},{1},{2},{1,2}}
*/
void printPowerSet(vector<int> &v) {
  cout << "{";
  const auto delim1 = ",";
  const auto *sep1 = "";

  for (int i = 0; i < pow(2, v.size()); i++) {

    cout << sep1 << "{";
    const auto delim = ",";
    const auto *sep = "";

    for (int j = 0; j < v.size(); j++) {
      if (i & (1 << j)) {
        cout << sep << v.at(j);
        sep = delim;
      }
    }
    cout << "}";
    sep1 = delim1;
  }
  cout << "}" << endl;
}

int main() {
  vector<int> v = {1, 2, 3};
  printPowerSet(v);
  return 0;
}
