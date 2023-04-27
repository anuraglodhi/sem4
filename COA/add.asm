
;<Addition>

jmp start

;data
ab: db 50
cd: db 60

;code
start: nop
lda ab
mov b, a
lda cd
add b
sta 2000

hlt