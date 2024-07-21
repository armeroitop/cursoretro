APP		:= game
CCFLAGS	:= -Wall -pedantic
CFLAGS	:= $(CCFLAGS)
CC		:= g++
C		:= gcc
MKDIR	:= mkdir -p
SRC		:= src
OBJ		:= obj
LIBS 	:= -lX11


SUBDIRS		:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))

ALLC		:= $(shell find src/ -type f -iname *.c)
ALLCSOBJ	:= $(patsubst %.c,%.o,$(ALLC))

ALLCPP		:= $(shell find src/ -type f -iname *.cpp)
ALLCPPSOBJ	:= $(patsubst %.cpp,%.o,$(ALLCPP))

.PHONY: dir


$(APP) : $(OBJSUBDIRS) $(ALLCPPSOBJ) $(ALLCSOBJ) 
	$(CC) -o $(APP) $(patsubst $(SRC)%,$(OBJ)%,$(ALLCPPSOBJ) $(ALLCSOBJ)) $(LIBS)
%.o : %.cpp
	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)
%.o : %.c
	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)


dir :
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCCP))
	$(info $(ALLC))
	$(info $(ALLCSOBJ))
	$(info $(ALLCPPSOBJ))

$(OBJSUBDIRS) :
	$(MKDIR) $(OBJSUBDIRS)