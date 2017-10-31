# vim: noet

BINDIR = bin
SRCDIR = src
INCLUDEDIR = include

DEPS = $(SRCDIR)/array.c $(SRCDIR)/bst.c $(SRCDIR)/list.c
BUILD = gcc -o $(BINDIR)/$* -I $(INCLUDEDIR) $(DEPS) $(SRCDIR)/$*.c

bindir:
	mkdir -p $(BINDIR)

build-%: bindir
	$(BUILD)

clean:
	rm -f $(BINDIR)/*
	rmdir $(BINDIR)

run-%: build-%
	./$(BINDIR)/$*

debug-%:
	@watch "$(BUILD) && ./$(BINDIR)/$*"
