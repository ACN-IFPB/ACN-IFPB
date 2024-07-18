module tb;
  bit clk = 0;
  bit reset = 0;
  bit sp = 0;
  bit sj = 0;
  bit sm = 0;
  bit cr = 0;
  int a = 0;
  wire sirene;
  wire led;
  logic [2:0] S;
  
  
  always #5 clk = ~clk;		// liga o clock
  
  SA alarmev1 (clk, reset, cr, sm, sp, sj, sirene, led);
  
  
  covergroup CG_S @(S);
    coverpoint S
    {
      bins a2[] = {[0:7]};
    }
  endgroup
  
initial
  begin
    $dumpfile("tb.vcd");
    $dumpvars(1,tb);
  end
  
initial
    begin
      
      
      /*-------Lendo as Entradas  <------- */
      
      
      CG_S cg_s_inst = new;
	  cr = 1;
      #1
      cr = 0;
      
      while( (cg_s_inst.get_coverage() < 100) )
         begin
           S = $urandom_range(7,0);
           
           sm = (S & 'h01);
           sp = (S & 'h02) >> 1;
           sj = (S & 'h04) >> 2;
           
           #20
           $display ("CG_S = %.2f%%", cg_s_inst.get_coverage());
           $display ("sm = %d, sp = %d, sj = %d", sm, sp, sj);
           $display("sirene = %d", sirene);
           
           #20
           
           if((sm == 0) && (sp == 0) && (sj == 0)) begin
             if(sirene != 0) begin
               $display("ERRO, nao ta desligada");
               $finish;
             end
           end
           else begin
               if(sirene != 1) begin
                 $display("ERRO, sirene nao ativada");
               	$finish;
               end
           end
           
           
           #100
           sm = 0;
           sp = 0;
           sj = 0;
           reset = 1;
           #1
           reset = 0;
           #10
           cr = 1;
           #1
           cr = 0;
         end
		
      /*---------->	Controle Remoto <---------*/
      
      // resetando
      reset = 1;
      #1
      reset = 0;
      #10
      
      // ligando o controle 
      cr = 1;
      #10
      
      
      //Lendo o sensor da porta
      sp = 1;
      #20
      if(sirene != 1)begin
        $display ("sm = %d, sp = %d, sj = %d", sm, sp, sj);
      	$display("ERRO, sirene nao ativada");
        $finish;
      end
      #20
      
      //desligando o botao
      cr = 0;
      #10
      
      //verificando sirene novamente
      if(sirene != 1)begin
      	$display("ERRO, sirene nao ativada");
        $finish;
      end
      
      // ligando e desligando para colocar em standby
      cr = 1;
      #1
      cr = 0;
      
      #10
      
      //verificando se a sirene desligou
      if(sirene != 0)begin
        $display("ERRO, sirene nao desligou");
        $finish;
      end
      
      
      sp = 0;
     
  	  /*---------->	Teste LED  <---------*/
  
  	// Entrando em standby
      reset = 1;
      #1
      reset = 0;
      #10
      for(int i = 0; i < 20000; i++)
        if(led != 1)begin
          $display("ERRO, Led desligou no standby");
          $finish;
        end
      #10
      $display("led = %d", led);
      cr = 1;
      #1
      cr = 0;
      $display( "FIM" );
      $finish;
        
   end
 
  always @(led)
    begin
      a++;
      $display("led = %d", led);
      if(a == 2)begin
        a = 0;
        sp = 1;
      end
      else
        begin
          reset = 1;
          #1
          reset = 0;
          #10
          cr = 1;
          #10
          cr = 0;
        end
    end
endmodule 

