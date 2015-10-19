CC=/usr/bin/gcc
AR=/usr/bin/ar

CFLAGS = -I. -I../ -g -Wall -Werror
LINKOPTS = 

OBJ = dslib_ut.bin
LIB = ../build/libds.a

all: $(OBJ) 

$(OBJ):
	$(CC) $(BIN_ARCH) -o $(OBJ) $(CFLAGS) dslib_ut.c $(LIB) 

clean:
	rm -rf dslib_ut.bin

