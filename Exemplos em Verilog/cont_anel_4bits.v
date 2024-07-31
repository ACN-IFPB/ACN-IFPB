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
