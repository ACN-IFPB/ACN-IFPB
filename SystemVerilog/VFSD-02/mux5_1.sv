module mux (sel, in_5, in_4, in_3, in_2, in_1, in_0, out_mux);
    
    input bit[2:0] sel;
    input bit in_0, in_1, in_2, in_3, in_4, in_5;
	output bit out_mux;
	
  always_comb begin
      case (sel) 
			3'b000 : out_mux = in_0;
			3'b001 : out_mux = in_1;
			3'b010 : out_mux = in_2;
			3'b011 : out_mux = in_3;
			3'b100 : out_mux = in_4;
			3'b101 : out_mux = in_5;
			default: out_mux = 0;
	 endcase
   end
endmodule


/*module mux5_1 (sel, in_5, in_4, in_3, in_2, in_1, in_0, out_mux);    
    input bit[2:0] sel;
    input bit in_0, in_1, in_2, in_3, in_4, in_5;
	 output bit out_mux;
	
	always_comb
		begin
			case (sel)
				4'd00 :  out_mux = in_0;
				
				4'd01 :  out_mux = in_1;
		
				4'd02 :  out_mux = in_2;

				4'd03 :  out_mux = in_3;
				
				4'd04 :  out_mux = in_4;
		
				default: out_mux = in_5;		
			endcase
			
		end

endmodule
*/