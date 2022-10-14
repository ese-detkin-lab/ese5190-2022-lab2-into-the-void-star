# -------------------------------------------------- #
# This file is autogenerated by pioasm; do not edit! #
# -------------------------------------------------- #

import rp2
from machine import Pin
# ------ #
# ws2812 #
# ------ #

ws2812_T1 = 2
ws2812_T2 = 5
ws2812_T3 = 3

@rp2.asm_pio(sideset_init=pico.PIO.OUT_HIGH, out_init=pico.PIO.OUT_HIGH, out_shiftdir=1)
def ws2812():
    wrap_target()
    label("0")
    out(x, 1)               .side(0) [2]  # 0
    jmp(not_x, "3")         .side(1) [1]  # 1
    jmp("0")                .side(1) [4]  # 2
    label("3")
    nop()                   .side(0) [4]  # 3
    wrap()



# --------------- #
# ws2812_parallel #
# --------------- #

ws2812_parallel_T1 = 2
ws2812_parallel_T2 = 5
ws2812_parallel_T3 = 3

@rp2.asm_pio()
def ws2812_parallel():
    wrap_target()
    out(x, 32)                            # 0
    mov(pins, invert(null))          [1]  # 1
    mov(pins, x)                     [4]  # 2
    mov(pins, null)                  [1]  # 3
    wrap()



