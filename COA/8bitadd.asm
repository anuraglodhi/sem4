;<Add 8 bit numbers>
mvi b, 00010110b ;store 22 in b
mvi c, 00100100b ;store 36 is c
mvi a, 0         ;reset a
add b            ;add b to a
add c            ;add c to a
sta 50           ;store a at 50
hlt