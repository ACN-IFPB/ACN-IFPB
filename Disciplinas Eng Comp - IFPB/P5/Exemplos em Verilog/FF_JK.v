//Módulo flip-flop tipo JK

module FF_JK (q, j, k, clr, ck);

	input j,k,clr,ck;
	output reg q;
	
	always @(negedge ck or negedge clr)
	begin 
		if(clr==0) q=0;
		else 
		begin
			case({j,k})
				0: q=q;
				1: q=0;
				2: q=1;
				3: q=~q;
			endcase
		end
	end
endmodule
	