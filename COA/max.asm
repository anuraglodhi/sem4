
;<Max>

start: nop
mvi b, 50
mvi c, 40
mov a, b
cmp c
jc sec
sta 50
jmp end
sec: mov a, c
sta 50
end: nop
hlt