;<16 bit addition>
lxi b, 0010101101011011b
lxi d, 0010111011011110b
mvi a, 0
add c
add e
sta 2001
mvi a, 0
jnc nocarry
mvi a, 1
nocarry: nop
add b
add d
sta 2000
hlt