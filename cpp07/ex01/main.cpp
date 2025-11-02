#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}



// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     size_t length = sizeof(arr) / sizeof(arr[0]);
//     std::cout << "Original array:" << std::endl;
//     ::iter(arr, length, print<int>);
//     std::cout << "Incremented array:" << std::endl;
//     ::iter(arr, length, increment<int>);
//     ::iter(arr, length, print<int>);
//     std::cout << "Decremented array:" << std::endl;
//     ::iter(arr, length, decrement<int>);
//     ::iter(arr, length, print<int>);
//     std::cout << "Doubled array:" << std::endl;
//     ::iter(arr, length, doubleValue<int>);
//     ::iter(arr, length, print<int>);
//     std::cout << "----------------------------------------" << std::endl;
//     std::string strArr[] = {"Hello", "World", "!"};
//     size_t strLength = sizeof(strArr) / sizeof(strArr[0]);
//     std::cout << "Original string array:" << std::endl;
//     ::iter(strArr, strLength, print<std::string>);

//     std::cout << "----------------------------------------" << std::endl;

//     char charArr[] = {'a', 'b', 'c', 'd', 'e'};
//     size_t charLength = sizeof(charArr) / sizeof(charArr[0]);
//     std::cout << "Original char array:" << std::endl;
//     ::iter(charArr, charLength, print<char>);
//     std::cout << "Incremented char array:" << std::endl;
//     ::iter(charArr, charLength, increment<char>);
//     ::iter(charArr, charLength, print<char>);
//     std::cout << "Decremented char array:" << std::endl;
//     ::iter(charArr, charLength, decrement<char>);
//     ::iter(charArr, charLength, print<char>);
//     std::cout << "Doubled char array:" << std::endl;
//     ::iter(charArr, charLength, doubleValue<char>);
//     ::iter(charArr, charLength, print<char>);
//     std::cout << "----------------------------------------" << std::endl;
//     return 0;
// }



//---------------------------------------------------------------------------
//                   //test_main


