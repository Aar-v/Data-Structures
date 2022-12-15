#include <bits/stdc++.h>
using namespace std;

class HeapBuilder {
 private:
  vector<int> H;
  vector< pair<int, int> > swaps;

  void WriteResponse() const {
    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); ++i) {
      cout << swaps[i].first << " " << swaps[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    H.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> H[i];
  }

  int leftValue(int i){
    return 2*i + 1;
  }

  int rightValue(int i){
    return 2*i + 2;
  }

  int parent(int i){
    return floor((i-1)/2);
  }

  void shiftdown(int i){
    int minIndex = i;
    int l = leftValue(i);
    if(l <= H.size()-1 && H[l] < H[minIndex])
      minIndex = l;
    int r = rightValue(i);
    if(r <= H.size()-1 && H[r] < H[minIndex])
      minIndex = r;
    if(i != minIndex){
      swap(H[i], H[minIndex]);
      swaps.push_back(make_pair(i, minIndex));
      shiftdown(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps.clear();

      int n = H.size();  
      for(int i = (n-1)/2; i+1 != 0; i--){
        shiftdown(i);
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}