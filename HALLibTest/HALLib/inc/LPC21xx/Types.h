#ifndef __LPC21XX_TYPES_H__
#define __LPC21XX_TYPES_H__

#include <Generator/BaseType.h>

/*
    these Types here do only define a hierarchie of Types
    divided into general and specific Types
*/
namespace LPC21xx{
using Generator::BaseType;

// the general Base, defining all general behaviour
struct Base : Generator::SelectorBase<>{
	static char const* name(){return "LPC21xx::Base"; }
};
struct LPC21x1 : Generator::SelectorBase<Base>{
	static char const* name(){return "LPC21xx::LPC21x1"; }
};
struct LPC21x2 : Generator::SelectorBase<LPC21x1>{
	static char const* name(){return "LPC21xx::LPC21x2"; }
};
struct LPC21x4 : Generator::SelectorBase<LPC21x2>{
	static char const* name(){return "LPC21xx::LPC21x4"; }
};
struct LPC21x6 : Generator::SelectorBase<LPC21x4>{
	static char const* name(){return "LPC21xx::LPC21x6"; }
};
struct LPC21x8 : Generator::SelectorBase<LPC21x6>{
	static char const* name(){return "LPC21xx::LPC21x8"; }
};

}//namespace LPC21xx
#endif /* __LPC21XX_TYPES_H__ */
