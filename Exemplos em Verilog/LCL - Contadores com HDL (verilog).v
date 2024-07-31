
//Anexos 

//Contador gray módulo 7
module cont_gray_mod_7(a,ck,clr);

	input ck,clr;
	output [2:0] a;

	wire [2:0] j,k;

	FF_JK FF_2 (a[2], j[2], k[2], clr, ck);
	FF_JK FF_1 (a[1], j[1], k[1], clr, ck);
	FF_JK FF_0 (a[0], j[0], k[0], clr, ck);

	porta_and U1 (j[2], a[1], ~a[0]);
	k[2]=~a[1];

	porta_and U2 (j[1], ~a[2], a[0]);
	porta_and U3 (k[1], a[2], a[0]);

	porta_xnor U4 (j[0],a[2],a[1]);
	porta_xor U5 (k[0],a[2],a[1]);

endmodule 

//Mod_teste
wire ck, clr;
wire [2:0] a;

assign clr = SW[2];
assign ck = SW[0];

cont_gray_mod_7(a,ck,clr);

assign LEDR[2:0] = a [2:0]

//********************************************************

//Contador jonhson modificado de 4 bits
module cont_johnson_mod_4bits(a,ck,clr);

	input ck,clr;
	output [3:0] a;

	wire [3:0] j,k;
	wire x;

	FF_JK FF_3 (a[3], j[3], k[3], clr, ck);
	FF_JK FF_2 (a[2], j[2], k[2], clr, ck);
	FF_JK FF_1 (a[1], j[1], k[1], clr, ck);
	FF_JK FF_0 (a[0], j[0], k[0], clr, ck);

	porta_and U1 (x, a[1], a[2]);
	porta_or U2 (k[3], x, a[0]);
	
	porta_and U3 (j[3], ~a[1], ~a[0]);
	
endmodule 

//Mod_teste
wire ck, clr;
wire [3:0] a;

assign clr = SW[2];
assign ck = SW[0];

cont_gray_mod_7(a,ck,clr);

assign LEDR[3:0] = a [3:0];

//********************************************************

//Contador síncrono em anel de 4 bits
module cont_anel_4bits(a,ck,clr,sel,i);

	input ck,clr,sel;
	input [3:0] i;
	output [3:0] a;

	wire [3:0] d;
	

	mux2p1 mux3 (d[3], sel, i[3], 0);
	mux2p1 mux2 (d[2], sel, i[2], a[3]);
	mux2p1 mux1 (d[1], sel, i[1], a[2]);
	mux2p1 mux0 (d[0], sel, i[0], a[1]);

	FF_D FF_D_3 (a[3], d[3], clr, ck);
	FF_D FF_D_2 (a[2], d[2], clr, ck);
	FF_D FF_D_1 (a[1], d[1], clr, ck);
	FF_D FF_D_0 (a[0], d[0], clr, ck);

endmodule 

//Mod_teste
wire ck, clr,sel;
wire [3:0] a,i;

assign i [3:0] = SW[3:0];

assign sel = SW[5];
assign clr = SW[6];
assign ck = SW[8];

cont_anel_4bits(a,ck,clr,sel,i)

assign LEDR[3:0] = a [3:0];

//********************************************************

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

//Mod_teste
wire ck, clr,sel;
wire [2:0] a;

assign sel = SW[3];
assign clr = SW[1];
assign ck = SW[0];

Cont_mod_8_cres_decres(a,ck,clr,sel);

assign LEDR[2:0] = a [2:0];

