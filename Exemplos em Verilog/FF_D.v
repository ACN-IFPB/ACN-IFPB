//Módulo flip-flop tipo D

module FF_D (q, d, clr, ck);

	input d,clr,ck;
	output reg q;
	
	always @(negedge ck or negedge clr)
	begin 
		if(clr==0) q=0;
		else q=d;
		
	end
endmodule
	
