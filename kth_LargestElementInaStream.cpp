#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KthLargest
{
private:
  int n;
  vector<int> vec;

public:
  void setNum(int n)
  {
    this->n = n;
  }
  int getNum()
  {
    return this->n;
  }
  void setVec(vector<int> inp)
  {
    this->vec = inp;
  }
  vector<int> getVec()
  {
    return this->vec;
  }
  KthLargest(int k, vector<int> &nums)
  {
    setNum(k);
    setVec(nums);
    sort(vec.begin(), vec.end(), greater<>());
  }
  int add(int val)
  {
    auto it = lower_bound(vec.begin(), vec.end(), val, greater<>());
    vec.insert(it, val);
    return vec[getNum() - 1];
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
