BasicUpstart2(start)
*=$4000 "Program"
// $00FB - pointer to tape page
start:
    jsr $ff81
    lda #$02
    sta $d020
    sta $d021
    lda #$01
    sta $0286

    lda #$73
    sta $00FB + 1
    lda #$00
    sta $00FB // memory at is like $00FB to …00 73… so we have a pointer to $7300
    ldy #$ff // initialize tape index to 255
