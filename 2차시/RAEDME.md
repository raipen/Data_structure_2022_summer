# 자료구조 스터디 2차시(배열과 구조들)



## Data structure

* Data structure ≡ data type + storage structure
* Data type
  * How to categorize data objects
  * Object + operator
* Abstract Data Type (ADT)
  * Specification of objects and operations independent of their implementation

***Performance of a program largely depends on data structures !!***



## Abstarct Data Type(ADT) of Array

> ADT array is
>
> objects:
>
> ​	A set of pairs <index, value> where for each value of index there is a value from the set item. Index is a finite ordered set of one or more dimensions, for example, {0, · · · , n-1} for one dimension, {(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1 ), (2, 2)} for two dimensions, etc.
>
> functions:
>
> ​	for all A ∈ Array, i ∈ index, x ∈ item, j, size ∈ integer
>
> ​	Array Create(j, list) ::= **return** an array of j dimensions where list is a j-tuple whose ith element is the the size of the ith dimension. *Items* are undefined. 
> ​	Item Retrieve(A, i) ::= **if** (i E index) **return** the item associated with index value i in array A **else** **return** error
>
> ​	Array Store(A,i,x) ::= **if** (i in index) **return** an array that is identical to array A except the new pair <i, x> has been inserted **else return** error.

* A set of pairs <index, value>
* ADT for array provides operations that
  * retrieves a value
  * stores a value

## Array in C

### 1D array

![image-20220708045502797](img\image-20220708045502797.png)

* map into configuous memory locations

* location(array[i]) = start + i

``` c
int main(void){
    int i,*list,list2[5] = {0,1,2,3,4}; list1 = list2; //declaration
    printf(list2 == &list2[0] ? "true\n" : "false");
    scanf("%d",&i);
    printf(list2 + i == &list1[i]  ? "true\n" : "false");
    scanf("%d",&i);
    printf(*(list1+i) == list2[i] ? "true\n" : "false");
}
```

* |                    | **list1**                                                    | **list2**                                                    |
  | ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | **정의**           | pointer                                                      | array name                                                   |
  | **공통점**         | 둘 다 정수를 가리키는 포인터                                 | 둘 다 정수를 가리키는 포인터                                 |
  | **주소 값의 변경** |                                                              | 불가능(++ 불가능)(5개 정수를 위한 메모리 위치가 예약되어 있다. |
  | **기타**           | (int *list1 = list2) 포인터 변수가 배열을 참조하면 포인터 변수를 배열처럼 사용할 수 있다. |                                                              |

```c
#include <stdio.h>

void print1(int*, int);

void main(){  
 int one[] = { 0, 1, 2, 3, 4};
 int size = _____________________;
 print1Darry(____,____);
}

void print1(int *ptr, int row){
	/* print out a one-dimensional array using a pointer */
	int i;
	printf("Address Contents\n");
    for (i=0; i<row; i++)
    printf("%8u%5d\n", ptr+i, *(ptr+i) );
    printf("\n");
}
```

<details>
	<summary>정답보기/가리기</summary>


```c
void main(){	
	int one[] = { 0, 1, 2, 3, 4};
	int size = sizeof(one)/sizeof(int);
	print1Darry(one,size);
}
```
</details>

