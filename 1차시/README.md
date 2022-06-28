# 자료구조 스터디 1차시(성능이란?)

자료구조를 공부하는 목적: 더 좋은 성능의 프로그램을 설계하고 개발하기 위함

∴ 자료구조를 공부하기에 앞서 프로그램의 성능을 분석하고 측정하는 방법에 대해 알아야한다.

※ 실제로 이론 시험의 대부분이 여기서 배운 내용을 토대로 나옴



## performance analysis vs performance measurement

* performance measurement

  * machine dependent: running times

  * Measure actual time on an actual computer

  * Use system clock

  * Measure running time in C

    ``` C
    #include <time.h>
    
    int main(void){
    	clock_t start = clock();
    	//do something
        double duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    }
    ```

    ```c
    #include <time.h>
    
    int main(void){
    	time_t start = time(NULL);
    	//do something
        double duration = (double) difftime(time(NULL),start);
    }
    ```

* Performance Analysis
  * Analyzing time and space complexity independent of the machine for the program
    * Time complexity: amount of computation time that a program needs to run to completion
    * Space complexity: amount of memory that a program needs to run to completion

 * Space Complexity

   * S(P) = c + S<sub>p</sub>(n)

     * S(P): space requirement of program P(알고리즘과 무관한 부분까지 포함)

     * c: constant (for fixed space requirements)

       * Fixed part: space independent of the program's input/output size

         - Instruction space

         - space for simple variables
         - fixed-size structured variables
         - constants

     * n : Instance characteristics (ex: I/O size, number)

     * S<sub>p</sub>(n): 알고리즘과 밀접한 부분만

   * ```c
     float abc(float a, float b, float c){
         return a+b+b*c+(a+b-c)/(a+b)+4.00;
     }
     ```

   * S<sub>abc</sub>(n) = 0

   * ```c
     float sum(float list[],int n){
         float tempsum = 0;
         int i;
         for(i=0;i<n;i++)
             tempsum += list[i];
         return tempsum;
     }
     ```

   * S<sub>sum</sub>(n) = n+3

