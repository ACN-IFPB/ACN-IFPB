/* VERIFICAÇÃO FUNCIONAL DE SISTEMAS DIGITAIS
		PERÍODO: 2023.1 
		PROFESSOR: GEORGE SOBRAL
		ALUNOS: ADRIEL CASSIMIRO E DIOGO SANTOS
*/


//modulo para diminuir o clock para 1k

module clk_1k(clk_in_50M, reset, clk_out_1K);
	 	 
  input clk_in_50M, reset;
  output bit clk_out_1K;
  
  logic [15:0] contador = 0;
    
  always_ff @(posedge clk_in_50M, posedge reset) begin
    if (reset) begin
		clk_out_1K = 0;
		contador = 0;
	 end
    else begin
		if(contador == 25000) begin
			clk_out_1K = ~clk_out_1K;
			contador = 0;
		end
		else begin
			contador = contador + 1;
		end
	 end
  end
endmodule
