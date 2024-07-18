// Code your design here
module controle_adc (
		input  wire clk,               //  clk
		output wire adc_sck,           //  Sinal de clock do SPI
		output wire adc_convst,        //  Disparar a conversão
		input  wire adc_sdo,           //  Receber os dados da conversão
		output wire adc_sdi,           //  Enviar dados de configuração
  		output wire [11:0] dataout,    //  Dado convertido
		input  wire [5:0] conf,       //  Parametro de configuração
		input  wire reset              //  RESET
	);
  
  bit sck, convst, sdi;
  logic[5:0] contador;
  logic[11:0] out, auxOut;
  enum bit[1:0] {convertendo,transmitindo} estado;
  logic[5:0] confSDI;
  logic[3:0] contSDI, contSDO;
  
  
  assign adc_convst = convst;
  assign adc_sck = sck;
  assign adc_sdi = sdi;
  assign confSDI = conf;
  assign dataout = out;
  
  
  //maquina de estados
  always @(posedge clk or posedge reset) begin
    if(reset == 1) begin
      convst = 0;
      contador = 0;
    end
    else begin
      contador = contador + 1;
      if(contador > 2 && contador < 4) begin
        convst = 1;
		estado = convertendo;
      end
      else begin
        if(contador > 4 && contador < 28) begin
          convst = 0;
          estado = transmitindo;
        end
        else begin
          if(contador > 29) begin
			contador = 2;
          end
          else begin
            contador = contador;
          end
        end
      end
	end
  end
  
  
  //clock de sincronia com o adc para envio de informação
  always @(posedge clk or posedge reset) begin
    if (reset == 1) begin
      sck = 0;
    end
    else begin
      if (contador > 5 && contador < 30) begin
        sck = ~sck;
      end
      else begin
        sck = sck;
      end
    end
  end
  
  
  //envia informação para o adc
  always @(posedge sck or posedge reset or posedge convst) begin
    if (reset == 1) begin
      sdi = 0;
      contSDI = 0;
    end
    else begin
      if(convst == 1) begin
        contSDI = 0;
      end
      else begin
        if (estado == transmitindo) begin
          contSDI = contSDI + 1;
          case (contSDI)
            1: begin
              sdi = confSDI[5];
            end
            2: begin
              sdi = confSDI[4];
            end
            3: begin
              sdi = confSDI[3];
            end
            4: begin
              sdi = confSDI[2];
            end
            5: begin
              sdi = confSDI[1];
            end
            6: begin
              sdi = confSDI[0];
            end
            default: begin
              sdi = sdi;
            end
          endcase
        end
        else begin
          contSDI = 0;
        end
      end
    end
  end
  
  
  //recebe informação do adc
  always @(posedge sck or posedge reset or posedge convst) begin
    if (reset == 1) begin
      auxOut = 0;
      contSDO = 0;
    end
    else begin
      if(convst == 1) begin
        contSDO = 0;
      end
      else begin
        if (estado == transmitindo) begin
          contSDO = contSDO + 1;
          case (contSDO)
            1: begin
              auxOut[0] = adc_sdo;
            end
            2: begin
              auxOut[1] = adc_sdo;
            end
            3: begin
              auxOut[2] = adc_sdo;
            end
            4: begin
              auxOut[3] = adc_sdo;
            end
            5: begin
              auxOut[4] = adc_sdo;
            end
            6: begin
              auxOut[5] = adc_sdo;
            end
            7: begin
              auxOut[6] = adc_sdo;
            end
            8: begin
              auxOut[7] = adc_sdo;
            end
            9: begin
              auxOut[8] = adc_sdo;
            end
            10: begin
              auxOut[9] = adc_sdo;
            end
            11: begin
              auxOut[10] = adc_sdo;
            end
            12: begin
              auxOut[11] = adc_sdo;
            end
            default: begin
              auxOut = auxOut;
            end
          endcase
        end
        else begin
          contSDO = 0;
        end
      end
    end
  end
   
  
  //informa os dados de saida paralelizados
  always @ (posedge clk or posedge reset) begin
    if (reset == 1) begin
      out = 0;
    end
    else begin
      if (convst == 1) begin
        out = auxOut;
      end
      else begin
        out = out;
      end
    end
  end

  
endmodule