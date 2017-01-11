CC=/usr/bin/g++
AR=/usr/bin/ar

CFLAGS = -I./ -I../ -Wall -Werror -g -std=c++11 -D ALL_UT=$(ALL_UT)
LINKOPTS =

OBJ = dslib_ut.bin
LIB = ../bin/Debug/libds.a

all: $(OBJ)

$(OBJ):
	$(CC) $(BIN_ARCH) -o $(OBJ) $(CFLAGS) dslib_ut.cpp $(LIB)

clean:
	@rm -f dslib_ut.bin
	@rm -rf *.dSYM
	@rm -f core.*
