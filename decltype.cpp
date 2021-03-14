//C++14

template<typename Container, typename Index>
decltype(auto)
func_auth_access(Container&& c, Index i)
{
  auth_user();
  return std::forward<Container>(c)[i];
}


//C++11 Equivelent

template<typename Container, typename Index>
auto
func_auth_access(Container&& c, Index i)
-> decltype(std::forward<Container>(c)[i])
{
  auth_user();
  return std::forward<Container>(c)[i];
}
------------------------------------------

decltype(auto) f1()
{
  int x=0;
  ...
  return x; //decltype(x) is int so f1() return int
}

decltype(auto) f2()
{
  int x=0;
  ...
  return (x); //decltype((x)) is int& so f1() return int& -> undefined behaviour
}

---------------------------------------
//To know about type:

#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>

template<typename T>
class TD;

template<typename T>
void f(const T& param)
{
    //show T
    std::cout << "type for T: " << boost::typeindex::type_id_with_cvr<T>().pretty_name()<< std::endl;
    
    //show param
    std::cout << "type for param: " << boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name()<< std::endl;
}


int main()
{
    const int i = 100;
    auto x = i;
    auto y = &x;
    
    //Method 1
    //TD<decltype(x)> tx;
    //TD<decltype(y)> ty;
    
    //Method 2
    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(y).name() << std::endl;
    
    //Method 3 using boost typeindex
    
    f(x);
    f(y); 
}






