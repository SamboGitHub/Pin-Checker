#ifndef GLOBAL_H_MARK
#define GLOBAL_H_MARK 1



extern  unsigned char rig_address;
extern  unsigned char my_address;
extern int rotary_encoder_pos;

unsigned int BCDtoDEC(unsigned char const* nybbles, int length);
// void RotateStateChanged();


// unsigned int bcd_decimal(unsigned char hex[1]);


#endif