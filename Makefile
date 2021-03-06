# vim: noet

BINDIR = bin
SRCDIR = src
INCLUDEDIR = include

DEPS = \
	$(SRCDIR)/array.c \
	$(SRCDIR)/bst.c \
	$(SRCDIR)/list.c \
	$(SRCDIR)/stack.c \
	$(SRCDIR)/queue.c

BUILD = gcc -o $(BINDIR)/$* -I $(INCLUDEDIR) $(DEPS) $(SRCDIR)/$*.c
COMPILE = gcc -o $(TMPDIR)/$*.o -I $(INCLUDEDIR) -c $(SRCDIR)/$*.c

bindir:
	mkdir -p $(BINDIR)

list:
	@grep main -rl src/ | cut -d/ -f3 | cut -d\. -f1

edit-%:
	@vi $(SRCDIR)/$*.c

compile-%:
	$(COMPILE)

build-%: bindir
	$(BUILD)

clean:
	rm -f $(BINDIR)/*
	rmdir $(BINDIR)

run-%: build-%
	./$(BINDIR)/$*

debug-%:
	@$(BUILD) -g && gdb ./$(BINDIR)/$*

watch-%:
	@watch "$(BUILD) && ./$(BINDIR)/$*"
