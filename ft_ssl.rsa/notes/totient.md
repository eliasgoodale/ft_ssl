Euler's totient function: 
	for "the multitude of numbers less than D,
	and which have no common divisor with it"

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\phi(n)=&space;n\prod_{\substack{p&space;\text{&space;prime&space;}\&space;p&space;\vert&space;n}}&space;\left(&space;1-&space;\frac{1}{p}\right)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\phi(n)=&space;n\prod_{\substack{p&space;\text{&space;prime&space;}\&space;p&space;\vert&space;n}}&space;\left(&space;1-&space;\frac{1}{p}\right)" title="\phi(n)= n\prod_{\substack{p \text{ prime }\ p \vert n}} \left( 1- \frac{1}{p}\right)" /></a>

Counts the positive integers(k) up to a given integer n 
that are relatively prime(gcd(k, n) = 1) to n. Denoted by φ or Φ,
the k's are referred as totatives of n.

Example, the totient of 36 is 12, because,

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\phi(36)&space;=&space;\phi(2^{3}3^{2})&space;=&space;36(1&space;-&space;\frac{1}{2})(1&space;-&space;\frac{1}{3})&space;=&space;36&space;*&space;\frac{1}{2}&space;*&space;\frac{2}{3}&space;=&space;12" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\phi(36)&space;=&space;\phi(2^{3}3^{2})&space;=&space;36(1&space;-&space;\frac{1}{2})(1&space;-&space;\frac{1}{3})&space;=&space;36&space;*&space;\frac{1}{2}&space;*&space;\frac{2}{3}&space;=&space;12" title="\phi(36) = \phi(2^{3}3^{2}) = 36(1 - \frac{1}{2})(1 - \frac{1}{3}) = 36 * \frac{1}{2} * \frac{2}{3} = 12" /></a>

This states that the distinct prime factors of 36, 2 and 3, determine that half of numbers up to 36 are divisible by two,
and a third of those are divisible by 3, leaving 12 numbers that
are coprime to 36
