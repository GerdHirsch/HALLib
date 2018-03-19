#ifndef __GENERATOR_XML_XMLOUTPUT_H_
#define __GENERATOR_XML_XMLOUTPUT_H_

#include <iostream>
#include <Generator/CreateComponent.h>


namespace Generator{ namespace XML {
//=====================================================================
// ContextPrinter
//=====================================================================
template<class Selector>
struct ContextPrinter{
	template<class OStream>
	static void print(OStream& os){
		name<Selector>::print(os);
//		os << Selector::name();
	}
};

template<class Component, unsigned int Number>
struct ContextPrinter<NO<Component, Number> >{
	template<class OStream>
	static void print(OStream& os){
		os << "NO &lt; ";
		ContextPrinter<Component>::print(os);
		os << ", " << Number << " &gt;";
	}
};
template<class T1, class T2>
struct ContextPrinter<SS<T1, T2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "SS&lt; ";
		 ContextPrinter<T1>::print(os);
		 os << ", ";
		 ContextPrinter<T2>::print(os);
		os << " &gt;";
	}
};
template<class S1, class S2>
struct ContextPrinter<DD<S1, S2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "DD&lt; ";
		 ContextPrinter<S1>::print(os);
		 os << ", ";
		 ContextPrinter<S2>::print(os);
		os << " &gt;";
	}
};
template<class T, class S>
struct ContextPrinter<CS<T, S> >{
	template<class OStream>
	static void print(OStream& os){
		os << "CS&lt; ";
		 ContextPrinter<T>::print(os);
		 os << ", ";
		 ContextPrinter<S>::print(os);
		 os << " &gt;";
	}
};
//=====================================================================
// Printer für die Create...Printer
//=====================================================================
struct PrinterBase{
	template<class OStream>
	static void print(OStream& os){}
};
//---------------------------------------------------------------------
template<class Printer, class BaseType>
struct PrinterAggregate //: BaseType
{
	template<class OStream>
	static void print(OStream& os){
		Printer::print(os);
		BaseType::print(os);
	}
};
//=====================================================================
// XMLRow Knoten erzeugen
//=====================================================================
template <class Row>
struct XMLRow{
	template<class OStream>
	static void print(OStream& os){
	   os << "<Row name=\"";
	   ContextPrinter<Row>::print(os);
	   os << "\"/>" << std::endl;
	}
};
//---------------------------------------------------------------------
// Ausgabe unterdrücken
template <>
struct XMLRow<SelectorEnd>{
	template<class OStream>
	static void print(OStream& os){}
};
template <class T>
struct XMLRow<CS<T, SelectorEnd> >{
	template<class OStream>
	static void print(OStream& os){}
};
//=====================================================================
// XMLRows Knoten erzeugen
//=====================================================================
template<class Context, class Origin=Context, int num=0>
struct XMLRowFromBaseType{

    typedef XMLRowFromBaseType<typename Origin::template BaseType<Context>::type, Origin, num+1> BaseType;
    template<class OStream>
    static void print(OStream& os){
    	XMLRow<Context>::print(os);
    	BaseType::print(os);
    }
};
//-----------------------------
template<class Origin, int num>
struct XMLRowFromBaseType<SelectorEnd, Origin, num>{
	template<class OStream>
	static void print(OStream& os){	}
};
//---------------------------------------------------------------------
template<class Rows>
struct XMLRows{
	template<class OStream>
	static void print(OStream& os){
		   os << "<Rows>" << std::endl;
		   XMLRowFromBaseType<Rows>::print(os);
		   os << "</Rows>" << std::endl;
	}
};
//---------------------------------------------------------------------
struct RowPrinterCreator{
    template<typename Row, typename BaseType>
    struct apply{
    	typedef PrinterAggregate<
    			XMLRow<Row>, BaseType > type;
    };
};

template<class T1, class T2>
struct XMLRows<Loki::Typelist<T1, T2> >{
	typedef Loki::Typelist<T1, T2> Rows;

	typedef typename
			ForEachClassIn<
				Rows,
				RowPrinterCreator,
				PrinterBase
						  >
	::type XMLPrinter;

	template<class OStream>
	static void print(OStream& os){
		   os << "<Rows>" << std::endl;
		   os << "<Row name=\"Aggregate\"/>" << std::endl;
		   XMLPrinter::print(os);
		   os << "</Rows>" << std::endl;
	}
};
//=====================================================================
// XMLColumn Knoten
//=====================================================================
template <class Column>
struct XMLColumn{
	template<class OStream>
	static void print(OStream& os){
		   os << "<Column name=\"";
		   ContextPrinter<Column>::print(os);
		   os << "\"/>" << std::endl;
	}
};
template <>
struct XMLColumn<SelectorEnd>{
	template<class OStream>
	static void print(OStream& os){}
};
template <class T>
struct XMLColumn<CS<T, SelectorEnd> >{
	template<class OStream>
	static void print(OStream& os){}
};
//=====================================================================
// XMLColumns Knoten aus Selector erzeugen
//=====================================================================
template<class Context, class Origin=Context, int num=0>
struct XMLColumnFromBaseType{

    typedef XMLColumnFromBaseType<typename Origin::template BaseType<Context>::type, Origin, num+1> base;
    template<class OStream>
    static void print(OStream& os){
    	XMLColumn<Context>::print(os);
        base::print(os);
    }
};
//-----------------------------
template<class Origin, int num>
struct XMLColumnFromBaseType<SelectorEnd, Origin, num>{
	template<class OStream>
	static void print(OStream& os){}
};
//---------------------------------------------------------------------
template<class Context>
struct XMLColumns{
	template<class OStream>
	static void print(OStream& os){
		   os << "<Columns>" << std::endl;
		   XMLColumnFromBaseType<Context>::print(os);
		   os << "</Columns>" << std::endl;
	}
};
//=====================================================================
// XMLColumns Knoten aus Loki::Typelist erzeugen
//=====================================================================
struct ColumnPrinterCreator{
    template<typename Column, typename BaseType>
    struct apply{
    	typedef PrinterAggregate<
    			XMLColumn<Column>, BaseType > type;
    };
};
template<class T1, class T2>
struct XMLColumns<Loki::Typelist<T1, T2> >{
	typedef Loki::Typelist<T1, T2> Columns;

	typedef typename
			ForEachClassIn<
				Columns,
				ColumnPrinterCreator,
				PrinterBase
						  >
		::type XMLPrinter;

	template<class OStream>
	static void print(OStream& os){
		   os << "<Columns>" << std::endl;
		   os << "<Column name=\"Aggregate\"/>" << std::endl;
		   XMLPrinter::print(os);
		   os << "</Columns>" << std::endl;
	}
};
//=====================================================================
// XMLCell Knoten erzeugen
//=====================================================================
// column = 1: column/row column = 2: row/column
template<class Context, int column = 1>
//template<class Context>
struct XMLCell;

template<class Context>
struct XMLCell<Context, 1>{
//struct XMLCell{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell column=\"";
		ContextPrinter<Context>::print(os);
		os << "\" row=\"Aggregate\" content=\"";
		ContextPrinter<Context>::print(os);
		os << "\"/>" << std::endl;
	}
};
template<class Context>
struct XMLCell<Context, 2>{
//struct XMLCell{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell row=\"";
		ContextPrinter<Context>::print(os);
		os << "\" column=\"Aggregate\" content=\"";
		ContextPrinter<Context>::print(os);
		os << "\"/>" << std::endl;
	}
};
//---------------------------------------------------------------------
template<unsigned int column>
//template<>
struct XMLCell<SelectorEnd, column>{
//struct XMLCell<SelectorEnd>{
	template<class OStream>
	static void print(OStream& os){} // keine Ausgabe in die Tabelle
};
//---------------------------------------------------------------------
template<class T, class Selector>
struct XMLCell<CS<T, Selector>, 1>{
//struct XMLCell<CS<T, Selector> >{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell column=\"";
		ContextPrinter<Selector>::print(os);
		os << "\" row=\"";
		ContextPrinter<T>::print(os);
		os << "\" content=\"CS&lt;Row, Col&gt;\" />" << std::endl;
	}
};
template<class T, class Selector>
struct XMLCell<CS<T, Selector>, 2>{
//struct XMLCell<CS<T, Selector> >{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell row=\"";
		ContextPrinter<Selector>::print(os);
		os << "\" column=\"";
		ContextPrinter<T>::print(os);
		os << "\" content=\"CS&lt;Col, Row&gt;\" />" << std::endl;
	}
};
//---------------------------------------------------------------------
template<class Selector1, class Selector2>
struct XMLCell<DD<Selector1, Selector2>, 1>{
//struct XMLCell<DD<Selector1, Selector2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell column=\"";
		ContextPrinter<Selector1>::print(os);
		os << "\" row=\"";
		ContextPrinter<Selector2>::print(os);
		os << "\" content=\"DD&lt;Col, Row&gt;\"/>";
	}
};
template<class Selector1, class Selector2>
struct XMLCell<DD<Selector1, Selector2>, 2>{
//struct XMLCell<DD<Selector1, Selector2> >{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cell row=\"";
		ContextPrinter<Selector1>::print(os);
		os << "\" column=\"";
		ContextPrinter<Selector2>::print(os);
		os << "\" content=\"DD&lt;Row, Col&gt;\"/>";
	}
};
//---------------------------------------------------------------------
template<class Context, int column=1, class Origin=Context>
struct XMLAllCells;

template<class Context, int column, class Origin>
struct XMLAllCells
{
	typedef SelectComponent<Component<Context, Origin, EmptyRepository> > component_selector;

	typedef typename component_selector::origin_context origin;
	typedef typename component_selector::current_context selector;

	// selector wird zu SelectorEnd wenn es keine generelleren Components
	// als die Spezialisierung für Component<SelectorEnd, ..> gibt
	// ImplType ist Component_NotSupportedFor<Origin>
	typedef typename getBaseType<selector, origin>::type base_type;
	typedef XMLAllCells<base_type, column, Origin> BaseType;

	template<class OStream>
	static void print(OStream& os){
		XMLCell<selector, column>::print(os);
		BaseType::print(os);
	}
};
//---------------------------------------------------------------------
template<class Origin, int columns>
struct XMLAllCells<SelectorEnd, columns, Origin>{
	template<class OStream>
	static void print(OStream& os){}
};
//---------------------------------------------------------------------
template<class Context, int columns=1>
struct CellsPrinterCreator{
    template<typename ComponentType, typename BaseType>
    struct apply{
    	typedef PrinterAggregate<
    			XMLAllCells<CS<ComponentType, Context>, columns>, BaseType > type;
    };
};
//---------------------------------------------------------------------
template<class Context, class Platform>
struct XMLCells{
	template<class OStream>
	static void print(OStream& os){
		os << "<Cells>" << std::endl;
		XMLAllCells<DD<Context, Platform> >::print(os);
		os << std::endl << "</Cells>" << std::endl;
	}
};
//---------------------------------------------------------------------
template<class Context, class T1, class T2>
struct XMLCells<Context, Loki::Typelist<T1, T2> >{
	typedef Loki::Typelist<T1, T2> Components;

	typedef typename
		ForEachClassIn<
			Components,
			CellsPrinterCreator<Context>,
			XML::PrinterBase
					  >
	::type XMLPrinter;

	template<class OStream>
	static void print(OStream& os){
		os << "<Cells>" << std::endl;
		// Einträge für Aggregate erzeugen
		XMLAllCells<Context>::print(os);
		// Einträge für die Komponenten erzeugen
		XMLPrinter::print(os);
		os << "</Cells>" << std::endl;
	}
};
//---------------------------------------------------------------------
template<class T1, class T2, class Rows>
struct XMLCells<Loki::Typelist<T1, T2>, Rows>{
	typedef Loki::Typelist<T1, T2> Components;

	typedef typename
		ForEachClassIn<
			Components,
			CellsPrinterCreator<Rows, 2>,
			XML::PrinterBase
					  >
	::type XMLPrinter;

	template<class OStream>
	static void print(OStream& os){
		os << "<Cells>" << std::endl;
		// Einträge für Aggregate erzeugen
		XMLAllCells<Rows, 2>::print(os);
		// Einträge für die Komponenten erzeugen
		XMLPrinter::print(os);
		os << "</Cells>" << std::endl;
	}
};

}} // namespace Generator::XML
#endif /* __GENERATOR_XML_XMLOUTPUT_H_ */
