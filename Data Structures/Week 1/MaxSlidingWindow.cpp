#include <bits/stdc++.h>
using namespace std;
int main(){
  int n ,m,a=0,i=0;
  cin >> n;
  int A[n];
  for ( i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  cin >> m;

  queue<int> window;
  while (i <= n-m){
    for (int j =0; j<=m;j++)
    {
        window.push(A[j]);
        i++;
    }
    if (window.front() >= a) a = window.front();
    cout << a;
    i++;
  }
 return 0;
}