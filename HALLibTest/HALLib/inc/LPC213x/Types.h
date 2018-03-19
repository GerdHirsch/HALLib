#ifndef __LPC213X_TYPES_H__
#define __LPC213X_TYPES_H__

#include <Generator/BaseType.h>
#include <LPC21xx/Types.h>
/*
    these Types here do only define a hierarchie of Types
    divided into general and specific Types
*/
namespace LPC213x{

//Standardverhalten verwenden
template<class CurrentSelector>
struct BaseType : LPC21xx::BaseType<CurrentSelector> {};

struct LPC2131 : Generator::SelectorBase<LPC21xx::LPC21x1>{
	static char const* name(){return "LPC213x::LPC2131"; }};

struct LPC2132 : Generator::SelectorBase<LPC21xx::LPC21x2, BaseType>{
	static char const* name(){return "LPC213x::LPC2132"; }};

struct LPC2134 : Generator::SelectorBase<LPC21xx::LPC21x4, BaseType>{
	static char const* name(){return "LPC213x::LPC2134"; }};

struct LPC2136 : Generator::SelectorBase<LPC21xx::LPC21x6, BaseType>{
	static char const* name(){return "LPC213x::LPC2136"; }};

struct LPC2138 : Generator::SelectorBase<LPC21xx::LPC21x8, BaseType>{
	static char const* name(){return "LPC213x::LPC2138"; }};


template<>
struct BaseType<LPC21xx::LPC21x2>{
	typedef LPC2131 type;
};
template<>
struct BaseType<LPC21xx::LPC21x4>{
	typedef LPC2132 type;
};
template<>
struct BaseType<LPC21xx::LPC21x6>{
	typedef LPC2134 type;
};
template<>
struct BaseType<LPC21xx::LPC21x8>{
	typedef LPC2136 type;
};
////some primitiv BoardType supporting some Features (1,2,3)
//struct LPC2131 : Generator::SelectorBase<LPC21xx::Base>{};
//struct LPC2132 : Generator::SelectorBase<LPC2131>{};
//
////more elaborated Types supporting elaborated Features (4)
//struct LPC2134 : Generator::SelectorBase<LPC2132>{};
//struct LPC2136 : Generator::SelectorBase<LPC2134>{};
//struct LPC2138 : Generator::SelectorBase<LPC2136>{};
}
#endif /* __LPC213X_TYPES_H__ */
