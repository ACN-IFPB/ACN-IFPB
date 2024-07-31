//Módulo registrador

module reg_paral_serial(Q,SS,I,E,CL,ES,CK);
	
	input E,CL,CK,ES;
	input [3:0] I;
	output SS;
	output [2:0] Q;
	
	wire x1,x2,x3,x4,x5,x6,x7;
	
	
	mux2p1 M1 (x1, I[3], ES, E);
	FF_JK F1 (Q[0],x1,~x1,CL,CK);
	
	mux2p1 M2 (x3, I[2], Q[0], E);
	FF_JK F2 (Q[1],x3,~x3,CL,CK);
	
	mux2p1 M3 (x5, I[1], Q[1], E);
	FF_JK F3 (Q[2],x5,~x5,CL,CK);
	
	mux2p1 M4 (x7, I[0], Q[2], E);
	FF_JK F4 (SS,x7,~x7,CL,CK);
	
endmodule 

