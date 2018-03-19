#ifndef __GENERATOR_TOOLS_H_
#define __GENERATOR_TOOLS_H_

#include <sstream>

#include <Generator/ForEachClassIn.h>
#include <Generator/IfThenElse.h>

namespace Generator{
//---------------------------------------------------------------------
inline
std::string convertInt(int number)
{
   std::stringstream s;
   s << number;
   return s.str();
}
//---------------------------------------------------------------------
// todo: von Boost verwenden
template<typename T1, typename T2>
struct is_sameType{
	enum{value = false};
};
template<typename T>
struct is_sameType<T, T>{
	enum {value = true};
};
//---------------------------------------------------------------------
template <std::size_t N>
struct type_of_size
{
    typedef char type[N];
};

template <typename T, std::size_t Size>
typename type_of_size<Size>::type& sizeof_array_helper(T(&)[Size]);

#define sizeof_array(pArray) sizeof(sizeof_array_helper(pArray))

}// namespace Generator

#endif /* __GENERATOR_TOOLS_H_ */
