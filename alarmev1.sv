module alarmev1 (clk, reset, cr, sm, sp, sj, sirene, led);
  input clk, reset, cr, sp, sj, sm;
  
  output bit sirene = 0;
  output bit led = 0;
  
  int count_alert = 0, count_disp = 0;
  bit led_alert = 0, led_disp = 0;
  bit click = 0;
  bit down_click = 0;

  enum logic [4:0] {sb, alerta, disparo} estado = sb;

  // ler controle remoto
	always @ (posedge cr or posedge down_click)
	begin
      if(down_click)
			click <= 0;
		else
			click <= 1;
	end

  // gera os estados
  always @ (posedge reset or posedge clk) 
    begin
        
      if (reset == 1)  
        begin
          down_click <= 1;
          estado <= sb;
        end
      else
        case (estado)
          sb: 
            begin
				  down_click <= 0;
              if(click) 
                begin
                  estado <= alerta;    
                  down_click <= 1;
                end
            end
          alerta: 
            begin
				  down_click <= 0;
              if(click) 
                begin
                  estado <= sb;    
                  down_click <= 1;
                end 
              else if(sm || sp || sj)
                estado <= disparo;
            end
          disparo: 
            begin
				  down_click <= 0;
              if(click) 
                begin
                  estado <= sb;    
                  down_click <= 1;
                end 
            end
          default:
            estado <= sb;
        endcase    
    end

  //saida dos estados
  always_comb 
    begin
      case (estado)
        sb:
        begin
          sirene <= 0;
          led <= 1;
        end
        alerta: 
          begin
            sirene <= 0;
            led <= led_alert;
          end
        disparo:
          begin
            sirene <= 1;
            led = led_disp;
          end
        default:
          begin
            sirene <= 0;                  
            led <= 0;
          end
      endcase  
    end

  //led

  always @ (posedge clk) 
  begin
    if(reset)
      count_alert <= 0;
    else
    begin
      count_alert++;
      if(count_alert == 5)
      begin
          led_alert <= ~led_alert;
          count_alert <= 0;
      end
    end
  end
    
  always @ (posedge clk) 
  begin
    if(reset)
      count_disp <= 0;
    else
    begin
      count_disp++;
      if(count_disp == 1)
      begin
        led_disp <= ~led_disp;
        count_disp <= 0;
      end
    end
  end
	 
endmodule