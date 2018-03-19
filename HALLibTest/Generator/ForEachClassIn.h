#ifndef FOREACH_CLASS_IN_H
#define FOREACH_CLASS_IN_H

#include <Loki/NullType.h>
#include <Loki/EmptyType.h>
#include <Loki/Typelist.h>

template<class T, class Base> class DefaultUnit
{
    typedef T type;
};

template
    <
        class TList,
        class Handler,
        class Root = Loki::EmptyType
    >
    struct ForEachClassIn;

    //=================================================================
    template
    <
        class T1,
        class T2,
        class Handler,
        class Root
    >
    struct ForEachClassIn<Loki::Typelist<T1, T2>, Handler, Root>
    {
            typedef typename ForEachClassIn<T2, Handler, Root>::type BaseType;
            typedef typename Handler::template apply<T1, BaseType>::type type;
    };

    //=================================================================
    template
    <
        class T,
        class Handler,
        class Root
    >
    struct ForEachClassIn< Loki::Typelist<T, Loki::NullType>, Handler, Root>
    {
        typedef Root BaseType;
        typedef typename Handler::template apply<T, BaseType>::type type;
    };

// TemplateFunctor der ForEachClassIn<List, TemplateFunctor<Handler> >
// übergeben werden kann
template<typename SystemTraits,
        template<typename TYPE, typename BASE, typename SYSTEMTRAITS> class Creator>
struct TemplateFunctor{

    template<typename Type, typename Base>
    struct apply{
        typedef typename Creator<Type, Base, SystemTraits>::type type;
    };
};

#endif //FOREACH_CLASS_IN_H
