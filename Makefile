# Makefile for 2HDMC 

# Choose your C++ compiler here (in general g++ on Linux systems):
CC = g++

#Optimisation level, eg: -O3
OPT=-O3
#OR debug level: -g(n=1,2,3)
DEBUG=


GSL_path=/opt/homebrew/Cellar/gsl/2.8





CFLAGS=-I$(GSL_path)/include -Wall $(DEBUG) $(OPT) -Warray-parameter -Wunused-variable
LDFLAGS=-L$(GSL_path)/lib

OBJDIR=lib
LIBDIR=$(OBJDIR)
SOURCES=THDM.cpp SM.cpp DecayTable.cpp Constraints.cpp Util.cpp runTHDM.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=lib2HDMC.a
LDFLAGS+=-L$(LIBDIR) -l2HDMC -lgsl -lgslcblas -lm
#LDFLAGS+=-L$(LIBDIR) -l2HDMC
LIBS=
PROG=CalcPhys CalcGen CalcHiggs CalcHybrid CalcHMSSM CalcMSSM CalcInert CalcLH Demo

# To use HiggsBounds/HiggsSignals for Higgs constraints, put the corresponding libraries
# in the "lib" subdirectory and uncomment the following lines.
# Note that both programs: HiggsBounds (> 4.2.0) and HiggsSignals (> 1.4.0) must be present
#CFLAGS+=-DHiggsBounds
#LDFLAGS+=-L$(LIBDIR) -lHS -lHB -lgfortran
#SOURCES+=HBHS.cpp

VPATH=src

.PHONY: lib clean distclean

all: lib $(PROG)

$(OBJDIR)/%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

lib: $(addprefix $(LIBDIR)/, $(LIB))

$(addprefix $(LIBDIR)/, $(LIB)): $(addprefix $(OBJDIR)/, $(OBJECTS))
	@ echo "Making library $@"
	@ ar rcs $@ $(addprefix $(OBJDIR)/, $(OBJECTS))

%: %.cpp $(addprefix $(LIBDIR)/, $(LIB))
	@ $(CC) $< -Isrc $(CFLAGS) $(LDFLAGS) $(addprefix $(LIBDIR)/, $(LIBS)) -o $@

clean:
	@ echo "Cleaning library"
	@ rm -f $(addprefix $(OBJDIR)/, *.o)
	@ rm -f $(addprefix $(LIBDIR)/, $(LIB))

distclean:
	@ make -s clean
	@ echo "Cleaning programs"
	@ rm -f $(PROG)
