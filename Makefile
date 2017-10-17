# ajoutez vos programmes ci-dessous
PROGS_SRC=arc-en-ciel.cxx

SRC=utils.cxx
OBJ=${SRC:.cxx=.o}
HEADERS=utils.h ArcEnCiel.h Contexte.h Cracker.h
PROGS=${PROGS_SRC:.cxx=}
CXXFLAGS=-O3 -g -Wall
#env CFLAGS= /usr/include/openssl

all: ${PROGS}

arc-en-ciel: arc-en-ciel.cxx ${OBJ} ${HEADERS}
	g++ ${CXXFLAGS} $< ${OBJ} -lssl -std=c++11 -lcrypto -o $@

# ArcEnCiel: ArcEnCiel.cxx ${OBJ} ${HEADERS}
# 	g++ ${CXXFLAGS} $< ${OBJ} -lssl -std=c++11 -lcrypto -o $@
#
# Contexte: Contexte.cxx ${OBJ} ${HEADERS}
# 	g++ ${CXXFLAGS} $< ${OBJ} -lssl -std=c++11 -lcrypto -o $@
#
# Cracker: Cracker.cxx ${OBJ} ${HEADERS}
# 	g++ ${CXXFLAGS} $< ${OBJ} -lssl -std=c++11 -lcrypto -o $@

%.o: %.cxx %.h
	g++ ${CXXFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
