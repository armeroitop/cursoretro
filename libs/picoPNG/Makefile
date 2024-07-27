
##########################################
#### MACROS
##########################################

# $(1) : Compilador
# $(2) : Objeto file a generar
# $(3) : Codigo fuente
# $(4) : Dependencias adicionales
# $(5) : Flags del compilador
define COMPILA
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

# $(1) : Codigo fuente a cambiar a .o
define CTO
$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(1)))
endef
#$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))

# $(1) : Codigo fuente a cambiar a .o
define CTH
$(patsubst %.c,%.hpp,$(patsubst %.cpp,%.hpp,$(1)))
endef

##########################################
#### CONFIG
##########################################

APP		:= libpicopng.a
CCFLAGS	:= -Wall -pedantic -std=c++14
CFLAGS	:= $(CCFLAGS)
CC		:= g++
C		:= gcc
AR		:= ar
ARFLAGS	:= -crs
RANLIB	:= ranlib
MKDIR	:= mkdir -p
SRC		:= src
OBJ		:= obj


ifdef DEBUG
	CCFLAGS += -g
else
	CCFLAGS += -O3
endif

SUBDIRS		:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))

ALLC		:= $(shell find src/ -type f -iname *.c)
#ALLCSOBJ	:= $(patsubst %.c,%.o,$(ALLC))
#ALLCSOBJ	:= $(foreach F,$(ALLC),$(call CTO,$(F)))

ALLCPP		:= $(shell find src/ -type f -iname *.cpp)
#ALLCPPSOBJ	:= $(patsubst %.cpp,%.o,$(ALLCPP))
#ALLCPPSOBJ	:= $(foreach F,$(ALLCPP),$(call CTO,$(F)))

ALLOBJ		:= $(foreach F,$(ALLC) $(ALLCPP),$(call CTO,$(F)))

.PHONY: info clean cleanall


#Genera la libreria
$(APP) : $(OBJSUBDIRS) $(ALLOBJ) 
	$(AR) $(ARFLAGS) $(APP) $(ALLOBJ)
	$(RANLIB) $(APP)

#Genera las reglas para los objetos
$(foreach F,$(ALLCPP),$(eval $(call COMPILA,$(CC),$(call CTO,$(F)),$(F),$(call CTH,$(F)),$(CCFLAGS)))) 

$(foreach F,$(ALLC),$(eval $(call COMPILA,$(C),$(call CTO,$(F)),$(F),$(call CTH,$(F)),$(CFLAGS)))) 

#$(OBJ)/%.o : $(SRC)/%.cpp
#	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)
#$(OBJ)/%.o : $(SRC)/%.c
#	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

$(OBJSUBDIRS) :
	$(MKDIR) $(OBJSUBDIRS)

info :
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPP))
	$(info $(ALLC))
	$(info $(ALLOBJ))

clean:
	rm -f /obj/*.o

cleanall:
	rm -rf "./obj"
