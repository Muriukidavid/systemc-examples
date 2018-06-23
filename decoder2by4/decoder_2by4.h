/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#ifndef DECOCER_2BY4_H_
#define DECOCER_2BY4_H_

#include "../decoder1by2/decoder_1by2.h"
#include "andgate.h"
#include<systemc.h>

SC_MODULE(decoder2by4){
    sc_in<bool> dec_a, dec_b;
    sc_out<bool> dec_c, dec_d, dec_e, dec_f;
    sc_signal<bool> sig1, sig2, sig3, sig4;

    decoder dec_1;
    decoder dec_2;
    andgate and_1;
    andgate and_2;
    andgate and_3;
    andgate and_4;

    SC_CTOR(decoder2by4):dec_1("decoder_instance1"),dec_2("decoder_instance2"),and_1("andgate_instance1"),and_2("andgate_instance2"),and_3("andgate_instance3"),and_4("andgate_instance4"){
       
        dec_1.a(dec_b);
        dec_2.a(dec_a);        

        dec_1.b(sig1);
        and_1.x(sig1);
        and_2.x(sig1);

        dec_1.c(sig2);
        and_3.x(sig2);
        and_4.x(sig2);

        dec_2.b(sig3);
        and_1.y(sig3);
        and_3.y(sig3);

        dec_2.c(sig4);
        and_2.y(sig4);
        and_4.y(sig4);

        and_1.z(dec_c);
        and_2.z(dec_d);
        and_3.z(dec_e);
        and_4.z(dec_f);
    }

};
#endif /* DECOCER_2BY4_H_ */
