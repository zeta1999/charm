-include ../../../common.mk
-include ../../../../include/conv-mach-opt.mak
CHARMDIR = ../../../..
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)

all: direct_api

OBJS = direct_api.o

direct_api: $(OBJS)
	$(CHARMC) -language charm++ -o direct_api $(OBJS)

cifiles: direct_api.ci
	$(CHARMC)  direct_api.ci
	touch cifiles

direct_api.o: direct_api.C cifiles
	$(CHARMC) -c direct_api.C

test: all
	$(call run, +p1 ./direct_api 60)
	$(call run, +p4 ./direct_api 100)
ifeq ($(CMK_USE_CMA),1)
	$(call run, +p4 ./direct_api 100 +noCMAForZC)
endif

testp: all
	$(call run, +p$(P) ./direct_api $$(( $(P) * 8)) )
ifeq ($(CMK_USE_CMA),1)
	$(call run, +p$(P) ./direct_api $$(( $(P) * 8)) +noCMAForZC)
endif

smptest: all
	$(call run, +p2 ./direct_api 60 ++ppn 2)
	$(call run, +p4 ./direct_api 100 ++ppn 2)
ifeq ($(CMK_USE_CMA),1)
	$(call run, +p2 ./direct_api 60 +noCMAForZC ++ppn 2)
	$(call run, +p4 ./direct_api 100 +noCMAForZC ++ppn 2)
endif

clean:
	rm -f *.decl.h *.def.h *.o
	rm -f direct_api charmrun cifiles
