module alarmev1 (clk, reset, cr, sm, sp, sj, sirene, led);
  input clk, reset, cr, sp, sj, sm;
  
  output bit sirene = 0;
  output bit led = 0;
  
  int ContAlerta = 0, ContDisparo = 0;
  bit LedAlerta = 0, LedDisparo = 0;
  bit Botao = 0;
  bit PressBotao  = 0;

  enum logic [4:0] {sb, alerta, disparo} estado = sb;

  // ler controle remoto
	always @ (posedge cr or posedge  PressBotao )
	begin
      if( PressBotao )
			Botao <= 0;
		else
			Botao <= 1;
	end

  // gera os estados
  always @ (posedge reset or posedge clk) 
    begin
        
      if (reset == 1)  
        begin
           PressBotao  <= 1;
          estado <= sb;
        end
      else
        case (estado)
          sb: 
            begin
				   PressBotao  <= 0;
              if(  Botao  ) 
                begin
                  estado <= alerta;    
                   PressBotao  <= 1;
                end
            end
          alerta: 
            begin
				   PressBotao  <= 0;
              if(  Botao  ) 
                begin
                  estado <= sb;    
                   PressBotao  <= 1;
                end 
              else if(sm || sp || sj)
                estado <= disparo;
            end
          disparo: 
            begin
				   PressBotao  <= 0;
              if(  Botao  ) 
                begin
                  estado <= sb;    
                   PressBotao  <= 1;
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
            led <= LedAlerta;
          end
        disparo:
          begin
            sirene <= 1;
            led = LedDisparo;
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
      ContAlerta <= 0;
    else
    begin
      ContAlerta++;
      if(ContAlerta == 5)
      begin
          LedAlerta <= ~LedAlerta;
          ContAlerta <= 0;
      end
    end
  end
    
  always @ (posedge clk) 
  begin
    if(reset)
      ContDisparo <= 0;
    else
    begin
      ContDisparo++;
      if(ContDisparo == 1)
      begin
        LedDisparo <= ~LedDisparo;
        ContDisparo <= 0;
      end
    end
  end
	 
endmodule