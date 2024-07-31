module mux2p1 (S, A, I0, I1);
input A, I0, I1;
output S;
wire x, y;

porta_and U1(x,I0,~A);
porta_and U2(y,I1,A);
porta_or U3(S,x,y);

endmodule
