# Lab 8: Martin Kováč

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-: | :-: |
   | `add r24, r0` | `0b0000_1101_1000_0000` | `0x0D80` | `0x800D` |
   | `com r26` | `0b1001_0101_1010_0000` | `0x95A0` | `0x0A95` |
   | `eor r26, r27` | `0b0010_0111_1010_1011` | `0x27AB` | `0x72AB` |
   | `mul r22, r20` | `0b1001_1111_0110_0100` | `0x9F64` | `0x649F` |
   | `ret` | `0b1001_0101_0000_1000` | `0x9508` | `0x0895` |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 0 1 3 7 14 13 11 6 12 9 2 5 10 4 8 | 15 |
   | 4, 2 | 0 1 3 6 12 8 | 6 |
   | 4, 1 | 0 1 2 5 10 4 9 3 6 13 11 7 14 12 8 | 15 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![IMG_4616](https://user-images.githubusercontent.com/99388246/203418096-d6b3ec6f-cbbb-482d-be95-da8e28b85589.jpg)
