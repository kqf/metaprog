#include "iostream"
using std::cout

template< int i >
class LOOP
{
public:
  static inline void EXEC()
  {
    cout << "A-" << i << " ";
    LOOP < i - 1 >::EXEC();
    cout << "B-" << i << " ";
  }
};

class LOOP< 0 >
{
public:
  static inline void EXEC()
  {
    cout << "A-" << i;
    cout << "\n";
    cout << "B-" << i;
  }
};
