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
