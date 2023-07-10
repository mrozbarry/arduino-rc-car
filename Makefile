.PHONY : test lsp native

test:
	clear
	pio test -e native -vvv

lsp:
	pio run -t compiledb

native:
	pio run -e native -t exec
