#include<iostream>
#include<vector>
#include<cstring>
#include<ctime>
#include<boost/multiprecision/cpp_int.hpp>
#define mod(k) k%1000

namespace mp = boost::multiprecision;

typedef std::vector<std::vector<mp::cpp_int> > matrix;

matrix mul(matrix a, matrix b)
{
  matrix res;
  res.resize(2);
  res[0].resize(2);
  res[1].resize(2);
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      res[i][j] = 0;
      for(int k=0;k<2;k++){
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] = res[i][j];
      }
    }
  }
  return res;
}

matrix fast_pow(matrix x, int n) {
  matrix res;
  res.resize(2);
  res[0].resize(2);
  res[1].resize(2);
  res[0][0] = res[1][1] = 1;
  res[1][0] = res[0][1] = 0;
  while(n > 0) {
    if (n & 1) res = mul(x, res);
    x = mul(x, x);
    n >>= 1;
  }
  return res;
}

int main()
{
  matrix a;
  a.resize(2);
  a[0].resize(2);
  a[1].resize(2);
  a[1][1] = 0;
  a[0][1] = a[1][0] = a[0][0] = 1;

  int input;
  std::cin >> input;

  a = fast_pow(a, input);

  std::cout << "fib(" << input << ") = " << a[1][0] << std::endl;
  return 0;
}
