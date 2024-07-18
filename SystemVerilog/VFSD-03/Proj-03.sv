module controle_adc (
input  wire        clk,          //  clk
output wire        adc_sck,      //  Sinal de clock do SPI
output wire        adc_convst,   //  Disparar a conversão
input  wire        adc_sdo,      //  Receber os dados da conversão
output wire        adc_sdi,      //  Enviar dados de configuração
  output wire [11:0] dataout,      //  Dado convertido
input  wire [05:0] conf,         //  Parametro de configuração
input  wire        reset         //  RESET
);

   logic ADC_SCK, ADC_CONVST, ADC_SDI;
   logic [11:0] DataOut, Data;
   logic [5:0]  counter, DataSDI;
   logic [1:0]  currState;
   logic [4:0]  st_sdi, st_sdo;
 
   parameter convState=1'd1, transState=1'd0;

   assign DataSDI    = conf;     // Dados de configuração do conversor
   assign adc_sck    = ADC_SCK;
   assign adc_convst = ADC_CONVST;
   assign adc_sdi    = ADC_SDI;
   assign dataout    = DataOut;
 

  // FSM
  always @(posedge clk or posedge reset )
    if (reset) begin
      counter = 0;
      ADC_CONVST = 0;
    end
    else begin
      counter++;
      if (counter > 6'd2 && counter < 6'd4 ) begin
         currState = convState;
         ADC_CONVST = 1;
      end
      else
        if (counter > 6'd4 && counter < 6'd28 )begin
           currState = transState;
           ADC_CONVST = 0;
        end
        else
          if (counter > 6'd29 )
   counter = 6'd2;
          else
   counter = counter;
     end
   
 
   // ADC_SCK - Geração dos 12 Pulsos  
  always @(posedge clk or posedge reset)
     if (reset)
        ADC_SCK = 0;
     else
       if (counter > 6'd5 && counter < 6'd30 )
          ADC_SCK = ~ADC_SCK;
       else
 ADC_SCK = ADC_SCK;

 
   // ADC_SDI - Enviar dados de configuração para o ADC
  always @ (negedge clk or posedge reset)
  if (reset) begin
        ADC_SDI = 0;
        st_sdi = 0;
    end
    else
      if (currState == transState)
 case (st_sdi)
4'd00 : begin st_sdi++; ADC_SDI = DataSDI[05];  end
4'd01 : begin st_sdi++; end                
4'd02 : begin st_sdi++; ADC_SDI = DataSDI[04];  end
4'd03 : begin st_sdi++; end                                
4'd04 : begin st_sdi++; ADC_SDI = DataSDI[03];  end
4'd05 : begin st_sdi++; end                                
4'd06 : begin st_sdi++; ADC_SDI = DataSDI[02];  end
4'd07 : begin st_sdi++; end                                
4'd08 : begin st_sdi++; ADC_SDI = DataSDI[01];  end
4'd09 : begin st_sdi++; end                
4'd10 : begin st_sdi++; ADC_SDI = DataSDI[00];  end            
4'd11 : begin st_sdi++; end                                
default: ADC_SDI = 0;
 endcase
else
              st_sdi = 0;

   // ADC_SDO - Receber serialmente os dados do ADC e entregar paralelamente
   always @ (posedge ADC_SCK or posedge reset)
  if (reset) begin
        Data   = 0;
        st_sdo = 0;
    end
    else
      if (currState == transState)
    	case (st_sdo)
           4'd00  : begin st_sdo++; Data[11] = adc_sdo;  end
           4'd01  : begin st_sdo++; Data[10] = adc_sdo;  end
           4'd02  : begin st_sdo++; Data[09] = adc_sdo;  end
           4'd03  : begin st_sdo++; Data[08] = adc_sdo;  end
           4'd04  : begin st_sdo++; Data[07] = adc_sdo;  end
           4'd05  : begin st_sdo++; Data[06] = adc_sdo;  end
           4'd06  : begin st_sdo++; Data[05] = adc_sdo;  end
           4'd07  : begin st_sdo++; Data[04] = adc_sdo;  end
           4'd08  : begin st_sdo++; Data[03] = adc_sdo;  end
           4'd09  : begin st_sdo++; Data[02] = adc_sdo;  end
           4'd10  : begin st_sdo++; Data[01] = adc_sdo;  end
           default: begin st_sdo=0; Data[00] = adc_sdo;  end
    endcase
  else
             st_sdo=0;

//  Disponibiliza o dado depois de paralelizar
   always @ (posedge clk or posedge reset)
    if (reset)
      DataOut = 0;
  else
      if (ADC_CONVST)
		DataOut = Data;
	else
		DataOut = DataOut;


endmodule