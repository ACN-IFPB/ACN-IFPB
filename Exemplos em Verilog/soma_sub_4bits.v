// Somador/subtrator 4 bits

module soma_sub_4bits(s,ts,e,a,b,sel);

	input [3:0] a,b;
	input sel;
	output [3:0] s;
	output ts,e;
	
	wire [3:0] z;
	
	igual_comp_1 U1 (z,sel,b);
	somador_4bits U2 (s,ts,a,z,sel);
	detector_estouro U3 (e,a[3],z[3],s[3]);

endmodule

