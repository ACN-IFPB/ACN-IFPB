/*module contDec(clk_in, reset, clk_out);
	 	 
  input clk_in, reset;
  output bit clk_out;
  
  logic [3:0] count;
    
  always_ff @(posedge clk_in, negedge reset)
    begin
      if (!reset) begin
        count = 0;
        clk_out = 0;
      end
      else
        if (count == 4 ) begin
            count = 0;
            clk_out = ~clk_out;
         end
         else begin
            count = count + 1;
         end
    end
endmodule

*/

module cont_Dec(clk_in, reset, clk_out);
  input clk_in, reset;
  output bit clk_out;
  
  always @ (negedge clk_in)
	begin
		if (reset)
			begin
			if (clk_out >= 4'd0 && clk_out < 4'd10) //4bits pq o 10 é 1010
				clk_out <= clk_out + 4'd1;
			else
				clk_out <= 4'd0;
			end
		
		else
			clk_out <= 4'd0;
	end 
  
endmodule
