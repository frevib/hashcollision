# Morse code hash collision detector

## What is this?

This small tool converts the binary morse code equivalent of every letter of the alphabet into an number. This number can be used as an index for a table.

## Why do you need this?

If you are trying the morse code challenge, this tool calculates the time needed to "hash" the binary morse code alphabet into an index number for your table.

## Usage

Edit this part of charindex.cpp:

```
int hashme(char* morse) {
	int total = 0;
	
	// This is the algorithm!!
	for(int i=0; morse[i]; i++) {
		total += ((morse[i] - '0') * (i+2) * i);
	}
	return total;
}
```

Under '//This is the algorithm!!', change to your desired morse code-to-index number algorithm. Then run:

```
make
```
and run the program:
```
./charindex
```

## Example
```
./charindex
```

output:
```
Time hashing: 1.47802
collissions: 2
Collision nr's: 64,64,
collision char nr's: o,w,w,o,
min number: 3
max number: 93
```
