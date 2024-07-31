module SEG7_LUT (oSEG, iDIG);
input [3:0] iDIG;
output [6:0] oSEG;
reg [6:0] oSEG;

always @ (iDIG)
begin
	case (iDIG)
		4'h0: oSEG = 7'b1000000;
		4'h1: oSEG = ~7'b0000110;
		4'h2: oSEG = ~7'b1011011;
		4'h3: oSEG = ~7'b1001111;
		4'h4: oSEG = ~7'b1100110;
		4'h5: oSEG = ~7'b1101101;
		4'h6: oSEG = ~7'b1111101;
		4'h7: oSEG = ~7'b0000111;
		4'h8: oSEG = ~7'b1111111;
		4'h9: oSEG = ~7'b1101111;
		4'ha: oSEG = ~7'b1110111;
		4'hb: oSEG = ~7'b1111100;
		4'hc: oSEG = ~7'b0111001;
		4'hd: oSEG = ~7'b1011110;
		4'he: oSEG = ~7'b1111001;
		4'hf: oSEG = ~7'b1110001;
	
	
	endcase
end
endmodule 