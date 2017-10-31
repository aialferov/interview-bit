# vim: noet

DEPS = array.c bst.c list.c
BUILD = gcc -o $* $(DEPS) $*.c

build-%:
	@$(BUILD)

run-%: build-%
	@./$*

debug-%:
	@watch "$(BUILD) && ./$*"
