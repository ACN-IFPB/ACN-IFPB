//Somador 4bits

module somador_4bits(s,ts,a,b,te);

	input [3:0] a,b;
	input te;
	output [3:0] s;
	output ts;
	
	wire f1,f2,f3;
	somador_completo U1 (s[0],f1,a[0],b[0],te);
	somador_completo U2 (s[1],f2,a[1],b[1],f1);
	somador_completo U3 (s[2],f3,a[2],b[2],f2);
	somador_completo U4 (s[3],ts,a[3],b[3],f3);
	
endmodule 