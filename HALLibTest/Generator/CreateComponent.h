#ifndef __GENERATOR_CREATE_COMPONENT_H__
#define __GENERATOR_CREATE_COMPONENT_H__

#include <Generator/BaseType.h>
#include <Generator/GeneratorPrivate.h>

namespace Generator{
	//=========================================================
	//SelectComponent PrimaryTemplate
	template<class ComponentType, class ImplementationType=typename ComponentType::type>
	struct SelectComponent;
	//=========================================================
    // Create
	template<	class Context,
				class ConfigurationRepository,
				class Origin
			>
	struct Create{
			typedef Component<Context, Origin, ConfigurationRepository> ComponentType;
			typedef typename SelectComponent<ComponentType>::type type;
	};
    //=========================================================
	struct NextSelector;
	//=========================================================
	//SelectComponent
	template<class Context, class Origin, class ConfigRep, class ImplementationType>
	struct SelectComponent<Component<Context, Origin, ConfigRep>, ImplementationType>
	{
		typedef Context current_context;
		typedef Origin origin_context;
		typedef ImplementationType type;
	};

	//Spezialisierung für NextSelector
	template<class Context, class Origin, class ConfigRep>
	struct SelectComponent<Component<Context, Origin, ConfigRep>, NextSelector>
	: SelectComponent<Component<	typename Origin::template BaseType<Context>::type,
	  	  	  	  	  	  	  	  	Origin, ConfigRep> >
	{};
// Alternative Implementierung der Spezialisierung für NextSelector
//	template<class Context, class Origin, class ConfigRep>
//	struct SelectComponent<Component<Context, Origin, ConfigRep>, NextSelector>
//	{
//		typedef typename Origin::template BaseType<Context>::type base_type;
//		typedef Component<base_type, Origin, ConfigRep> ComponentType;
//		typedef SelectComponent<ComponentType> select_component;
//
//		typedef typename select_component::type type;
//		typedef typename select_component::current_context current_context;
//		typedef typename select_component::origin_context origin_context;
//	};
	//=========================================================
    // Component PrimaryTemplate, wenn es keine Spezialisierung gibt
	template<class CurrentContext, class OriginContext, class ConfigurationRepository>
	struct Component{
		typedef NextSelector type;
	};
    //-------------------------------------
    // Fehlermeldung: Component_NotSupportedFor<Origin>
    template<class Origin, class ConfigurationRepository>
    struct Component<SelectorEnd, Origin, ConfigurationRepository>
    {
	    template<class Context> struct Component_NotSupportedFor{
	        typedef typename Context::ConfigurationError Error;
	    };
	    typedef Component_NotSupportedFor<Origin> type;
    };
    //=========================================================
    //SimpleSelector, erzeugt aus zwei beliebigen Typen
    // einen Context, base_type ist SelectorDefault
    // ein byte auf dem Stack
    template<class T1, class T2>
    struct SS : SelectorBase<>{
    	typedef T1 other_type1;
    	typedef T2 other_type2;
    };
    //=========================================================
    //CompositeSelector
    template<typename T, typename Selector_>
    struct CS{
        typedef T other_type;
        typedef Selector_ Selector;
        typedef CS<T, Selector> this_type;

        template<class CurrentContext>
            struct BaseType{
                typedef typename 
                    CompositeSelector::BaseType<CurrentContext, this_type>::type
                type;
            };
        template<class Context = CS<other_type, Selector> >
        struct getSelector;

        template<class OtherType, class S>
        struct getSelector<CS<OtherType, S> >{
        	typedef S type;
        };

    };
    //=========================================================
    //DoubleDispatchSelector
    template<class Selector1, class Selector2>
    struct DD{

        typedef Selector1 S1;
        typedef Selector2 S2;
    	typedef DD<S1, S2> this_type;

        template<class CurrentContext>
            struct BaseType{
                typedef typename 
                    DoubleDispatch::BaseType<CurrentContext, this_type>::type
                type;
            };

        template<int No, class Context=DD<S1, S2> >
        struct getSelector;

        template<class S_1, class S_2>
        struct getSelector<1, DD<S_1, S_2> >{
        	typedef S_1 type;
        };
        template<class S_1, class S_2>
        struct getSelector<2, DD<S_1, S_2> >{
        	typedef S_2 type;
        };
    };
    //=========================================================
    template<class CurrentContext, class OriginContext>
    struct getBaseType{
    	typedef typename OriginContext::template BaseType<CurrentContext>::type type;
    };
    template<class OriginContext>
    struct getBaseType<SelectorEnd, OriginContext>{
    	typedef SelectorEnd type;
    };
} // namespace Generator

#endif // __GENERATOR_CREATE_COMPONENT_H__
