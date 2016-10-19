//Gregory Asher
//Michael Su
//Lab 3
//Warning: Must assign weak pull up resistors to GPIO pins: 11, 13, 15, 17, 19, 21, 23, 25.
//				Failure to have these would require pull up resistors hardwired.
module KeypadScanner(

	//////////// CLOCK //////////
	input 		          		CLOCK_50,
	input 		          		CLOCK2_50,
	input 		          		CLOCK3_50,
	input 		          		CLOCK4_50,

	//////////// SEG7 //////////
	output		     [6:0]		HEX0,
	output		     [6:0]		HEX1,
	output		     [6:0]		HEX2,
	output		     [6:0]		HEX3,
	output		     [6:0]		HEX4,
	output		     [6:0]		HEX5,

	//////////// KEY //////////
	input 		     [3:0]		KEY,

	//////////// LED //////////
	output		     [9:0]		LEDR,

	//////////// SW //////////
	input 		     [9:0]		SW,

	//////////// GPIO_0, GPIO_0 connect to GPIO Default //////////
	inout 		    [35:0]		GPIO
);
	//assign reset key
	wire reset = ~KEY[0];
	
	wire [3:0] rawKey;
	
	Scan FourbyFourKeypad(CLOCK_50, {GPIO[25], GPIO[23], GPIO[21], GPIO[19], GPIO[17], GPIO[15], GPIO[13], GPIO[11]} , rawKey, rawValid);
	//assign HEX0 to the key being pressed
	SevenSegment hex0 (rawKey, HEX0, rawValid);

	//asynchronous reset-counter for how many times the key(s) are pressed.
	reg [15:0] counter;
	always@(posedge rawValid, posedge reset)
	begin
		if (reset)
			counter <= 16'b0;	
		else
		counter <= counter + 1;
	end
	wire [3:0] A, B, C, D;//A is most significant D is least
	assign A = counter[15:12];
	assign B = counter[11:8];
	assign C = counter[7:4];
	assign D = counter[3:0];
	//Assign each HEX display to a 4 bit segment of the counter
	//Also suppresses leading zeroes while maintaining non-leading zeroes.
	SevenSegment hex5 (A, HEX5, |A ); 
	SevenSegment hex4 (B, HEX4, ( |B )|( |A ) );
	SevenSegment hex3 (C, HEX3, ( |C )|( |B )|( |A ));
	SevenSegment hex2 (D, HEX2, ( |D )|( |C )|( |B )|( |A ));
	
	//turned off unused display
	SevenSegment hex1 (4'b0000, HEX1, 0); 
endmodule

//Scan
//Inputs: a clock, an 8 bit inout (4x4 Keypad)
//
// Keypad diagram assumption:
//
// 1	2	3	A
// 4	5	6	B
//	7	8	9	C
// E	0	F	D
//
//Outputs: 4 bit reg set to the value of the keypressed
//
module Scan( input CLOCK_50, inout [ 7:0 ] keypad, output reg [ 3:0 ] rawKey, output reg rawValid );
	reg [1:0] selector;
	reg [3:0] columns;
	wire [3:0] rows = keypad[7:4];
	assign keypad[3:0] = columns[3:0];
	
	wire enabled = (&rows);
	
	reg [31:0] clock;
	parameter clockDivisor = 500;
	
	always @( posedge CLOCK_50 )
	begin
	//once every 500 clock cycles
		if ( clock == 0 )
		begin
			clock <= clockDivisor;
			//if all rows are 1's
			if(enabled)
			begin
			//rotate through which column is set to 0
				selector <= selector + 1;
				case (selector)
					0: columns[3:0] <= 4'b0zzz;
					1: columns[3:0] <= 4'bz0zz;
					2: columns[3:0] <= 4'bzz0z;
					3: columns[3:0] <= 4'bzzz0;
				endcase
			end
		end
		else	
		//decrement clock
			clock <= clock - 1;
	end
	always @(*)
	begin			
		rawValid = ~enabled;
		//opting to use hex here to read each case easier.
		casex( {rows, columns} )
				//row 0
				8'b0111_0xxx: rawKey[3:0] = 4'h1;
				8'b0111_x0xx: rawKey[3:0] = 4'h2;
				8'b0111_xx0x: rawKey[3:0] = 4'h3;
				8'b0111_xxx0: rawKey[3:0] = 4'hA;
				//row 1
				8'b1011_0xxx: rawKey[3:0] = 4'h4;
				8'b1011_x0xx: rawKey[3:0] = 4'h5;
				8'b1011_xx0x: rawKey[3:0] = 4'h6;
				8'b1011_xxx0: rawKey[3:0] = 4'hB;
				//row 2
				8'b1101_0xxx: rawKey[3:0] = 4'h7;
				8'b1101_x0xx: rawKey[3:0] = 4'h8;
				8'b1101_xx0x: rawKey[3:0] = 4'h9;
				8'b1101_xxx0: rawKey[3:0] = 4'hC;
				//row 3
				8'b1110_0xxx: rawKey[3:0] = 4'hE;
				8'b1110_x0xx: rawKey[3:0] = 4'h0;
				8'b1110_xx0x: rawKey[3:0] = 4'hF;
				8'b1110_xxx0: rawKey[3:0] = 4'hD;
			endcase
	end
endmodule


module SevenSegment( input [3:0] hexDigit, output [6:0] segments, input active );

	wire b0, b1, b2, b3;
	wire [6:0] s;
     
	assign b0 = hexDigit[0];    
	assign b1 = hexDigit[1];    
	assign b2 = hexDigit[2];    
	assign b3 = hexDigit[3];   
	
	assign s[0] = (b1 & b2 | ~b1 & ~b2 & b3 | ~b0 & b3 | ~b0 & ~b2 | b0 & b2 & ~b3 | b1 & ~b3) & active;  
	assign s[1] = (~b3 & ~b2 | ~b3 & ~b1 & ~b0 | ~b3 & b1 & b0 | ~b2 & b1 & ~b0 | b3 & ~b1 & b0 | b3 & ~b2 & ~b1) & active;
	assign s[2] = (b3 & ~b2 | ~b3 & b2 | ~b1 & b0 | ~b3 & ~b1 | ~b3 & b0) & active;
	assign s[3] = (b3 & ~b1 | b2 & ~b1 & b0 | b3 & ~b2 & b0 | b2 & b1 & ~b0 | ~b3 & ~b2 & b1 | ~b3 & ~b2 & ~b0) & active;
	assign s[4] = (~b2 & ~b0 | b3 & b2 | b1 & ~b0 | b3 & b1 & b0) & active;
	assign s[5] = (~b1 & ~b0 | ~b3 & b2 & ~b1 | b3 & b1 | b2 & b1 & ~b0 | b3 & ~b2) & active;
	assign s[6] = (~b3 & ~b2 & b1 | b1 & ~b0 | b3 & b0 | ~b3 & b2 & ~b1 | b3 & ~b2 & ~b1) & active;
	
	assign segments = ~s;           
	
endmodule