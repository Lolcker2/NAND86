# NAND86
A logic gate simulator as an assembly like language


nand86 → c → fed to the Board86 which runs the compiled program.

potentially run the board and compiled c in parallel

syntax
.board seg

define registers
io macros
layout
stack size

.code seg 
includes
…



io macros be a keypress → triggered action

say i have an 8 bit register.
loading it onto the stack should be a macro,
same as loading it from the stack.

then create registers or data buffers / busses whatever name i think of.

regarding i/o
command line interfact + rom / r&w registers

say \set reg 3 100101
\run program



how about different programs for the same environment + savestates for the environment
