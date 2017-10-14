#//C++14

template<typename Container, typename Index>
decltype(auto)
func_auth_access(Container&& c, Index i)
{
  auth_user();
  return std::forward<Container>(c)[i];
}


#//C++11 Equivelent

template<typename Container, typename Index>
auto
func_auth_access(Container&& c, Index i)
-> decltype(std::forward<Container>(c)[i])
{
  auth_user();
  return std::forward<Container>(c)[i];
}
------------------------------------------
