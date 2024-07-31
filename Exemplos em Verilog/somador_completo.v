//somador_completo

module somador_completo(s,ts,a,b,te);
	input a,b,te;
	output s,ts;
	
	assign s=(a^b)^te;
	assign ts=((a^b)&te)|(a&b);

endmodule 

