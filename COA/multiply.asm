
;<Multiply>

jmp start

;data
ab: db 12
cd: db 6

;code
start: nop
lda ab
mov b, a
lda cd
mov c, a
mvi a, 0

loop1: nop
add b
dcr c
jnz loop1

sta 2000

hlt