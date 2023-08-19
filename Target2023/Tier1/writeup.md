**Hey there, this writeup summarises my approach and flags obtained in the Target CTF Tier 1 challenge.**

# Cryptography/ Steganography Challenges

## Challenge 1: Beware the Ides of March

The following ciphertext was to be decrypted:

`GUR GNETRG UNF ORRA NPDHVERQ`

First instinct was to check for ROT 13 cipher on cyber chef. 

**Flag obtained was `THE TARGET HAS BEEN ACQUIRED`**

## Challenge 2: Now you see me, now you don't

The challenge had this intro and an image attached, as follows:

```markdown
You have intercepted a email sent between Bob and Alice, who we believe to be members of Shiny Scorpion. See a transcription of the message below:
Hi Bob,
Our good friend Vigenère is looking to follow up on the financial reports you're working on. Can you give me a timeline on when you think they would be ready to share out?
Best, Alice
There doesn't look to be anything malicious in the email, but the embedded photo in the email hit the automated threat detection. Can you find the true message of the email?
```
![scorpion image](email_scorpion.jpg)

The mail had a clue, stating friend "vigenere" which made me think this cipher will definitely be handy somewhere ahead in the challenge. On examining the image with a custom script for steganography yields the following text hidden within image:

`KaierljsipvgbediecsvhrrscaEvvqyq`

This is where I decide to try using Vigenere cipher. The key for this isnt provided and an educated guess leads to trying scoprion, shinyscorpion. The latter `shinyscorpion` ends up being this key and leads to the flag.

script used: [a relative link](steg.py)

**Flag obtained was `StarttheransomwareattackonMonday`**



## Challenge 3: A Snowy Disposition

This challenge had a text file attached to it, which was a poem. On running basic file scans no embedded steganography text or image was found. But checking in a text editor revealed a bunch of whitespaces. This made me check for any steganography trick for whitespaces and then I came across whitespace / snow steganography. 
On counting the whitespaces on each line, the following sequence was obtained:

`0, 1 , 0 , 81 , 85 , 49 , 88 , 48 , 84 , 49 , 67 , 65 , 76 , 76 , 89`

Converting each of these digits to their equivalent ascii characters lead to the flag.

**Flag obtained was `QU1X0T1CALLY`.**

## Challenge 4: Follow the Dotted Line

This challenge had the following message attached:

```markdown
.--.- --... --.-- -...- -.-.- ----- -..-- -.---
Labor Day sale!
You won't want to miss this! We're putting on our biggest Labor Day sale yet.
Mark your calendars to bring home the bacon with these unbelievable savings!
.---. -.--- -..-- -...- -.-.- ----- ---.- --.--
```
My initial guess on observing the border was looking for morse code encrypted message, which sure was misleading after a few tries. That's when re-reading the message gave "bacon" as a lead. On searching for such ciphers came across baconian cipher. Next step was to substitute the dots and dashes for As and Bs as follows:
` A = '.'` and `B = '-'`
encoding this pattern leads to the following ciphertext:

```markdown
BAABA AABBB AABAA ABBBA ABABA AAAAA ABBAA ABAAA
BAAAB ABAAA ABBAA ABBBA ABABA AAAAA AAABA AABAA
```
On decoding this text using cyber chef lead to the flag.

**Flag obtained was `The plan is in place`**

## Challenge 5: A Particular Exchange

This challenge consisted of a mail intercepted and displayed and the goal was to decode a secret. The mail read as follows:

```markdown
Hi Bob,
 As you may have heard from Director Diffie-Hellman, there is going to be a party
 to support inter team communication. Can you arrange to have nine orders of papaya salad, seven orders of the
 grape pastries, six dozen apples, and eight loaves of banana bread?

 Thanks,
 Alice
```
The order had numbers mentioned and director's name gave off an obvious clue - get the diffie-hellman parameters and figure out the session key being used.
in this case the parameters guessed were in this order:

`P = 9 , G = 7 , a = 6 , b = 8`

On solving for session key:

```
A = g^a mod p = 76 mod 9 = 1
B = g^b mod p = 78 mod 9 = 4

keya = B^a mod p = 4^6 mod 9 = 1
keyb = A^b mod p = 1^8 mod 9 = 1
```

**Flag obtained was `1`**