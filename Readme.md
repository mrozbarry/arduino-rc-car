# Arduino RC racecar

## Helper cli commands

 - `make test` runs the native tests
 - `make lsp` builds language server files

## Notes

 - [Bluepad32](https://github.com/ricardoquesada/bluepad32-arduino)
 - [Motor driver spec sheet](https://www.sparkfun.com/datasheets/Robotics/L298_H_Bridge.pdf)
 - For clangd/c++ language servers, run `pio run -t compiledb` or `make lsp`, probably only new files/changes to platform.ini
 - Mosfet needed for each motor
   - How do the pins work?
 - Can we pulse the motors or do we need some other mechanism for controlling speed?

## Contributors

 - Alex
 - Daniel B
 - Justin S
 - Ruta
 - Caleb
