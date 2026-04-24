CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/Angajat.cpp src/Medic.cpp src/Asistent.cpp \
      src/Pacient.cpp src/Programare.cpp src/Factura.cpp \
      src/FacturaFactory.cpp src/Logger.cpp src/Spital.cpp \
      src/main.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o spital

clean:
	del spital.exe