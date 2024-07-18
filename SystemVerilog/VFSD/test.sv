module alarme( input clk, input reset, input cr, input sm, input sp, input sj, output sirene, output led );

   logic [2:0] estado_atual;
   logic [2:0] prox_estado;

  // Constantes para definir o estado atual
  parameter STANDBY = 3'b000;
  parameter ALERTA = 3'b001;
  parameter DISPARO = 3'b010;

  // Definir o tempo de piscar do LED para o estado de alerta e de disparo
  parameter ALERTA_LED_PERIOD = 1'b1;
  parameter DISPARO_LED_PERIOD = 1'b0;

  // Definir o tempo para piscar a sirene
  parameter SIRENE_PERIOD = 5;

  // Contadores para controlar o tempo de piscar da sirene e do LED
  logic [2:0] led_counter;
  logic [2:0] sirene_counter;

  // Definir o valor padrão dos sinais de saída
  assign sirene = 1'b0;
  assign led = 1'b1;

  always_ff @(posedge clk, negedge reset) begin
    if (!reset) begin
      // Reiniciar o estado do sistema
      estado_atual <= STANDBY;
    end else begin
      // Definir o próximo estado do sistema com base no estado atual e nos sinais de entrada
      case (estado_atual)
        STANDBY: begin
          if (cr) begin
            prox_estado = ALERTA;
          end else if (sm || sp || sj) begin
            prox_estado = DISPARO;
          end else begin
            prox_estado = STANDBY;
          end
        end
        ALERTA: begin
          if (cr) begin
            prox_estado = STANDBY;
          end else if (sm || sp || sj) begin
            prox_estado = DISPARO;
          end else begin
            prox_estado = ALERTA;
          end
        end
        DISPARO: begin
          if (cr) begin
            prox_estado = STANDBY;
          end else if (!sm && !sp && !sj) begin
            prox_estado = ALERTA;
          end else begin
            prox_estado = DISPARO;
          end
        end
      endcase
      estado_atual <= prox_estado;
    end
  end

  always_ff @(posedge clk) begin
    // Contador para piscar o LED
    if (estado_atual == ALERTA || estado_atual == DISPARO) begin
      led_counter <= led_counter + 1;
      if (led_counter == ALERTA_LED_PERIOD && estado_atual == ALERTA) begin
        led <= ~led;
        led_counter <= 0;
      end else if (led_counter == DISPARO_LED_PERIOD && estado_atual == DISPARO) begin
        led <= ~led;
        led_counter <= 0;
      end
    end else begin
      led_counter <= 0;
      led <= 1'b1;
    end

    // Contador para piscar a sirene
    if (estado_atual == DISPARO) begin
      sirene_counter <= sirene_counter + 1;
      if (sirene_counter == SIRENE_PERIOD) begin
        sirene <= ~sirene;
        sirene_counter <= 0;
      end
   

    else begin
      sirene_counter <= 0;
      sirene <= 1'b0;
    end
end

endmodule: alarme