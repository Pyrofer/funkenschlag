MCU = atmega8
F_CPU = 8000000
TARGET = funkenschlag
SRC = funkenschlag.c serial.c src_adc.c src_sw.c src_ds.c psx.c datenschlag.c
COMBINE_SRC = 0

include avr-tmpl.mk
