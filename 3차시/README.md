## 다항식

- $a*x^e$
  - a =계수(coefficient)
  - x = 변수(variable)
  - e =지수(exponent)

## 다항식 ADT

- object
  - p(x) = a1 *x^e1 + a2* x^e2 + ... + an * x^en
  - **<e, a>** : 지수(exponent), 계수(coefficient)의 순서쌍
- functions
  - Polynomial `ZeroP()` : return p(X)=0
  - Boolean `IsZeroP(poly)` : if (poly) return FALSE else return TRUE
  - Coefficient `coef(poly, expon)` : if (expon ∈ poly) return its coefficient else return 0
  - Exponent `leadExp(poly)` : return the largest exponent in poly
  - Polynomial `attach(poly, coef, expon)` **if** (expon ∈ p) **return** error **else** **return** 삽입된 poly
  - Polynomial `Remove(poly, expon)` **if** (expon ∈ p) **return** 삭제된 poly **else** **return** error
  - Polynomial `singleMult(poly, coef, expon)` **return** $poly *coef* x^expon$
  - Polynomial `Add(poly1, poly2)` **return** poly1 + poly2
  - Polynomial `Mult(poly2, poly2)` **return** poly1 * poly2

## 표현방법

1. i번째 배열에 지수가 i인 항의 계수에 대한 값 저장

   * ex) $10x^5 + 6x$

   * | index | 0    | 1    | 2    | 3    | 4    | 5    |
     | ----- | ---- | ---- | ---- | ---- | ---- | ---- |
     | coef  | 0    | 6    | 0    | 0    | 0    | 10   |

   * ```c
     #include <stdio.h>
     #include <stdlib.h>
     #define MAX_DEGREE 101
     typedef struct{
         int degree;
         int coef[MAX_DEGREE];
     }
     
     polynominal a={0};
     a.degree = 5;
     a.coef[1] = 6;
     a.coef[5] = 10;
     
     ```

2. 지수와 계수가 존재하는 항만 배열로 저장

   * ex) $10x^5 + 6x+3$

   * | index | 0    | 1    | 2    | 3    | 4    | 5    |
     | ----- | ---- | ---- | ---- | ---- | ---- | ---- |
     | coef  | 10   | 6    | 3    |      |      |      |
     | exp   | 5    | 1    | 0    |      |      |      |

   * ```c
     #define MAX_TERMS 100 
     typedef struct {
     float coef;
     int expon;
     } polynomial;
     
     polynomial terms[MAX_TERMS];
     int avail = 0;
     
     
     ```

   * 



## Sparse Matrices ADT





## Stack ADT





