// Verificar 

module cont_BCD (clk_amostra, reset, limp, hab, cont_3, cont_2, cont_1, cont_0  );   
    input clk_amostra, reset, limp, hab;
    output logic [3:0] cont_3, cont_2, cont_1, cont_0;
	
	  
      bit clk_0, clk_1, clk_2, clk_3;

      always_ff @ (negedge clk_amostra, negedge reset, posedge limp) 
        begin
        if (!reset || limp) 
          begin
          clk_0 <= 0;
          cont_0 <= 0;
          end
        else if (hab) 
          begin
          if(cont_0 == 9) 
            begin
            clk_0 <= 1;
            cont_0 <= 0;
            end
          else begin
            clk_0 <= 0;
            cont_0++;
          end
        end
      end

  
      always_ff @ (posedge clk_0, negedge reset, posedge limp) 
        begin
        if (!reset || limp) 
          begin
          clk_1 <= 0;
          cont_1 <= 0;
          end
        else if (hab) 
          begin
          if (cont_1 == 9) 
            begin
            clk_1 <= 1;
            cont_1 <= 0;
          end
          else begin
            clk_1 <= 0;
            cont_1++;
          end
        end
      end

  
      always_ff @ (posedge clk_1, negedge reset, posedge limp) 
        begin
        if (!reset || limp) 
          begin
          clk_2 <= 0;
          cont_2 <= 0;
          end
        else if (hab) 
          begin
          if (cont_2 == 9) 
            begin
            clk_2 <= 1;
            cont_2 <= 0;
          end
          else begin
            clk_2 <= 0;
            cont_2++;
          end
        end
      end

  
      always_ff @ (posedge clk_2, negedge reset, posedge limp) 
        begin
        if (!reset || limp) 
          begin
          clk_3 <= 0;
          cont_3 <= 0;
        end
        else if (hab) 
          begin
          if (cont_3 == 9) 
            begin
            clk_3 <= 1;
            cont_3 <= 0;
          end
          else begin
            clk_3 <= 0;
            cont_3++;
          end
        end
      end

  
endmodule




/* module cont_BCD (clk_amostra, reset, limp, hab, cont_3, cont_2, cont_1, cont_0  );   
	input clk_amostra, reset, limp, hab;
    output logic [3:0] cont_3, cont_2, cont_1, cont_0;
  
   wire  clk_0, clk_1, clk_2, clk_3;
	//wire bit clk_0, clk_1, clk_2, clk_3;
  
  //contador_BCD00
  
  always_ff @ (negedge clk_amostra, negedge reset, negedge limp) 
		
      begin
          if (!reset || limp) 
            begin
					clk_0 <= 0;
      			cont_0 <= 0;
    		   end
    	  
          else 
				if (hab) 
					begin        
						if(cont_0 == 9) 
							begin
								clk_0 <= 1;
								cont_0 <= 0;
      					end 
				else 
					begin
						clk_0 <= 0;
						cont_0++;
      	   	end
    	   end
  	  end
  //contador_BCD01
  
  always_ff @ (negedge clk_amostra, negedge reset, negedge limp) 
		
      begin
          if (!reset || limp) 
            begin
	  			clk_1 <= 0;
      			cont_1 <= 0;
    		end
    	  
          else if (hab) 
            begin        
              if(cont_1 == 9) 
            	begin
        			clk_1 <= 1;
        			cont_1 <= 0;
      			end 
      	 	else 
           		begin
        			clk_1 <= 0;
        			cont_1++;
      	   		end
    	   end
  	  end
  
    //contador_BCD02
  
  always_ff @ (negedge clk_amostra, negedge reset, negedge limp) 
		
      begin
          if (!reset || limp) 
            begin
	  			clk_2 <= 0;
      			cont_2 <= 0;
    		end
    	  
          else if (hab) 
            begin        
              if(cont_2 == 9) 
            	begin
        			clk_2 <= 1;
        			cont_2 <= 0;
      			end 
      	 	else 
           		begin
        			clk_2 <= 0;
        			cont_2++;
      	   		end
    	   end
  	  end  
  
  //contador_BCD03
  
  always_ff @ (negedge clk_amostra, negedge reset, negedge limp) 
		
      begin
          if (!reset || limp) 
            begin
	  			clk_3 <= 0;
      			cont_3 <= 0;
    		end
    	  
          else if (hab) 
            begin        
              if(cont_3 == 9) 
            	begin
        			clk_3 <= 1;
        			cont_3 <= 0;
      			end 
      	 	else 
           		begin
        			clk_3 <= 0;
        			cont_3++;
      	   		end
    	   end
  	  end
  

endmodule

*/
