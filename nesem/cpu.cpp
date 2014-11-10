namespace CPU{
#define CPU_FLAG_C (1 << 0)
#define CPU_FLAG_Z (1 << 1)
#define CPU_FLAG_I (1 << 2)
#define CPU_FLAG_D (1 << 3)
#define CPU_FLAG_B (1 << 4)
#define CPU_FLAG_V (1 << 6)
#define CPU_FLAG_N (1 << 7)
	class Cpu {
		inline unsigned decode_base64(char x) {
			return ( x >= 'A' && x <= 'Z') ? (x - 'A' + 0)
				: (x >= 'a' && x <= 'z') ? (x - 'a' + 26)
				: (x >= '0' && x <= '9') ? (x - '0' + 52)
				: (x == '+') ? 62 : 63;
		}

		void Do(unsigned opcode) {
			//unsigned index = opcode / 6;
			//unsigned bitmask = 1 << (opcode % 6);

#define test(pattern) if (decode_base64(pattern[opcode / 6]) & (1 << (opcode % 6)))
			test("DAAAAAAAAAA") a = x + y;
		}
		/* addressing modes:
		ZeroPage (direct) - accesses memory locations from $0000 to $00FF 
		Implied (1 byte instruction)
		Absolute (3 bytes)
			Absolute mode is a general-purpose mode. Branch instructions use a signed 
			8-bit offset relative to the instruction after the branch; the numerical 
			range -128..127 therefore translates to 128 bytes backward and 127 bytes 
			forward from the instruction following the branch (which is 126 bytes 
			backward and 129 bytes forward from the start of the branch instruction)
		Indexed absolute (3 bytes)
		Indexed zeropage (2bytes)
		relative (2bytes)
		accumulator(1byte)
			 Accumulator mode uses the accumulator as an effective address, and 
			 does not need any operand data.
		indirect,x and indirect,y (2bytes)
		immediate(2bytes)
			Immediate mode uses an 8-bit literal operand.
		*/
		unsigned 
			a, // accumulator
			x,y, // index registers
			p, // status register
			s; // stack pointer,  address range $0100–$01FF (256–511).
		unsigned __int16 pc; // program counter
		const unsigned __int8
			_C = CPU_FLAG_C, // carry flag
			_Z = CPU_FLAG_Z, // zero flag
			_I = CPU_FLAG_I, // interrupt disable
			_D = CPU_FLAG_D, // decimal mode flag
			_B = CPU_FLAG_B, // break command
			_V = CPU_FLAG_V, // overflow flag
			_N = CPU_FLAG_N; // negative flag


	};

}