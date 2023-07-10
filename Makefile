.PHONY : test lsp native

test:
	clear
	pio test -e native -v

lsp:
	pio run -t compiledb

native:
	pio run -e native -t exec
