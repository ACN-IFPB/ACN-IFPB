/*
include "cont-dec.sv"
include "mux.sv"
include "controle.sv"
include "cont_BCD.sv"
include "reg_DecodeDisplay.sv"
*/
module freq(clk_sistema_100k, reset_sistema, sel_sistema, clk_desc, bcd_3_bus, bcd_2_bus, bcd_1_bus, bcd_0_bus );

  	input clk_sistema_100k, reset_sistema, clk_desc; 
  	input [2:0] sel_sistema;
  	output wire [6:0] bcd_3_bus, bcd_2_bus, bcd_1_bus, bcd_0_bus;
  
  	wire clk_1, clk_10, clk_100, clk_1k, clk_10K;
  	wire clk_controle;
  	wire limp_s, hab_s, arm_s;
 	wire [3:0] cont_3_bus, cont_2_bus, cont_1_bus, cont_0_bus;
  
	contDec contDec_10K(.clk_in(clk_sistema_100k), .reset(reset_sistema), .clk_out(clk_10k));
	contDec contDec_1K (.clk_in(clk_10k), .reset(reset_sistema), .clk_out(clk_1k));  
	contDec contDec_100(.clk_in(clk_1k), .reset(reset_sistema), .clk_out(clk_100));  
	contDec contDec_10 (.clk_in(clk_100),.reset(reset_sistema), .clk_out(clk_10));
  	contDec contDec_1  (.clk_in(clk_10), .reset(reset_sistema), .clk_out(clk_1));
  
  	mux mux_my (.sel(sel_sistema), .in_0(clk_1), .in_1(clk_10), .in_2(clk_100), .in_3(clk_1k), .in_4(clk_10k), .in_5(clk_sistema_100k), .out_mux(clk_controle));
  

 	temp_controle controle_my (.clk_controle(clk_controle), .reset(reset_sistema), .arm(arm_s), .limp(limp_s), .hab(hab_s));

  	cont_BCD cont_BCD_my(.clk_amostra(clk_desc), 
              .reset(reset_sistema), 
              .limp(limp_s), 
              .hab(hab_s), 
              .cont_3(cont_3_bus), 
              .cont_2(cont_2_bus), 
              .cont_1(cont_1_bus), 
              .cont_0(cont_0_bus));  
  
  	reg_DecodeDisplay reg_DecodeDisplay_my (.reset(reset_sistema), 
                       .arm(arm_s), 
                       .cont_3(cont_3_bus), 
                       .cont_2(cont_2_bus), 
                       .cont_1(cont_1_bus), 
                       .cont_0(cont_0_bus), 
                       .bcd_3(bcd_3_bus), 
                       .bcd_2(bcd_2_bus), 
                       .bcd_1(bcd_1_bus), 
                       .bcd_0(bcd_0_bus));
  
endmodule