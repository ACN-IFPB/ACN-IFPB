// Conversor Hexadecimal para Display de 7 Segmentos

module convHexa7Seg (hexa, SeteSegmentos);
	input  [3:0] hexa;
	output [6:0] SeteSegmentos;
	
	always @ (hexa) begin
		case (hexa)
			4'b0000 : SeteSegmentos = 7'b1000000;
			4'b0001 : SeteSegmentos = 7'b1111001;
			4'b0010 : SeteSegmentos = 7'b0100100;
			4'b0011 : SeteSegmentos = 7'b0110000;
			4'b0100 : SeteSegmentos = 7'b0011001;
			4'b0101 : SeteSegmentos = 7'b0010010;
			4'b0110 : SeteSegmentos = 7'b0000010;
			4'b0111 : SeteSegmentos = 7'b1111000;
			4'b1000 : SeteSegmentos = 7'b0000000;
			4'b1001 : SeteSegmentos = 7'b0011000;
			4'b1010 : SeteSegmentos = 7'b0001000;
			4'b1011 : SeteSegmentos = 7'b0000011;
			4'b1100 : SeteSegmentos = 7'b1000110;
			4'b1101 : SeteSegmentos = 7'b0100001;
			4'b1110 : SeteSegmentos = 7'b0000110;
			4'b1111 : SeteSegmentos = 7'b0001110;
		endcase
	end
endmodule