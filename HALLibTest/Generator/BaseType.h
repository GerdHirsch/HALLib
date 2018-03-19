#ifndef __GENERATOR_BASETYPE_H
#define __GENERATOR_BASETYPE_H

//=====================================================================
namespace Generator{
//=====================================================================
struct EmptyRepository{};
//---------------------------------------------------------
//! Create Erzeugt eine Component für den Context
template<   class Context, 
            class ConfigurationRepository = EmptyRepository,
            class Origin = Context
            >
struct Create;
//---------------------------------------------------------
//! Component, muss für einen Context spezialisiert werden
template<class Context, class Origin, class ConfigurationRepository>
struct Component;
//---------------------------------------------------------
//! SimpleSelector, erzeugt aus zwei beliebigen Typen
//! einen Context, base_type ist SelectorDefault
template<class T1, class T2>
struct SS;
//---------------------------------------------------------
//! CompositeSelector, erzeugt aus einem beliebigen Typ
//! und einem Selector einen Context
template<typename T, typename Selector>
struct CS;
//---------------------------------------------------------
//! DoubleDispatchSelector, erzeugt aus zwei Selectoren
//! einen Context
template<class Selector1, class Selector2>
struct DD;
//---------------------------------------------------------
//! NumberOf Zur Auswahl einer von mehreren Componenten
template<class ComponentType, unsigned int Number>
struct NO
{
	typedef ComponentType type;
	static const unsigned int value = Number;
//	enum { value = Number };
};
//---------------------------------------------------------
//! Selector zur Spezialisierung für Komponenten
//! die allgemein zur Verfügung stehen
//! Default für SelectorBase<...>
struct SelectorDefault;
//---------------------------------------------------------
template<class CurrentContext>
struct BaseType{
	typedef typename CurrentContext::base_type type;
};
/*!  SelectorBase
    Jeder Selector der Create als Context übergeben wird, 
    muss von SelectorBase erben
*/
/*!
    SelectorBase wird für Typ Hierarchien (Selectoren) benötigt
    die die Metainformationen über ihre Basisklassen 
    zur Verfügung stellen müssen. Damit lassen
    sich Component (templates) für die jeweilige 
    Hierarchie Stufe definieren, die an die spezielleren Typen
    vererbt werden
    diese werden vom Compiler ausgewählt 
*/
template <typename BASETYPE=SelectorDefault,
		 template<class> class BaseTypeTemplate=BaseType>
struct SelectorBase
{
    typedef BASETYPE base_type;

    //! BaseType berechnet den nächsten Typ
    //! mit dem ein Context erzeugt wird
    //! für den eine Componente gesucht wird
    template<class CurrentContext>
    struct BaseType : BaseTypeTemplate<CurrentContext>{};

    static char const * name(){ return "Generator::SelectorBase"; }
};
//---------------------------------------------------------
template<class T>
struct name{
	template<class OStream>
	static void print(OStream& os){
		os << T::name();
	}
};
//---------------------------------------------------------
// nur für den Generator 
struct SelectorEnd //: SelectorBase<SelectorNext>
{
	static const char* name(){ return "Generator::SelectorEnd";}
};
 
struct SelectorDefault : SelectorBase<SelectorEnd>{
	static const char* name(){ return "Generator::SelectorDefault";}
};
} // namespace Generator

#endif //__GENERATOR_BASETYPE_H

