//----------------------------------------------------------------
// Módulos de entradas e saídas para a placa ALTERA DE2
//----------------------------------------------------------------
//
module Mod_test (
			////////////// Fonte de clock ////////////////////
			CLOCK_27,	//27MHz
			CLOCK_50,	//50MHz
			////////////// Push Button	////////////////////
			KEY,				//Pushbutton[3:0]
			////////////// Chaves DPDT	////////////////////
			SW,				//Toogle switch [17:0]
			////////////// Display de 7 segmentos	////////////////////
			HEX0,				//Display 0
			HEX1,				//Display 1
			HEX2,				//Display 2
			HEX3,				//Display 3
			HEX4,				//Display 4
			HEX5,				//Display 5
			HEX6,				//Display 6
			HEX7,				//Display 7
			////////////// LED	////////////////////
			LEDG,				//Led green [8:0] 
			LEDR,				//Led red [17:0] 
);

input CLOCK_27;
input CLOCK_50;

input [3:0] KEY;
input [17:0] SW;

output [6:0] HEX0;
output [6:0] HEX1;
output [6:0] HEX2;
output [6:0] HEX3;
output [6:0] HEX4;
output [6:0] HEX5;
output [6:0] HEX6;
output [6:0] HEX7;

output [8:0] LEDG;
output [17:0] LEDR;

//----------------------------------------------------------------
// Trecho para instanciaçao de módulos e interligação entre eles
//----------------------------------------------------------------
//

wire ck, clr,sel;
wire [3:0] a,i;

assign i [3:0] = SW[3:0];

assign sel = SW[5];
assign clr = SW[6];
assign ck = SW[8];

cont_anel_4bits(a,ck,clr,sel,i)

assign LEDR[3:0] = a [3:0];


//------------------------------------------------------------------------
// Fim do trecho para instanciaçao de módulos e interligaçao entre eles
//------------------------------------------------------------------------

endmodule 



