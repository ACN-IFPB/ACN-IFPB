//Porta_xnor

module porta_xor(s,a,b);
	input a,b;
	output s;

	assign s = (a ~^ b);
endmodule 
