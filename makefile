PROGS= bsearch

all: $(PROGS)

%: %.c 
	gcc -g -Wall -pedantic $< -o $@

.PHONY: clean all

clean:
	-rm $(PROGS) *~
