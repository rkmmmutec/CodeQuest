## <u>**Steps involved in developing a C program**</u>

* Program Creation
* Program compilation
* Program Execution



Developing a C program involves several stages, each crucial for transforming human-readable source code into an executable program. Here’s a breakdown of the key steps:

### 1. Program Creation

**Theory:**

- This is the initial phase where the actual C source code is written.
- The code is written using a text editor like vim, visual studio code and saved with a `.c` extension.

**Steps Involved:**

1. Choose a Text Editor:

   - Common text editors include Visual Studio Code, Sublime Text, Notepad++, etc.

2. Write the C Code:

   - Write your C code let say hello.c

     ```c
     #include <stdio.h>
     
     int main() {
         printf("Hello, World!\n");
         return 0;
     }
     ```

     

​	Save the File: with a `.c` extension hello.c.

### 2. Program Compilation

- Compilation is the process of converting the C source code into machine code.
- This involves several stages: preprocessing, compiling, assembling, and linking.

**Steps Involved:**

1. **Preprocessing:**
   - The preprocessor processes directives such as `#include` and `#define`. It handles macro substitutions, file inclusions, and conditional compilations.
   - This step is usually implicit when you compile the program, but the preprocessor can be invoked separately using:

```bash
gcc -E -o hello.c hello.i  //from pre-processed code to assembly code
gcc -E -o hello.i hello.c  // from c _source code to assembly code
```

2. **Compilation:**

- Converts the preprocessed code into assembly code.

```bash
gcc -S hello.i -o hello.s  //AT&T Syntax
gcc -S -o hello.s hello.i
Intel syntax : By using Microsoft Macro Assembler:      (.cfi-startproc):- call frame information
gcc -S -masm=intel -o hello.s hello.c or hello.i   // from c-source code or preprocessed c code
```

3. **Assembly:**

- Translates the assembly code into machine code, resulting in an object file.

- Command:

  ```bash
  gcc -c hello.s -o hello.o
  ```

4. **Linking:**

- Links the object file with necessary libraries to produce an executable.

```bash
gcc hello.o -o hello
```



### 3. Program Execution

**Theory:**

- Execution is the process of running the compiled executable program.

**Steps Involved:**

1. Run the Executable:

   - Execute the compiled program from the command line or terminal.

   - Command:

     ```bash
     ./hello
     ```

### Summary of Commands:

```bash
Preprocessing :    gcc -E hello.c -o hello.i
Compilation   :    gcc -S hello.i -o hello.s
Assembly	  :	   gcc -c hello.s -o hello.o
Linking		  :	   gcc hello.c -o hello
Execution     :    ./hello
```

![image-20240613063138285](/home/cdac/.config/Typora/typora-user-images/image-20240613063138285.png)



![image-20240613063433834](/home/cdac/.config/Typora/typora-user-images/image-20240613063433834.png)

   ![image-20240613063737028](/home/cdac/.config/Typora/typora-user-images/image-20240613063737028.png)

**Intel Syntax: $gcc -S -masm=intel -o hello.S hello.c**

![image-20240615102947352](/home/cdac/.config/Typora/typora-user-images/image-20240615102947352.png)

**AT&T Syntax**

![image-20240615103040164](/home/cdac/.config/Typora/typora-user-images/image-20240615103040164.png)

**Conversion Specification(for printf)**

%c : print a single character
%d %i : print a decimal integer
%u : print an unsigned decimal integer|
%o : print and unsigned octal integer
%x : print an unsigned  hexadecimal integer using a,b,c,d,e,f
%X : print an unsigned hexadecimal integer using A,B,C,D,E,F
%e : print  a floating point number in exponential 

**Reading input data using scanf()**

int num ; scanf("%d",&num);

char ch; scanf("%c",&ch);

float a; scanf("%f",&a);

char str[20]; scanf("%s",str); //str is not preceded by ampersand(&) sign

**Format for integer input **

%wd : scanf("%2d%3d",&a,&b);  

* when input data is less than or equal to the given field width, the input values are unaltered and stored in given variables
* when input data length is more than the given gield width, the input values are altered in the variable : Input - 269 3845 , 
  26 is stored in and 9 is stored in b.

**Format for integer output**

**Format for floating point numeric input**

scanf("%3f%4f",&x,&y);  

* when input data length is less than or equal to  the given width values are unaltered and stored in the variable
* when i/p data > width , e.g i/p : 5.93 65.875 : 5.9 is stored in x and 3.00 is stored in y

**Format for floating point numeric output**

printf("x=%4.1f,y=7.2f",x,y);
value of variable : 8 5.9 
output : x=8.0 y=5.90, 

value of variable : 25.3 1635.92
output : 25.3 1635.92

value of variable : 15.231 65.875948
output : 15.2 65.88

**Suppression character in scanf**

To skip any input field, we can specify * between the % sign and the conversion specification.
**scanf("%d*d%d",&a,&b,&c);** // The input field is read but its value is not assigned to any address.

e.g i/p : 10 11 12 , a=10,b=12 // No data is available in c (garbage)

**Character I/O**

getchar() and putchar