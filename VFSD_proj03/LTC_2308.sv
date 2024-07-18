//versão 0.2
module LTC2308_SPI (
  input wire clk,         // Clock sinal
  input wire reset,       // Reset sinal
  output wire cs,         // Chip select sinal
  output wire sdi,        // Serial data input
  input wire sdo,         // Serial data output
  output wire sclk,       // Serial clock
  output wire convst,     // Conversion start sinal
  input wire [7:0] adc_data  // ADC data output
);

  // sinais internos
  reg [7:0] spi_byte;
  reg [3:0] bit_counter;
  reg [15:0] adc_result;

  // Initialização
  initial begin
    spi_byte <= 8'h00;
    bit_counter <= 4'd0;
    adc_result <= 16'h0000;
  end

  // Maquinas de Estados
  localparam IDLE = 2'd0;
  localparam START = 2'd1;
  localparam TRANSFER = 2'd2;
  localparam FINISH = 2'd3;

  // Estado do CI
  reg [1:0] state;

  always @(posedge clk or posedge reset) begin
    if (reset)
      state <= IDLE;
    else begin
      case (state)
        IDLE:
          if (convst)
            state <= START;
        START:
          begin
            cs <= 1'b0;
            spi_byte <= 8'h00;
            bit_counter <= 4'd0;
            state <= TRANSFER;
          end
        TRANSFER:
          begin
            sdi <= spi_byte[7];
            spi_byte <= spi_byte << 1;
            bit_counter <= bit_counter + 1;
            if (bit_counter == 4'd11)
              state <= FINISH;
          end
        FINISH:
          begin
            cs <= 1'b1;
            adc_result <= {sdo, adc_data[14:1]};  // Assuming 16-bit ADC data
            state <= IDLE;
          end
      endcase
    end
  end

endmodule
