// detector de estouro

module detector_estouro(e,a3,z3,s3);

	input a3,z3,s3;
	output e;
	
	wire f1,f2;
	
	assign f1 = (~a3)&(~z3)&(s3);
	assign f2 = (a3)&(z3)&(~s3);
	
	assign e = f1|f2;
	
endmodule 