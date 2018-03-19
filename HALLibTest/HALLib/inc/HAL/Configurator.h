#ifndef __CONFIGURATOR_H__
#define __CONFIGURATOR_H__

namespace HAL
{
struct Configurer{

    template<typename ComponentType, typename BaseType>
    struct Rebind{
        typedef typename ComponentType::template Configure<BaseType>::type Type;
    };
};
template<class Component>
class Configurator{
	template <class BaseType, bool isUsed>
	struct Create{
        template<class BASE> struct PinAlreadyUsed{
            typedef typename BASE::ConfigurationError Error;
        };

        typedef typename Component::template Impl<BaseType> ImplType;
        typedef PinAlreadyUsed<ImplType> type;
	};
	template<class BaseType>
	struct Create<BaseType, false>{
        typedef typename Component::template Impl<BaseType> type;
	};
public:
	template<class BaseType>
	struct Configure
	{
		enum {isUsed = Component::template getConstraint<BaseType>::value };
		typedef typename Create<BaseType, isUsed>::type type;
	};
};
// Gcc kann das template als default Argument nicht auflösen,
// darum wird die obige Implementierung mit Create benötigt
//    template<class Component>
//    struct ConfiguratorOld{
//            template<   class BaseType,
//                        bool isUsed = Component::template getConstraint<BaseType>,::value
//                        >
//            struct Configure
//            {
//	            template<class BASE> struct PinAlreadyUsed{
//	                typedef typename BASE::ConfigurationError Error;
//	            };
//
//	            typedef PinAlreadyUsed<BaseType> type;
//            };
//
//            template<class BaseType>
//            struct Configure<BaseType, false>
//            {
//                typedef typename Component::template Impl<BaseType> type;
//            };
//
//    };
} //

#endif //__CONFIGURATOR_H__
