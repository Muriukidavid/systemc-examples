
/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#ifndef DECOCER_2BY4_H_
#define DECOCER_2BY4_H_

#include "../decoder1by2/decoder_1by2.h"
#include "ANDGATE.h"
#include<systemc.h>

SC_MODULE(decoder2by4){
    sc_in<bool> dec_m, dec_n;
    sc_out<bool> dec_o, dec_p, dec_r, dec_s;
    sc_signal<bool> mid1, mid2, mid3, mid4, sig1, sig2, sig3, sig4, sig6, sig7 ;

    decoder dec_1;
    decoder dec_2;
    andgate and_1;
    andgate and_2;
    andgate and_3;
    andgate and_4;

    SC_CTOR(decoder2by4):dec_1("decoder_instance1")
                        ,dec_2("decoder_instance2")
                        ,and_1("andgate_instance1")
                        ,and_2("andgate_instance2")
                        ,and_3("andgate_instance3")
                        ,and_4("andgate_instance4"){
       
        dec_1.a(dec_n);
        
        dec_2.a(dec_m);        

        dec_1.b(mid1);
        and_1.x(mid1);
        and_2.x(mid1);

        dec_1.c(mid2);
        and_3.x(mid2);
        and_4.x(mid2);

        dec_2.b(mid3);
        and_1.y(mid3);
        and_3.y(mid3);

        dec_2.c(mid4);
        and_2.y(mid4);
        and_4.y(mid4);

        and_1.z(dec_o);

        and_2.z(dec_p);

        and_3.z(dec_r);

        and_4.z(dec_s);
    }

};

#endif /* DECOCER_2BY4_H_ */