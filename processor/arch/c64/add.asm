    lda ($fb),y
    clc
    adc #value()
    bcc label()
    lda #$ff 
label():
    sta ($fb),y
