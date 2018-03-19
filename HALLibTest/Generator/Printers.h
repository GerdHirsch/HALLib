#ifndef __GENERATOR_PRINTERS_H_
#define __GENERATOR_PRINTERS_H_

//#include <iostream>

#include <Generator/BaseType.h>
#include <Generator/CreateComponent.h>
namespace Generator{

//---------------------------------------------------------------------
template<class Selector>
struct ContextPrinter{
	template<class OStream>
	static void print(OStream& os){
		name<Selector>::print(os);
//		os << Selector::name();
	}
};
template<class T1, class T2>
struct ContextPrinter<SS<T1, T2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "SS<";
		ContextPrinter<T1>::print(os);
		os << ", ";
		ContextPrinter<T2>::print(os);
		os << ">";
	}
};
template<class Component, unsigned int Number>
struct ContextPrinter<NO<Component, Number> >{
	template<class OStream>
	static void print(OStream& os){
		os << "NO< ";
		ContextPrinter<Component>::print(os);
		os << ", " << Number << " >";
	}
};
template<class S1, class S2>
struct ContextPrinter<DD<S1, S2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "DD< ";
		 ContextPrinter<S1>::print(os);
		 os << ", ";
		 ContextPrinter<S2>::print(os);
		os << " >";
	}
};
template<class T, class S>
struct ContextPrinter<CS<T, S> >{
	template<class OStream>
	static void print(OStream& os){
		os << "CS< ";
		 ContextPrinter<T>::print(os);
		 os << ", ";
		 ContextPrinter<S>::print(os);
		os << " >";
	}
};
//---------------------------------------------------------------------
template<class Context>
struct PrintComponent{
	typedef SelectComponent<
			Component<Context, Context, EmptyRepository> > component_selector;

	template<class OStream>
	static void print(OStream& os){
		os
//			<< std::endl
			<< "Origin"
//			<< std::endl
			;
		ContextPrinter<typename component_selector::origin_context>::print(os);
		os
//			<< std::endl
			<< "Selector"
//			<< std::endl
			;
		ContextPrinter<typename component_selector::current_context>::print(os);
	}
};
//---------------------------------------------------------------------
//template <bool condition, typename Then, typename Else>
//struct IF;
////---------------------------------------------------------------------
//template<typename T1, typename T2>
//struct isSameType;

//---------------------------------------------------------------------
template<class Context>
struct PrintAllComponents{
	typedef SelectComponent<Component<Context, Context, EmptyRepository> > component_selector;

	typedef typename component_selector::origin_context origin;
	typedef typename component_selector::current_context selector;

	// selector wird zu SelectorEnd wenn es keine generelleren Components
	// als die Spezialisierung für Component<SelectorEnd, ..> gibt
	// ImplType ist Component_NotSupportedFor<Origin>
	typedef typename getBaseType<selector, origin>::type base_type;

	typedef PrintAllComponents<base_type> base;

	template<class OStream>
	static void print(OStream& os){

//		std::cout << std::endl << "========================" << std::endl;
//		std::cout << "Origin" << std::endl;
		ContextPrinter<typename component_selector::origin_context>::print(os);
//		std::cout << std::endl << "Selector" << std::endl;
		ContextPrinter<typename component_selector::current_context>::print(os);

		base::print(os);
	}
};
template<>
struct PrintAllComponents<SelectorEnd>{
	template<class OStream>
	static void print(OStream& os){
//		std::cout << std::endl << "========================" << std::endl;
//		std::cout << std::endl << "SelectorEnd No Components available" << std::endl;
		ContextPrinter<SelectorDefault>::print(os);
//		std::cout << std::endl;
	}
};
//---------------------------------------------------------------------
template<class Context, class Origin=Context, int num=0>
struct PrintBaseType{

    typedef PrintBaseType<typename Origin::template BaseType<Context>::type, Origin, num+1> base;
	template<class OStream>
    static void print(OStream& os){
        //std::cout << std::endl<< "basetype " << num << std::endl;
        os
//        	<< std::endl
        	<< "&typeid( "
//        	<< std::endl
        	;
        ContextPrinter<Context>::print(os);
        os << " ),";
        base::print(os);

    }
};
template<class Origin, int num>
struct PrintBaseType<SelectorEnd, Origin, num>{
	template<class OStream>
	static void print(OStream& os){
        //std::cout << std::endl<< "basetype " << num << std::endl;
        os
//        	<< std::endl
        	<< "&typeid( "
//        	<< std::endl
        	;
        ContextPrinter<SelectorEnd>::print(os);
        os << " )";
//        std::cout << "Rekursionen: " << num << std::endl;
    }
};
} // namespace Generator

#endif /* __GENERATOR_PRINTERS_H_ */
