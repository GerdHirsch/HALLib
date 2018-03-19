#ifndef __GENERATOR_XMLPRINTERS_H_
#define __GENERATOR_XMLPRINTERS_H_

#include <Generator/XMLOutput.h>

namespace Generator{ namespace XML {

//=====================================================================
// XMLContext Knoten erzeugen
//=====================================================================
template <class Columns, class Rows>
struct XMLContext;

template <class Columns, class Rows>
struct XMLContext{

	template<class OStream>
	static void print(OStream& os){
		os << "<Context name=\"DD&lt;";
			ContextPrinter<Columns>::print(os);
			os <<", ";
			ContextPrinter<Rows>::print(os);
			os << "&gt;\">" << std::endl;
				XMLColumns<Columns>::print(os);
				XMLRows<Rows>::print(os);
				XMLCells<Columns, Rows>::print(os);
		os << "</Context>" << std::endl;
	}
};

template <class Columns, class T1, class T2>
struct XMLContext<Columns, Loki::Typelist<T1, T2> >{

	typedef Loki::Typelist<T1, T2> Rows;

	template<class OStream>
	static void print(OStream& os){
		os << "<Context name=\"";
			ContextPrinter<Columns>::print(os);
			os << "\">" << std::endl;
				XMLColumns<Columns>::print(os);
				XMLRows<Rows>::print(os);
				XMLCells<Columns, Rows>::print(os);
		os << "</Context>" << std::endl;
	}
};
template <class T1, class T2, class Rows>
struct XMLContext<Loki::Typelist<T1, T2>, Rows>{

	typedef Loki::Typelist<T1, T2> Columns;

	template<class OStream>
	static void print(OStream& os){
		os << "<Context name=\"";
			ContextPrinter<Rows>::print(os);
			os << "\">" << std::endl;
				XMLColumns<Columns>::print(os);
				XMLRows<Rows>::print(os);
				XMLCells<Columns, Rows>::print(os);
		os << "</Context>" << std::endl;
	}
};
//=====================================================================
// XMLAdapters Alle Context Knoten für Adapter erzeugen
//=====================================================================
template<class Context, class Platform>
struct AdapterPrinterCreator{
    template<typename Row, typename BaseType>
    struct apply{
    	typedef PrinterAggregate<
    			XMLContext<CS<Row, Context>, Platform>, BaseType > type;
    };
};
template<class Context, class Components, class Platform>
struct XMLAdapters{
	typedef typename
			ForEachClassIn<Components,
				AdapterPrinterCreator<Context, Platform>,
				PrinterBase
				>
	::type XMLPrinter;

	template<class OStream>
	static void print(OStream& os){
		XMLPrinter::print(os);
	}
};
//=====================================================================
// XMLContexts Knoten erzeugen
//=====================================================================
/*
 * 1. Alle Components für den Context mit den Aggregaten
 *	  ausgeben
 * 2. Alle Adapter für Context/Platform ausgeben
 * 3. Alle Adapter für alle Components/Platform ausgeben
 *
 * Context = Radio::RadioLuxus
 * Components = Loki::Typelist<HMI, Reveicer, ...>
 * Platform = CS<Board, Prozessor>
 */
template<class Context, class Components, class Platform=Context>
struct XMLContexts{
	template<class OStream>
	static void print(OStream& os){
		os <<
		"<?xml-stylesheet type=\"text/xsl\" href=\"HTMLTransformer.xsl\"?>"
		<< std::endl;
		os << "<Contexts>" << std::endl;
		//Komponenten der Anwendung
		XMLContext<Context, Components>::print(os);
		//AdapterLayer für gesamte Anwendung
		XMLContext<Context, Platform>::print(os);
		//Adapter für alle Komponenten
		XMLAdapters<Context, Components, Platform>::print(os);
		os << "</Contexts>" << std::endl;
	}
};
template<class Context, class Components>
struct XMLContexts<Context, Components, Context>{
	template<class OStream>
	static void print(OStream& os){
		os <<
		"<?xml-stylesheet type=\"text/xsl\" href=\"HTMLTransformer.xsl\"?>"
		<< std::endl;
		os << "<Contexts>" << std::endl;
		//Komponenten der Anwendung
		XMLContext<Context, Components>::print(os);
		os << "</Contexts>" << std::endl;
	}
};
//
//template<class Context, class T1, class T2, class Board, class Prozessor>
//struct XMLContexts<Context, Loki::Typelist<T1, T2>, CS<Board, Prozessor> >{
//	typedef Loki::Typelist<T1, T2> Components;
//	typedef CS<Board, Prozessor> Platform;
//
//	template<class OStream>
//	static void print(OStream& os){
//		//<?xml-stylesheet type="text/xsl" href="HTMLTransformer.xsl"?>
//
//		os <<
//		"<?xml-stylesheet type=\"text/xsl\" href=\"HTMLTransformer.xsl\"?>"
//		<< std::endl;
//		os << "<Contexts>" << std::endl;
//		//Komponenten der Anwendung
//		XMLContext<Context, Components>::print(os);
//		//AdapterLayer für gesamte Anwendung
//		XMLContext<Context, Platform>::print(os);
//		//Adapter für alle Komponenten
//		XMLAdapters<Context, Components, Platform>::print(os);
//		os << "</Contexts>" << std::endl;
//	}
//};

//---------------------------------------------------------------------
}} // namespace Generator::XML
#endif /* XMLPRINTERS_H_ */
