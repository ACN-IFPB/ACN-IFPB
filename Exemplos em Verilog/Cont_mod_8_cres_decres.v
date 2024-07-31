//Contador asíncrono módulo 8 crescente/decrescente

module Cont_mod_8_cres_decres(a,ck,clr,sel);

	input ck,clr,sel;
	output [2:0] a;

	wire ck1,ck2 ;

	FF_T FF_T_0 (a[0], 1, clr, ck);
	mux2p1 mux0 (ck1, sel, a[0], ~a[0]);

	FF_T FF_T_1 (a[1], 1, clr, ck1);
	mux2p1 mux1 (ck2, sel, a[1], ~a[1]);

	FF_T FF_T_2 (a[2], 1, clr, ck2);


endmodule 
