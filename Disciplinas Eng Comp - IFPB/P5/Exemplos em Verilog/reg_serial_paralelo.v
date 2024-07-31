//Módulo reg_serial_paralelo

module reg_serial_paralelo (q,es,clr,ck);
	
	input es, clr,ck;
	output [3:0] q;
	
	FF_D F1 (q[3], es, clr, ck);
	FF_D F2 (q[2], q[3], clr, ck);
	FF_D F3 (q[1], q[2], clr, ck);
	FF_D F4 (q[0], q[1], clr, ck);

endmodule 