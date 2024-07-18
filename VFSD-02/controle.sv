module temp_controle (clk_controle, reset, arm, limp, hab);
    
    input clk_controle, reset;
    output bit arm, limp, hab;
  
    logic [4:0] {estado_0, estado_1, estado_2, estado_3, estado_4, estado_5} estado = estado_0;
	
  always @ (posedge clk_controle, negedge reset )
    begin
      if (!reset) begin
        arm = 0;
        limp = 0;
        hab = 0;
        estado = 0;
      end
      else
        case (estado) 
			3'b000 : begin
              			limp = 1; 
              			hab  = 0;
              			arm  = 0;
              			estado = 1;
            		 end	
			3'b001 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 2;
            		 end	
			3'b010 : begin
              			limp = 0; 
              			hab  = 1;
              			arm  = 0;
              			estado = 3;
            		 end	
			3'b011 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 4;
            		 end	
			3'b100 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 1;
              			estado = 5;
            		 end	
			3'b101 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 1;
            		 end
          	default : begin
              			limp = 1; 
              			hab  = 0;
              			arm  = 0;
              			estado = 0;
            		 end			
	 endcase
   end
endmodule

/*module controle (clk_controle, reset, arm, limp, hab);
    
    input clk_controle, reset;
    output bit arm, limp, hab;
  
    logic [2:0] estado;
	
  always @ (posedge clk_controle, negedge reset )
    begin
      if (!reset) begin
        arm = 0;
        limp = 0;
        hab = 0;
        estado = 0;
      end
      else
        case (estado) 
			3'b000 : begin
              			limp = 1; 
              			hab  = 0;
              			arm  = 0;
              			estado = 1;
            		 end	
			3'b001 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 2;
            		 end	
			3'b010 : begin
              			limp = 0; 
              			hab  = 1;
              			arm  = 0;
              			estado = 3;
            		 end	
			3'b011 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 4;
            		 end	
			3'b100 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 1;
              			estado = 5;
            		 end	
			3'b101 : begin
              			limp = 0; 
              			hab  = 0;
              			arm  = 0;
              			estado = 1;
            		 end
          	default : begin
              			limp = 1; 
              			hab  = 0;
              			arm  = 0;
              			estado = 0;
            		 end			
	 endcase
   end
endmodule
*/