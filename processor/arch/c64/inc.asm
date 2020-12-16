    lda ($fb),y
    cmp #$ff
    beq label()
    clc
    adc #$01
    sta ($fb),y
label():
