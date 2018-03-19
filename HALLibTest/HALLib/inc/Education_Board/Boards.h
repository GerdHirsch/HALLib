#ifndef BOARDS_EA_LPC2138_EduBoard_H_
#define BOARDS_EA_LPC2138_EduBoard_H_

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
	struct EA_LPC2138_EduBoard : Generator::SelectorBase<>{};


}

#endif /* BOARDS_EA_LPC2138_EduBoard_H_ */
