APP	:= game
CCFLAGS	:= -Wall -pedantic
CFLAGS	:= $(CCFLAGS)
CC		:= g++
C		:= gcc
MKDIR	:= mkdir -p
SRC		:= src
OBJ		:= obj


SUBDIRS		:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLC		:= $(shell find src/ -type f -iname *.c)
ALLCSOBJ	:= $(patsubst %.c,%.o,$(ALLC))
ALLCCP		:= $(shell find src/ -type f -iname *.cpp)
ALLCPPSOBJ	:= $(patsubst %.cpp,%.o,$(ALLCPP))

.PHONY: dir


$(APP) : $(OBJSUBDIRS) $(ALLCSOBJ) $(ALLCPPSOBJ)

%.o : %.c
	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

%.o : %.cpp
	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

dir :
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCCP))
	$(info $(ALLC))
	$(info $(ALLCSOBJ))
	$(info $(ALLCPPSOBJ))

$(OBJSUBDIRS) :
	$(MKDIR) $(OBJSUBDIRS)