DIRS = \
  pingpong \
  queueperf \
  xcastredn \
  migrate \
  taskSpawn \
  taskSpawnRecursive \
  kNeighbor \
  zerocopy \

#streamingAllToAll benchmark must be rewritten with the [aggregate] API before it can be added back
TESTDIRS = $(DIRS)

NONSCALEDIRS = \
  pingpong \
  queueperf \
  migrate \

TESTPDIRS = $(filter-out $(NONSCALEDIRS),$(TESTDIRS))

all: $(foreach i,$(DIRS),build-$i)

test: $(foreach i,$(TESTDIRS),test-$i)

testp: $(foreach i,$(TESTPDIRS),testp-$i)

clean: $(foreach i,$(DIRS),clean-$i)
	rm -f TAGS #*#
	rm -f core *~

$(foreach i,$(DIRS),build-$i):
	$(MAKE) -C $(subst build-,,$@) all OPTS='$(OPTS)'

$(foreach i,$(DIRS),test-$i):
	$(MAKE) -C $(subst test-,,$@) test OPTS='$(OPTS)' TESTOPTS='$(TESTOPTS)'

$(foreach i,$(TESTPDIRS),testp-$i):
	$(MAKE) -C $(subst testp-,,$@) testp OPTS='$(OPTS)' TESTOPTS='$(TESTOPTS)' P='$(P)'

$(foreach i,$(DIRS),clean-$i):
	$(MAKE) -C $(subst clean-,,$@) clean OPTS='$(OPTS)'
