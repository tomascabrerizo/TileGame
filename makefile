#DEFINES macros
EXECUTABLE_NAME = game.exe
DIR_SRC = .\src
DIR_BIN = .\bin
DIR_VENDOR = .\vendor
DIR_BIN_INT = .\bin-int

SRC_FILES = \
	$(DIR_SRC)\*.cpp 

INCLUDE_FILES = \
	$(DIR_VENDOR)\SDL2\include

LIB_FILES = \
	$(DIR_VENDOR)\SDL2\lib\x86\SDL2.lib \
	$(DIR_VENDOR)\SDL2\lib\x86\SDL2main.lib

#Compiler CONFIG

$(EXECUTABLE_NAME):
	cl /EHsc /Fe$(DIR_BIN)\$(EXECUTABLE_NAME) \
		/I$(INCLUDE_FILES) $(SRC_FILES) $(LIB_FILES) \
		/link /SUBSYSTEM:CONSOLE 

	copy *obj $(DIR_BIN_INT)
	del *obj

