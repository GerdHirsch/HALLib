#ifndef __GENERATOR_TEST_HELPER_H__
#define __GENERATOR_TEST_HELPER_H__

#include <iostream>
#include <string>
#include <sstream>

#include <typeinfo>
#include <cppunit/extensions/HelperMacros.h>

#include <Generator/BaseType.h>
#include <Generator/CreateComponent.h>
#include <Generator/Tools.h>
#include <Generator/Printers.h>

namespace Generator
{
//forward Declarations
//---------------------------------------------------------------------
template<	int num, std::type_info const* expected[],
			class Context, class Origin>
struct TestBaseType;
//=====================================================================
// Interface
template<
	class Context,
	std::type_info const* expected[]
		>
struct TestAllBaseTypes
{
	typedef TestBaseType<0, expected, Context, Context> type;

	static void test(){
		type::test();
	}
};

//---------------------------------------------------------------------
template<	int num, std::type_info const* expected[],
			class Context, class Origin>
struct TestBaseType{

    typedef TestBaseType<
    		num+1,
    		expected,
    		typename Origin::template BaseType<Context>::type,
    		Origin> base_type;


	static void test(){
		char const* message = convertInt(num).c_str();
		CPPUNIT_ASSERT_EQUAL_MESSAGE(message, (*expected[num]).name(), typeid(Context).name() );
		// für Compiler die einen leeren string bei typeid(...).name() liefern
		CPPUNIT_ASSERT_MESSAGE(message, *expected[num] == typeid(Context) );
		base_type::test();
    }
};
//------------------------------
// TestBaseType Spezialisierung für SelectorEnd
template<int num, std::type_info const* expected[], class Origin>
struct TestBaseType<num, expected, SelectorEnd, Origin>{

	static void test(){
		char const* message = convertInt(num).c_str();
		CPPUNIT_ASSERT_EQUAL_MESSAGE(message, (*expected[num]).name(), typeid(SelectorEnd).name() );
		// für Compiler die einen leeren string bei typeid(...).name() liefern
		CPPUNIT_ASSERT_MESSAGE(message, *expected[num] == typeid(SelectorEnd) );
    }
};
//---------------------------------------------------------------------
struct TestTypeId{
	template<	class Expected, class Result>
	static void test(char const* message){
		CPPUNIT_ASSERT_EQUAL_MESSAGE(message,
				typeid(Expected).name(), typeid(Result).name() );
		// für Compiler die einen leeren string bei typeid(...).name() liefern
		CPPUNIT_ASSERT_MESSAGE(message,
				typeid(Expected) == typeid(Result) );
	}
};
//---------------------------------------------------------------------
template<class Expected, class Result>
struct TestComponent{
	static void test(){
		TestTypeId::test
		<typename Expected::Origin, typename Result::Origin>
		("Origin");

		TestTypeId::test
		<typename Expected::Selector,typename Result::Selector>
		("Selector");
    }
};
//---------------------------------------------------------------------
// wird von Component für TestComponent erzeugt
template <class Selector_, class Origin_, class ConfigRep_=EmptyRepository >
struct TestImpl{
	typedef Selector_ Selector;
	typedef Origin_ Origin;
	typedef ConfigRep_ ConfigRep;

	static void print(){
        std::cout << "TestImpl" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Selector: ";
        ContextPrinter<Selector>::print();
        std::cout << "----------------------" << std::endl;
        std::cout << "  Origin: "; 
        ContextPrinter<Origin>::print();
    }
};
} // namespace Generator

#endif //__GENERATOR_TEST_HELPER_H__
