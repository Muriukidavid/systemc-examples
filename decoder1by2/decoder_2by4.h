
#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include "decoder_1by2.h"

SC_MODULE(decoder2){
    
    sc_in<bool>w, x, y, z;
    sc_out<bool>o, p, q, r;

    SC_CTOR(decoder2){
        SC_METHOD(decode2)
        sensitive<<w<<x<<y<<z;
    }

~decoder2(){
//delete stuff :P
}    
void(decode2)(void){
    o = ( w==1 && z==1 )?1:0;
    p = ( w==1 && y==1 )?1:0;
    q = ( z==1 && x==1 )?1:0;
    r = ( y==1 && x==1 )?1:0;
}

};


#endif /* DECODER_2BY4_H_ */

