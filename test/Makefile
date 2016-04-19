CC=/usr/bin/g++
AR=/usr/bin/ar

CFLAGS = -I. -I../ -g -Wall -Werror
LINKOPTS = 

OBJ = dslib_ut.bin
LIB = ../build/libds.a

all: $(OBJ) 

$(OBJ):
	$(CC) $(BIN_ARCH) -o $(OBJ) $(CFLAGS) dslib_ut.cpp $(LIB) 

clean:
	@rm -f dslib_ut.bin
	@rm -rf *.dSYM
	@rm -f core.*
