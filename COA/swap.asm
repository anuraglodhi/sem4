;<Swap>
lda 50      ;load operand at location 50
mov b, a    ;mov operand from a to b
lda 51      ;load operand from 51
sta 50      ;store at 50 i.e. 51 -> a -> 50
mov a, b    ;move operand from b to a
sta 51      ;store at 51 i.e. 50 -> a -> b -> a -> 51
hlt