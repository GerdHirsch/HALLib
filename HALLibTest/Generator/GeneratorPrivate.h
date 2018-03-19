#ifndef __GENERATOR_PRIVATE_H__
#define __GENERATOR_PRIVATE_H__
namespace Generator{
namespace CompositeSelector{
    template<class CurrentContext, class CSOrigin>
        struct BaseType{
            typedef CS<
                typename CSOrigin::other_type,
                typename CSOrigin::Selector::template BaseType<
                    typename CurrentContext::Selector>::type> 
            type;
        };
        template<class T, class CSOrigin>
        struct BaseType<CS<T, SelectorEnd>, CSOrigin >{
            typedef SelectorEnd type;

        };
} // namespace CompositeSelector

namespace DoubleDispatch{
        //Primary Template ohne Definition
        template<class CurrentContext, class DDOrigin>
        struct BaseType;
        
        //----------------------
        // Double Specializations
        // Selector2
        template<class Selector1, class Selector2, class DDOrigin>
        struct BaseType<DD<Selector1, Selector2>, DDOrigin >{
            typedef DD<
            	Selector1,
                typename DDOrigin::S2::template BaseType<Selector2>::type
            > type;
        };
        // Selector1
        template<class Selector1, class DDOrigin>
        struct BaseType<DD<Selector1, SelectorEnd>, DDOrigin >{
            typedef DD<
                typename DDOrigin::S1::template BaseType<Selector1>::type,
                typename DDOrigin::S2
            > type;
        };
        // SelectorEnd Recursion
        template<class DDOrigin>
        struct BaseType<DD<SelectorDefault, SelectorEnd>, DDOrigin>{
            typedef SelectorEnd type;
        };
        // SelectorEnd für CS<...>
        template<class T1, class T2, class DDOrigin>
        struct BaseType<DD<
        	CS<T1, SelectorDefault>, CS<T2, SelectorEnd> >, DDOrigin>{
            typedef SelectorEnd type;
        };

        //------------------------
        // SelectorEnd DDOrigin::S1
        // Optimierung für Selector1, SelectorDefault, SelectorEnd DDOrigin::S1
        // SelectorEnd wird anstelle SelectorDefault übergeben
        template<class Selector1, class DDOrigin>
        struct BaseType<DD<DD<Selector1, SelectorDefault>, SelectorEnd>, DDOrigin>{
            typedef DD<
                typename DDOrigin::S1::template BaseType<DD<Selector1, SelectorEnd> >::type,
                typename DDOrigin::S2
            > type;
        };
        //------------------------
        // SelectorEnd Recursion für DD<DD<
        template<class DDOrigin>
        struct BaseType<DD<DD<SelectorDefault, SelectorDefault>, SelectorEnd>, DDOrigin>{
            typedef SelectorEnd type;
        };
        //------------------------
        // SelectorEnd Recursion für DD<S1, DD<
        template<class DDOrigin>
        struct BaseType<DD<SelectorDefault, DD<SelectorDefault, SelectorEnd> >, DDOrigin>{
            typedef SelectorEnd type;
        };

        //------------------------
        // Benötigt für DD<DD<DD< ...
        // DD< DD< DD< SelectorDefault, SelectorDefault >, SelectorDefault >, SelectorEnd >
        // wird zu
        // DD< SelectorEnd, DDS::S3 > ),
        template<class Selector2, class DDOrigin>
        struct BaseType<DD<SelectorEnd, Selector2>, DDOrigin>{
            typedef SelectorEnd type;
        };
} // namespace DoubleDispatch

} // namespace Generator
#endif // __GENERATOR_PRIVATE_H__
