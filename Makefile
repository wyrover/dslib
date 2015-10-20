CC=/usr/bin/gcc
AR=/usr/bin/ar

# BIN_ARCH = -m32
BIN_ARCH = 

DSLIB_TOP = .
DSLIB_BLD_DIR = $(DSLIB_TOP)/build

MODULE_NAME = ds
MODULE_OBJ_NAME = libds.a
MODULE_BLD_DIR = $(DSLIB_BLD_DIR)
MODULE_OBJ = $(MODULE_BLD_DIR)/$(MODULE_OBJ_NAME)
MODULE_OBJ_FILES = $(addprefix $(MODULE_BLD_DIR)/, $(patsubst %.c, %.o, $(wildcard *.c )))

CFLAGS = -I./ -Wall -Werror
LINKOPTS = 

all:  $(MODULE_BLD_DIR) $(MODULE_OBJ) testapp


$(MODULE_BLD_DIR):
	@echo $(MODULE_BLD_DIR)
	@mkdir -p $(MODULE_BLD_DIR)

$(MODULE_BLD_DIR)/%.o: %.c $(DEPS)
	$(CC) $(BIN_ARCH) -c -o $@ $< $(CFLAGS) 

$(MODULE_OBJ): $(MODULE_OBJ_FILES)
	$(AR) rcs $(MODULE_BLD_DIR)/$(MODULE_OBJ_NAME) $(MODULE_OBJ_FILES)

testapp:
	cd test; make

clean:
	rm -rf $(MODULE_BLD_DIR)
	cd test; make clean
