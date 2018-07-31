Overview:
	Two distinct large primes p, q

	One modulus n = p * q
	Positive whole numbers a, n, and e
	Given a, n, and e with 0 < a < n and e > 1
Symbols

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\phi" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\phi" title="\phi" /></a> Euler's totient


Formulas:

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;n&space;=&space;pq" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;n&space;=&space;pq" title="n = pq" /></a> Calculate the modulus

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\phi&space;n&space;=&space;(q&space;-&space;1)(p&space;-&space;1)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\phi&space;n&space;=&space;(q&space;-&space;1)(p&space;-&space;1)" title="\phi n = (q - 1)(p - 1)" /></a> Proof for totient

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;a^{e}&space;(mod&space;n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;a^{e}&space;(mod&space;n)" title="a^{e} (mod n)" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;d&space;=&space;e&space;mod&space;\phi(n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;d&space;=&space;e&space;mod&space;\phi(n)" title="d = e mod \phi(n)" /></a>

Procedure

	1.) Key generation
		a.) Generate distinct primes p and q and let n = pq
		b.) Calculate d as the multiplicative inverse of e mod m using the extended Euclidean algorithm.
	
	2.)