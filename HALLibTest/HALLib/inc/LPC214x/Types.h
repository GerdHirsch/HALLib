#ifndef __LPC214X_TYPES_H__
#define __LPC214X_TYPES_H__

#include <Generator/BaseType.h>
#include <LPC21xx/Types.h>

/*
    these Types here do only define a hierarchie of Types
    divided into general and specific Types
    dieser header enthält die definitionen der prozessoren
*/
namespace LPC214x{

//Standardverhalten verwenden
template<class CurrentSelector>
struct BaseType : LPC21xx::BaseType<CurrentSelector> {};

struct LPC2141 : Generator::SelectorBase<LPC21xx::LPC21x1>{
	constexpr static char const* name(){return "LPC214x::LPC2141"; }};

struct LPC2142 : Generator::SelectorBase<LPC21xx::LPC21x2, BaseType>{
	static char const* name(){return "LPC214x::LPC2142"; }};

struct LPC2144 : Generator::SelectorBase<LPC21xx::LPC21x4, BaseType>{
	static char const* name(){return "LPC214x::LPC2144"; }};

struct LPC2146 : Generator::SelectorBase<LPC21xx::LPC21x6, BaseType>{
	static char const* name(){return "LPC214x::LPC2146"; }};

struct LPC2148 : Generator::SelectorBase<LPC21xx::LPC21x8, BaseType>{
	static char const* name(){return "LPC214x::LPC2148"; }};


template<>
struct BaseType<LPC21xx::LPC21x2>{
	typedef LPC2141 type;
};
template<>
struct BaseType<LPC21xx::LPC21x4>{
	typedef LPC2142 type;
};
template<>
struct BaseType<LPC21xx::LPC21x6>{
	typedef LPC2144 type;
};
template<>
struct BaseType<LPC21xx::LPC21x8>{
	typedef LPC2146 type;
};
}
#endif //__LPC213X_TYPES_H__

