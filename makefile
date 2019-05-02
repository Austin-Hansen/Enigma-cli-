CXXFLAGS += --std=c++17
FSFLAGS = -lstdc++fs
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: enigma

enigma: main.o rotor.o machine.o reflector.o enigma.o view.o dialogs.o *.h
	${CXX} ${CXXFLAGS} -o enigma main.o rotor.o machine.o reflector.o enigma.o view.o dialogs.o $(GTKFLAGS)
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp $(GTKFLAGS)
rotor.o: rotor.cpp *.h
	${CXX} ${CXXFLAGS} -c rotor.cpp $(GTKFLAGS)
machine.o: machine.cpp *.h
	${CXX} ${CXXFLAGS} -c machine.cpp $(GTKFLAGS)
reflector.o: reflector.cpp *.h
	${CXX} ${CXXFLAGS} -c reflector.cpp $(GTKFLAGS)
enigma.o: enigma.cpp *.h
	${CXX} ${CXXFLAGS} -c enigma.cpp $(GTKFLAGS)
view.o: view.cpp *.h
	${CXX} ${CXXFLAGS} -c view.cpp $(GTKFLAGS)
dialogs.o: dialogs.cpp *.h
	${CXX} ${CXXFLAGS} -c dialogs.cpp $(GTKFLAGS)
