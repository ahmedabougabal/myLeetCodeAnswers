#include <iostream>
#include <sstream>
#include <numeric>
using namespace std;

//* A/B + a/b = A * b + B * a / B * b (elementary school law)
//!(up = up) and (down = down)
//* then for A/B , A = (A * b + B * a)     and   B = (B * b) 
class Solution
{
public:
string fractionAddition(string expression)
{
  istringstream iss(expression);
  char _;
  int a, b , A=0 , B=1;
  while(iss >> a >> _ >> b){
    A = (A * b + B * a);
    B = (B * b);
    int g = abs(gcd(A,B));
    A = A / g;
    B = B / g;
  }
  return to_string(A)+ "/"+ to_string(B);
}
};
