.PHONY : test lsp make\:test

test:
	clear
	pio test -e native

lsp:
	pio run -t compiledb

make\:test:
	cp -R ./templates/test ./test/test_$(NAME)
	mv ./test/test_$(NAME)/test_test.cpp ./test/test_$(NAME)/test_$(NAME).cpp
