#ifndef __HALMOCK_COMPONENT_TYPES_H__
#define __HALMOCK_COMPONENT_TYPES_H__

//#include "../HALLibTestApp.h"
#include <Generator/BaseType.h>
#include <LPC213x/Types.h>
#include <LPC214x/Types.h>
/*
    these Types here do only define Types to
    select specific templates
    dieser header definiert die namen der Geräte die
    für die Tests benötigt werden.
*/

namespace Mock
{
	struct Traits{
		static char const* name(){ return "Mock::Traits";}
	};
	struct Register{
		static char const* name(){ return "Mock::Register";}
	};

	struct Base;

	// BaseType für alle typen
//	template<class CurrentContext, class NextSelector>
//	struct BaseType : NextSelector::BaseType<CurrentContext>{};

	template<class CurrentContext>
	struct BaseType3x : LPC213x::BaseType<CurrentContext>{};
	template<class CurrentContext>
	struct BaseType4x : LPC214x::BaseType<CurrentContext>{};

	template<>
	struct BaseType3x<LPC21xx::LPC21x1>{
		typedef Base type;
	};

	template<>
	struct BaseType4x<LPC21xx::LPC21x1>{
		typedef Base type;
	};

	struct Base : Generator::SelectorBase<LPC21xx::Base>{
		static char const* name(){ return "Mock::Base";}
	};
	// kein template übergeben sondern einen Typ, der ein Template enthält und
	// weis an welches weitergeleitet werden soll -> LPC213x::BaseType oder LPC214x::

	struct LPC2149 : Generator::SelectorBase<LPC214x::LPC2148, BaseType4x>{
		static char const* name(){ return "Mock::LPC2141";}
	};
	struct LPC2141 : Generator::SelectorBase<LPC214x::LPC2141, BaseType4x>{
		static char const* name(){ return "Mock::LPC2141";}
	};
	struct LPC2142 : Generator::SelectorBase<LPC214x::LPC2142, BaseType4x>{
		static char const* name(){ return "Mock::LPC2142";}
	};
	struct LPC2144 : Generator::SelectorBase<LPC214x::LPC2144, BaseType4x>{
		static char const* name(){ return "Mock::LPC2144";}
	};
	struct LPC2146 : Generator::SelectorBase<LPC214x::LPC2146, BaseType4x>{
		static char const* name(){ return "Mock::LPC2146";}
	};
	struct LPC2148 : Generator::SelectorBase<LPC214x::LPC2148, BaseType4x>{
		static char const* name(){ return "Mock::LPC2148";}
	};

	struct LPC2131 : Generator::SelectorBase<LPC213x::LPC2131, BaseType3x>{
		static char const* name(){ return "Mock::LPC2131";}
	};
	struct LPC2132 : Generator::SelectorBase<LPC213x::LPC2132, BaseType3x>{
		static char const* name(){ return "Mock::LPC2132";}
	};
	struct LPC2134 : Generator::SelectorBase<LPC213x::LPC2134, BaseType3x>{
		static char const* name(){ return "Mock::LPC2134";}
	};
	struct LPC2136 : Generator::SelectorBase<LPC213x::LPC2136, BaseType3x>{
		static char const* name(){ return "Mock::LPC2136";}
	};
	struct LPC2138 : Generator::SelectorBase<LPC213x::LPC2138, BaseType3x>{
		static char const* name(){ return "Mock::LPC2138";}
	};
} // end namespace Mock

#endif //__HALMOCK_COMPONENT_TYPES_H__
