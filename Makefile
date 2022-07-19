include config.mk

SRC := $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ := $(SRC:c=o)

all: ${BIN}

${BIN}: ${OBJ}
	@echo ${SRC}
	${CC} ${CFLAGS} -o $@ ${OBJ}

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $<

install: ${BIN}
	cp ${BIN} ${INSTALL}/bin/${BIN}

.PHONY: clean
clean:
	rm -rf ${BIN} ${OBJ} 
