#ifndef BOARDS_ZEA7_2_H_
#define BOARDS_ZEA7_2_H_

#include <Generator/BaseType.h>

/*
    these Types here do only define Types to
    select specific templates
*/
namespace Boards
{
    /*
    Todo: eventuell für jede Board/Controller Kombination
     einen Selector zur Verfügung stellen
     struct ZEA7_2_LPC214x : Generator::SelectorBase<>{};
     Alternativ: doubleDispatch implementieren oder
     wie aktuell (ugly) den ControllerType im ConfigRep mit
     übergeben
     */
	struct ZEA7_2 : Generator::SelectorBase<>{};
	struct ZEA7_2_LPC214x : Generator::SelectorBase<>{};
	struct ZEA7_2_LPC213x : Generator::SelectorBase<>{};
}


#endif /* BOARDS_ZEA7_2_H_ */
