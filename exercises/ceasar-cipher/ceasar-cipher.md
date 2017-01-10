# Exercise

## Ceasar cipher

The Caesar cipher is a substitution cipher where each letter in the original message (called the plaintext) is replaced with a letter corresponding to a certain number of letters up or down in the alphabet.  The encrypted message (ciphertext) is not easily readable.

For example, here's the Caesar Cipher encryption of a message, using a right shift of 3.

__Plaintext:__  

THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG

__Ciphertext:__ 

QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD

It is straightforward to recover the original message by using the opposite shift.

### Task 

You are asked to write a program that takes a shift value between +/- 26 and a _plaintext_ message (no spaces) and returns the corresponding _ciphertext_.  The program should also implement a decryption routine that reconstructs the original _plaintext_ from the _ciphertext_.

#### Example usage

~~~shell
$ ceasar 3 THE
ciphertext: QEB
plaintext: THE
~~~ 

or

~~~bash
$ ceasar -1 ZZZ
ciphertext: AAA
plaintext: ZZZ
~~~ 

We assume that the user message only consists of uppercase English alphabet (A-Z).

