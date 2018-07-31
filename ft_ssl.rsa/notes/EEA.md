# Extended Euclidean Algorithm

## Prerequisites

### Modular Arithmetic

	Introduces a congruence relation on integers compatible with +, -, and *. For unsigned int n, two numbers a and b are said to be congruent modulo n. If their difference (k = a - b) is an integer multiple of n (a - b = kn) the congruence is denoted:

$$a ≡ b (mod\;n)\;\;or\;\;a = kn + b$$ 

	Essentially, a and b have the same remainder when divided by n such that:

$$a = pn + r\;\;,\;\;b = qn + r\;\;\;\;\;\;where,\;\;0\leq r < n$$



$$38 ≡ 14 (mod\;12)$$
$$38 - 14 = 24$$
$$24 = k(12)$$
$$k = 2$$

### Modular Inverse
	A number multiplied by its inverse equals 1:
$A \times \frac{1}{A} = 1$

	A modular inverse of A (mod C) is A⁻¹

$(A \times A^{-1}) ≡ 1(mod\;C)$

Only numbers coprime to C have a modular inverse (mod C)



>Naive Approach: A = 3, C = 7

$$3 * 0 ≡ 0(mod\;7)$$
$$3 * 1 ≡ 3(mod\;7)$$
$$3 * 2 ≡ 6 (mod\;7)$$
$$3 * 3 ≡ 9 ≡ 2 (mod\;7)$$
$$3 * 4 ≡ 12 ≡ 5 (mod\;7)$$
$$->3 * 5 ≡ 15 (mod\;7) ≡ 1 (mod\;7)<-$$

$$3 * 6 ≡ 18 (mod\;7) ≡ 4 (mod\;7)$$

The modular inverse of $A$ mod $C$, is the $(B = 5)$ value that makes $A \times B (mod\;C) = 1$.

### Modular Multiplicative Inverse

	A MMI of an integer, a is an integer x such that the product ax is congruent to 1 with respect to the modulus m.

$$ax ≡ 1 (mod\;m)$$

	This shorthand makes the statement that m evenly divides the quantity ax - 1, or the remainder after dividing ax by the integer m is 1. Any element that is a solution

Computes, in addition to the gcd of integers a and be, the coefficients of Bézout's identity which are integers x and y such that: 


<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;ax&space;&plus;&space;by&space;=&space;gcd(a,&space;b)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;ax&space;&plus;&space;by&space;=&space;gcd(a,&space;b)" title="ax + by = gcd(a, b)" /></a>

## Algorithm

	The Euclidean Algorithm is a recursive technique for quickly finding the GCD of two integers $A \;and\; B$. 

>$if\;A = 0\;\;or\;\;B = 0,\;stop$

>$A = B \cdot Q + R$

>$find\;\;\;GCD(B, R)\;\;\;\;knowing\;\;\;\;GCD(A,B) = GCD(B, R)$

$$Example$$

$$A = 270,\;\;B = 192$$

$$270 = 192 \cdot 1 + 78$$

$$192 = 78 \cdot 2 + 36$$
$$78 = 36 \cdot 2 + 6$$
$$36 = 6 \cdot 6 + 0$$
$$GCD(270, 192) = 6$$

### The proof is derived as follows:
>Given $A - B = C$

$$GCD(A, B) = GCD(A,\; A - B)$$
$$GCD(A, B) \overset!\leq GCD(B,C)$$
$$GCD(A, B) = GCD(B, C) = GCD(B, A - B) = GCD(B, R)$$



	



















Successive quotients and remainders are used in the
extended algorithm. The algorithm starts with integers a and b as inputs and consists of computing a sequence $(q_{1}\;...\;q_{i})$ of quotients and a sequence $(r_{1}\;...\;r_{i+1})$ of remainders such that

$\;\;\;\;r_{0} = a$

$\;\;\;\;r_{1} = b$

$\;\;\;\;\;\;\;\;\;\vdots$

$r_{i + 1} = r_{i - 1} - q_{i}r_{i}\;\;\;\;\;$and$\;\;\;\;\;\;0 \leq r_{i+1} < |r_{i}|$ 

It is the main property of Euclidean division is that inequal

$\;\;\;\;r_{0} = a\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;r_{1} = b$

$\;\;\;\;s_{0} = 1\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;s_{1} = 0$

$\;\;\;\;t_{0} = 0\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;t_{1} = 1$

$\;\;\;\;\;\;\;\;\,\vdots\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\;\vdots$

$r_{i + 1} = r_{i -1} - q_{i}r_{i}\;\;\;\;\;\;$and$\;\;\;\;\;\;\;\;\;\;\;\;\;0 \leq r_{i + 1} < |r_{i}|$

$s_{i + 1} = s_{i -1} - q_{i}s_{i}$

$t_{i+1} = t_{i -1} - q_{i}t_{i}$

$\;\;\;\;\;\;\;\;\vdots$

The computation stops 


 









