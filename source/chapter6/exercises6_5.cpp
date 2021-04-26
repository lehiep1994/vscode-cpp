#include <iostream>
#include <iomanip>
#include <cctype>
#include <memory>
#include <vector>

using namespace std;
using Class = vector<size_t>;                     // Type alias for vector storing the ages for student in a class
using PClass = shared_ptr<Class>;                  // Type alias for a smart pointer to a Class
using PClasses = vector<PClass>;                   // Type alias for a vector of pointers to Class objects

int main(){
  auto pclasses = make_shared <PClasses>();       // Pointer to vector of pointers to Class objects
  size_t age {};
  PClass pclass;
  char answer {};
  while (true)
  {
    pclass = make_shared<Class>();
    pclasses->push_back(pclass);

    std::cout << "Enter ages for the class, enter 0 to end:\n";
    while (true)
    {
      std::cin >> age;
      if (!age) break;
      pclass->push_back(age);
    }
    cout << "Do you want to enter ages for another class(Y or N): ";
    cin >> answer;
    if (toupper(answer) == 'N') break;
  }

  const size_t perline {5};
  size_t count {};
  size_t class_id {};
  for (auto& pclass : *pclasses)
  {
    count = 0;
    cout << "\nAges of student in class " << ++class_id << ":\n";
    for (auto age : *pclass){
      cout << std::setw(5) << age;
      if (++count % perline) continue;
      cout << std::endl;
    }
    cout << std::endl;
  }
  return EXIT_SUCCESS;
}