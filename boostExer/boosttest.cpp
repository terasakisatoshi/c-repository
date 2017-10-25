#include <boost/ptr_container/ptr_list.hpp>
#include <iostream>

using namespace std;

class foo
{
private:
   int Num;
public:
  foo() : Num(0){}//default Constructor
  explicit foo(int a): Num(a){}
  ~foo(){cout << "Destructed" << endl;} // destructor
  void print() {cout << Num << endl;}
};

int main()
{
  boost::ptr_list<foo> ls;
  boost::ptr_list<foo>::iterator itls;

  ls.push_back(new foo());
  ls.push_back(new foo(1));
  ls.push_back(new foo(2));

  for (itls = ls.begin();
       itls != ls.end();
       itls++)
    {
      itls->print();
    }

  ls.clear(); // All pointers held in list are deleted.
}