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
