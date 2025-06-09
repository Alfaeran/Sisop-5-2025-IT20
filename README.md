# Sisop-5-2025-IT-Template

## Kelompok

Nama | NRP
--- | ---
Mey Rosalina | 5027241004
Rizqi Akbar Sukirman Putra | 5027241044
M. Alfaeran Auriga Ruswandi | 5027241115

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan
**kernel.asm**

```_getBiosTick```
Mengambil jumlah tick BIOS sejak sistem dinyalakan menggunakan interrupt 0x1A. Nilai DX:CX menyimpan total tick 18.2 per detik.

```
_getBiosTick:
  mov ah, 0x00
  int 0x1A
  mov ax, dx
  mov dx, cx
  ret
```

Hasilnya dipindahkan ke AX dan DX sebelum keluar dengan ret.

```_putInMemory```
Memasukkan karakter (char) ke alamat memori tertentu (untuk menulis ke video memory 0xB800).

```
_putInMemory:
	push bp
	mov bp,sp
	push ds
	mov ax,[bp+4]
	mov si,[bp+6]
	mov cl,[bp+8]
	mov ds,ax
	mov [si],cl
	pop ds
	pop bp
	ret

```

```_interrupt```
Memanggil int dari C ke assembly.

Parameter:

- int number

- AX, BX, CX, DX

```
_interrupt:
	push bp
	mov bp,sp
	mov ax,[bp+4]  //number
	push ds
	mov bx,cs
	mov ds,bx
	mov si,intr
	mov [si+1],al
	pop ds
	mov ax,[bp+6]
	mov bx,[bp+8]
	mov cx,[bp+10]
	mov dx,[bp+12]

intr:	int 0x00 //akan diganti nilainya dengan number

	mov ah,0
	pop bp
	ret
```

**kernel.c**

```printString(char *str)```
Menampilkan string ke layar satu per satu karakter via interrupt video 0x10, mode 0x0E.
```
void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E00 + str[i], 0, 0, 0);
        i++;
    }
}
```

```readString(char *buf)```
Membaca input dari keyboard hingga Enter. Menangani Backspace juga, mencetak karakter saat diketik.
```
void readString(char *buf) {
    char c;
    int i = 0;

    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0);
        if (c == 13) { // Enter
            buf[i] = '\0';
            printString("\r\n");
            break;
        } else if (c == 8) { // Backspace
            if (i > 0) {
                i--;
                printString("\b \b");
            }
        } else {
            buf[i++] = c;
            interrupt(0x10, 0x0E00 + c, 0, 0, 0);
        }
    }
}
```

```clearScreen()```
Membersihkan layar video memory (0xB800) dengan spasi ' ' dan warna default 0x07 (abu-abu).
```
void clearScreen() {
    int i;
    for (i = 0; i < 25 * 80; i++) {
        putInMemory(0xB800, i * 2, ' ');
        putInMemory(0xB800, i * 2 + 1, 0x07);
    }
}
```

**shell.c**

```user```, ```hostname```, ```username```: Untuk menampilkan prompt seperti user@Storm> .

```currentColor```: Menyimpan warna teks aktif.

Fungsi Utama:

```updateUsername()```
Menggabungkan ```user``` + ```hostname``` ke username.

```randomAnswer()```
Jawaban acak berdasarkan ```getBiosTick() % 3```.

```shell() ...```
Loop utama shell:

- Mencetak prompt, kemudian membaca input ke buffer ```yo```

- Parse jadi ```cmd```, ```arg[0]```, ```arg[1]```

 akan mengecek perintah seperti:

- ```yo```, ```gurt```, ```yogurt```: respons humor

- ```user```: ubah nama user

- ```grandcompany```: ubah warna + hostname (```maelstrom```, ```twinadder```, ```immortalflames```)

- ```clear```: bersihkan layar + reset warna

- ```add```, ```sub```, ```mul```, ```div```: operasi aritmatika

- Unknown command: tampilkan kembali input

Fungsi warna:

- ```setColorRed()``` → 0x04

- ```setColorYellow()``` → 0x0E

- ```setColorBlue()``` → 0x01

- ```resetColor()``` → 0x07

```parseCommand(char *yo, char *cmd, char arg[2][64])```
Memisahkan input string ke cmd dan maksimal 2 argumen. Menggunakan spasi sebagai delimiter.

**Headers**

```std_type.h```
Definisi tipe: ```byte```, ```bool```

Konstanta: true, false

```std_lib.h```
Deklarasi fungsi utilitas:

- ```div```, ```mod```: pembagian & modulo

- ```strcmp```, ```strcpy```, ```clear```

- ```atoi```, ```itoa```: konversi antara string dan integer

```kernel.h```
Deklarasi fungsi dan eksternal untuk Assembly seperti ```putInMemory```, ```interrupt```, ```getBiosTick```.

```shell.h```
Deklarasi untuk shell, parseCommand, dan pengatur warna.

**Makefile**

```prepare```:           → Buat folder bin/

```bootloader```:        → Compile bootloader.asm → binary

```stdlib```:            → Compile std_lib.c → object

```shell```:            → Compile shell.c → object

```kernel```:           → Compile kernel.c + kernel.asm → object

```link```:             → Link semua object → kernel.bin lalu gabung bootloader

```build```:            → Shortcut: build seluruh OS

```
prepare:
	mkdir -p bin

bootloader:
	nasm src/bootloader.asm -f bin -o bin/bootloader

stdlib:
	i386-elf-gcc -m32 -ffreestanding -c src/std_lib.c -o bin/std_lib.o

shell:
	i386-elf-gcc -m32 -ffreestanding -c src/shell.c -o bin/shell.o

kernel:
	i386-elf-gcc -m32 -ffreestanding -c src/kernel.c -o bin/kernel.o
	nasm src/kernel.asm -f elf -o bin/kernelasm.o

link:
	i386-elf-ld -m elf_i386 -Ttext 0x1000 -o bin/kernel.bin bin/kernel.o bin/std_lib.o bin/shell.o bin/kernelasm.o --oformat binary
	cat bin/bootloader bin/kernel.bin > bin/os-image

build: prepare bootloader stdlib shell kernel link
```

