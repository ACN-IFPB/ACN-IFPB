//Módulo flip-flop tipo T

module FF_T (q, t, clr, ck);

	input t,clr,ck;
	output reg q;
	
	always @(negedge ck or negedge clr)
	begin 
		if(clr==0) q=0;
		else if(t==0) q=q;
			else q=~q;
	end
endmodule
	
