module alarmeV2 (clk, reset, cr, sm, sp, sj, sirene, led);

    // Entradas
    input clk;
    input reset;
    input cr;
    input sm;
    input sp;
    input sj;

    // Saídas
    output reg sirene;
    output reg led;

    // Parâmetros
    parameter STANDBY = 2'b00;   // Sistema em espera
    parameter ALERTA  = 2'b01;   // Sistema em alerta
    parameter DISPARO = 2'b10;   // Sistema em disparo
	parameter RST = 2'b11;   //sistema em modo reset
	
	
    // Registros
    reg [1:0] estado_atual;
    reg [1:0] estado_proximo;

    // Contadores
    reg [23:0] cnt_led;
    reg [23:0] cnt_sirene;

    // Módulo de controle
    always_ff @ (posedge clk, posedge reset)
    begin
        if (reset)
            estado_atual <= STANDBY;    // Sistema reiniciado
        else
        begin
            case (estado_atual)
                STANDBY:
                    if (cr)             // Botão de controle remoto pressionado
                        estado_proximo <= ALERTA;
                    else if (sm || sp || sj)    // Sensores detectaram movimento, porta ou janela aberta
                        estado_proximo <= DISPARO;
                    else
                        estado_proximo <= STANDBY;    // Permanece em espera
                ALERTA:
                    if (cr)             // Botão de controle remoto pressionado
                        estado_proximo <= STANDBY;
                    else if (sm || sp || sj)    // Sensores detectaram movimento, porta ou janela aberta
                        estado_proximo <= DISPARO;
                    else
                        estado_proximo <= ALERTA;    // Permanece em alerta
                DISPARO:
                    if (cr)             // Botão de controle remoto pressionado
                        estado_proximo <= STANDBY;
                    else if (!sm && !sp && !sj)    // Sensores não detectaram mais movimento, porta ou janela fechada
                        estado_proximo <= ALERTA;
                    else
                        estado_proximo <= DISPARO;    // Permanece em disparo

			
				RESET:
					if (rst)
						estado_proximo <= RST; //se for acionado o reset ele vai pra reset
					else if (!rst)
						estado_proximo <= STANDBY;
						
                default:
                    estado_proximo <= STANDBY;    // Estado inválido, retorna para espera
            endcase
            estado_atual <= estado_proximo;
        end
    end

    // Módulo de controle do LED
    always @ (posedge clk)
    begin
        case (estado_atual)
            STANDBY:
                led <= 1'b1;        // LED aceso constantemente
            ALERTA:
                cnt_led <= cnt_led + 1;
                if (cnt_led == 240000)   // Contagem de 0,5 segundos
                begin
                    cnt_led <= 0;
                    led <= ~led;    // Inverte o valor do LED
                end
            DISPARO:
                cnt_led <= cnt_led + 1;
                if (cnt_led == 48000)    // Contagem de 0,1 segundos
                begin
                    cnt_led <= 0;
                    led <= ~led;    // Inverte o valor do LED
                end
            default:
                led <= 1'b1;        // LED aceso constantemente
        endcase
    end
