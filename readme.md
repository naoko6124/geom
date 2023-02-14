# geom file format

## header

the header is constitued by 16 bytes divided in 4 sections of 4 bytes
- the first is supposed to be 0x47 0x45 0x4F 0x4D which stands for GEOM in ASCII
- the second is supposed to be 0x00 0x00 0x00 x01 which is the current version of geom
- the third is the offset of the data buffer
- the last one is the length of the data buffer

| 0x47 | 0x45 | 0x4F | 0x4D |
| ---- | ---- | ---- | ---- |
| G    | E    | O    | M    |

| 0x00 | 0x00 | 0x00 | 0x01 |
| ---- | ---- | ---- | ---- |
| 0    | 0    | 0    | 1    |

| 0x30 | 0x00 | 0x00 | 0x00 |
| ---- | ---- | ---- | ---- |
| 48   | 0    | 0    | 0    |

| 0x98 | 0x00 | 0x00 | 0x00 |
| ---- | ---- | ---- | ---- |
| 144  | 0    | 0    | 0    |

## info

the info section is a sequence of 16 bytes per data
- the first eight are the type which can be either VERTEX or INDEX
- the next 8 bytes are the offset and the the length of the respective buffer, 4 bytes each.

| 0x56 | 0x45 | 0x52 | 0x54 | 0x45 | 0x58 | 0x20 | 0x20 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| V    | E    | R    | T    | E    | X    |      |      |

| 0x30 | 0x00 | 0x00 | 0x00 | 0x80 | 0x00 | 0x00 | 0x00 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 48   | 0    | 0    | 0    | 128  | 0    | 0    | 0    |

| 0x49 | 0x4E | 0x44 | 0x45 | 0x58 | 0x20 | 0x20 | 0x20 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| I    | N    | D    | E    | X    |      |      |      |

| 0xB0 | 0x00 | 0x00 | 0x00 | 0x18 | 0x00 | 0x00 | 0x00 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 176  | 0    | 0    | 0    | 24   | 0    | 0    | 0    |

## buffer

the buffer is the last section of the file and is the raw data in bytes defined in the info section