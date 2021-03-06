# ajoutez vos programmes ci-dessous
PROGS_SRC=arc-en-ciel.cxx craquer.cxx

SRC=utils.cxx ArcEnCiel.cxx Cracker.cxx Contexte.cxx
OBJ=${SRC:.cxx=.o}
HEADERS=utils.h Contexte.h ArcEnCiel.h Cracker.h 
PROGS=${PROGS_SRC:.cxx=}
CXXFLAGS=-O1 -g -Wall -std=c++11
#env CFLAGS= /usr/include/openssl

all: ${PROGS}

arc-en-ciel: arc-en-ciel.cxx ${OBJ} ${HEADERS}
	g++ ${CXXFLAGS} $< ${OBJ} -lssl -lcrypto -o $@

craquer: craquer.cxx ${OBJ} ${HEADERS}
	g++ ${CXXFLAGS} $< ${OBJ} -lssl -lcrypto -o $@


%.o: %.cxx %.h
	g++ ${CXXFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
