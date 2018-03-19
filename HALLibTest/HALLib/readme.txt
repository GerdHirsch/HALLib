todo:

Namen der Register kleine Schreiben, nur MACROS in Großbuchstaben
alle XYZRegister aus HAL/ComponentTypes.h entfernen Adresse: SS<PinConnectBlock, Register>
MockRegister in einzelne Header auslagern, jeder Test hat seine eigenen Header
PinConnectBlock problem mit PCBTestRegistern.h


Methoden in MemoryMappedRegister überarbeiten: read/write set/get 

VIC::FIQ funktioniert nicht, Software interrupts Demo für interrupts IRQ, FIQ, software

generelle Lösung für Macros für __irq für die verschiedenen Compiler finden

TimerCalibration mit Generator erzeugen, Pins als Parameter übergeben, 
	so dass die Anwendung entscheiden kann, an welchem GPIOPin "geblinkt" 
	oder nicht werden soll.
	backToDefaults: gewährleisten dass voreinstellungen wieder hergestellt werden.
	siehe unten: Memento

PLL als eigenen Typ der deviceNo für VIC definiert

ADSourceInfo mit Methoden versehen 

operator OR(|) für bit templates überladen??

Timer: setMatch nach matchOn(value) umbenennen
	startTimer nach start() umbenennen
Timer: TIMERESOLUTION hinzufügen, damit kann 
	Timer::Match<n>::setDelay(TIMERESOSLUTION/SECDIVUNITS)
	als ticks/sec berechnet werden.
	
RTC Problem weiter analysieren 
RTCDiagnostic: Projekt zur Ausgabe aller RTC Einstellungen, 
	Alarme, aktuelle Zeit, interrupts, 
	
PinConnectBlock::PinSel_2 read, modify, write in asm in spezielem RMWMemoryMappedRegister
abbilden

HAL Implementierungen in den Generatoren zusammenfassen: siehe LPC213x HAL.h	

MementoPattern für bestimmte Devices umsetzen? 
	speichert die Einstellungen, so dass sie nach einer 
	Änderung wieder zurückgesetzt werden können.
	zB für
	Slot::Memento memento = Slot::memento();
	//zurücksetzen
	Slot::memento(memento);
	
	PCBPin::Memento memento = PCBPin::memento();
	RTC::Memento memento = RTC::memento();
	
	
