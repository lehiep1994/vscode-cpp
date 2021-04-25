#include <iostream>
#include <cmath>

using namespace std;
int main()
{
  size_t n {};
  cout << "Enter the number of array elements: ";
  cin >> n;
  
  auto values = new (double[n]);
  for (size_t i {}; i < n; ++i)
    *(values+i) = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (size_t i {}; i < n; ++i)
    sum += *(values + i);

  cout << "result is " << sqrt(6.0*sum) << endl;
  delete[] values;                                              // Don't forget to free the memory!
}