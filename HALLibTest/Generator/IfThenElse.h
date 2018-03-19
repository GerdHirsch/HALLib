#ifndef IFTHENELSE_H_
#define IFTHENELSE_H_

namespace Generator
{
	template <bool condition, typename Then, typename Else>
	struct IF
	{
		typedef Then type;
	};

	template<typename Then, typename Else>
	struct IF<false, Then, Else>
	{
		typedef Else type;
	};
}

#endif /* IFTHENELSE_H_ */
