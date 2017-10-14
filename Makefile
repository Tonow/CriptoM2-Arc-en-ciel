# ajoutez vos programmes ci-dessous
PROGS_SRC=arc-en-ciel.cxx ArcEnCiel.cxx Contexte.cxx Cracker.cxx

SRC=utils.cxx
OBJ=${SRC:.cxx=.o}
HEADERS=utils.h ArcEnCiel.h Contexte.h Cracker.h
PROGS=${PROGS_SRC:.cxx=}
CXXFLAGS=-O3 -g -Wall

all: ${PROGS}

arc-en-ciel: arc-en-ciel.cxx ${OBJ} ${HEADERS}
	g++ ${CXXFLAGS} $< ${OBJ} -o -lssl $@

%.o: %.cxx %.h
	g++ ${CXXFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
