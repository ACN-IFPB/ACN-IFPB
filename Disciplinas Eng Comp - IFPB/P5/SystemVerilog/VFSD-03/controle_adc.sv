module controle_adc (
  input wire        clk,          //  clk
  output wire       adc_sck,      //  Sinal de clock do SPI
  output wire       adc_convst,   //  Disparar a conversão
  input  wire       adc_sdo,      //  Receber os dados da conversão
  output wire       adc_sdi,      //  Enviar dados de configuração
  output wire [11:0] dataout,      //  Dado convertido
  input  wire [5:0]  conf,         //  Parâmetro de configuração
  input  wire       reset         //  RESET
);

  reg [11:0] dataout;
  reg [5:0]  counter;
  reg [1:0]  currState;
  reg [4:0]  st_sdi, st_sdo;
  reg        ADC_SCK, ADC_CONVST, ADC_SDI;

  // Parâmetros de estado
  parameter convState = 1'b1;
  parameter transState = 1'b0;

  // Atribuição dos sinais de saída
  assign adc_sck = ADC_SCK;
  assign adc_convst = ADC_CONVST;
  assign adc_sdi = ADC_SDI;
  assign dataout = DataOut;

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      counter <= 0;
      ADC_CONVST <= 0;
    end else begin
      counter <= counter + 1;
      case (counter)
        6'd2: begin
          currState <= convState;
          ADC_CONVST <= 1;
        end
        6'd4: begin
          currState <= transState;
          ADC_CONVST <= 0;
        end
        6'd29: counter <= 6'd2;
        default: counter <= counter;
      endcase
    end
  end

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      ADC_SCK <= 0;
    end else begin
      if (counter > 6'd5 && counter < 6'd30) begin
        ADC_SCK <= ~ADC_SCK;
      end else begin
        ADC_SCK <= ADC_SCK;
      end
    end
  end

  always @(negedge clk or posedge reset) begin
    if (reset) begin
      ADC_SDI <= 0;
      st_sdi <= 0;
    end else begin
      if (currState == transState) begin
        case (st_sdi)
          4'd0: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[5];
          end
          4'd1: begin
            st_sdi <= st_sdi + 1;
          end
          4'd2: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[4];
          end
          4'd3: begin
            st_sdi <= st_sdi + 1;
          end
          4'd4: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[3];
          end
          4'd5: begin
            st_sdi <= st_sdi + 1;
          end
          
		4'd5: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[2];
          end
          4'd6: begin
            st_sdi <= st_sdi + 1;
          end
          4'd7: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[1];
          end
          4'd8: begin
            st_sdi <= st_sdi + 1;
          end
          4'd9: begin
            st_sdi <= st_sdi + 1;
            ADC_SDI <= conf[0];
          end
          4'd10: begin
            st_sdi <= st_sdi + 1;
          end
          default: ADC_SDI <= 0;
        endcase
      end else begin
        st_sdi <= 0;
      end
    end
  end

  always @(posedge ADC_SCK or posedge reset) begin
    if (reset) begin
      data <= 0;
      st_sdo <= 0;
    end else begin
      if (currState == transState) begin
        case (st_sdo)
          4'd0: begin
            st_sdo <= st_sdo + 1;
            data[11] <= adc_sdo;
          end
          4'd1: begin
            st_sdo <= st_sdo + 1;
            data[10] <= adc_sdo;
          end
          4'd2: begin
            st_sdo <= st_sdo + 1;
            data[9] <= adc_sdo;
          end
          4'd3: begin
            st_sdo <= st_sdo + 1;
            data[8] <= adc_sdo;
          end
          4'd4: begin
            st_sdo <= st_sdo + 1;
            data[7] <= adc_sdo;
          end
          4'd5: begin
            st_sdo <= st_sdo + 1;
            data[6] <= adc_sdo;
          end
          4'd6: begin
            st_sdo <= st_sdo + 1;
            data[5] <= adc_sdo;
          end
          4'd7: begin
            st_sdo <= st_sdo + 1;
            data[4] <= adc_sdo;
          end
          4'd8: begin
            st_sdo <= st_sdo + 1;
            data[3] <= adc_sdo;
          end
          4'd9: begin
            st_sdo <= st_sdo + 1;
            data[2] <= adc_sdo;
          end
          4'd10: begin
            st_sdo <= st_sdo + 1;
            data[1] <= adc_sdo;
          end
          default: begin
            st_sdo <= 0;
            data[0] <= adc_sdo;
          end
        endcase
      end else begin
        st_sdo <= 0;
      end
    end
  end

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      dataout <= 0;
    end else begin
      if (ADC_CONVST) begin
        dataout <= data;
      end else begin
        dataout <= dataout;
      end
    end
  end

endmodule
