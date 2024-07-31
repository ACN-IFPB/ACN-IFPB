// Seletor: Igualdade/Complemento de 1

module igual_comp_1(z,sel,b);
	
	input [3:0] b;
	input sel;
	output [3:0] z;
	
	assign z[0] = sel ^ b[0];
	assign z[1] = sel ^ b[1];
	assign z[2] = sel ^ b[2];
	assign z[3] = sel ^ b[3];

endmodule 