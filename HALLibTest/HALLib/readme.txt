todo:

Namen der Register kleine Schreiben, nur MACROS in Gro�buchstaben
alle XYZRegister aus HAL/ComponentTypes.h entfernen Adresse: SS<PinConnectBlock, Register>
MockRegister in einzelne Header auslagern, jeder Test hat seine eigenen Header
PinConnectBlock problem mit PCBTestRegistern.h


Methoden in MemoryMappedRegister �berarbeiten: read/write set/get 

VIC::FIQ funktioniert nicht, Software interrupts Demo f�r interrupts IRQ, FIQ, software

generelle L�sung f�r Macros f�r __irq f�r die verschiedenen Compiler finden

TimerCalibration mit Generator erzeugen, Pins als Parameter �bergeben, 
	so dass die Anwendung entscheiden kann, an welchem GPIOPin "geblinkt" 
	oder nicht werden soll.
	backToDefaults: gew�hrleisten dass voreinstellungen wieder hergestellt werden.
	siehe unten: Memento

PLL als eigenen Typ der deviceNo f�r VIC definiert

ADSourceInfo mit Methoden versehen 

operator OR(|) f�r bit templates �berladen??

Timer: setMatch nach matchOn(value) umbenennen
	startTimer nach start() umbenennen
Timer: TIMERESOLUTION hinzuf�gen, damit kann 
	Timer::Match<n>::setDelay(TIMERESOSLUTION/SECDIVUNITS)
	als ticks/sec berechnet werden.
	
RTC Problem weiter analysieren 
RTCDiagnostic: Projekt zur Ausgabe aller RTC Einstellungen, 
	Alarme, aktuelle Zeit, interrupts, 
	
PinConnectBlock::PinSel_2 read, modify, write in asm in spezielem RMWMemoryMappedRegister
abbilden

HAL Implementierungen in den Generatoren zusammenfassen: siehe LPC213x HAL.h	

MementoPattern f�r bestimmte Devices umsetzen? 
	speichert die Einstellungen, so dass sie nach einer 
	�nderung wieder zur�ckgesetzt werden k�nnen.
	zB f�r
	Slot::Memento memento = Slot::memento();
	//zur�cksetzen
	Slot::memento(memento);
	
	PCBPin::Memento memento = PCBPin::memento();
	RTC::Memento memento = RTC::memento();
	
	
