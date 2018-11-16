# Theory of Computation Sprint Challenge

## State Machines

> A useful tool for drawing state machines is [Evan's FSM
> Designer](http://madebyevan.com/fsm/).

- The VT-100 terminal (console) outputs text to the screen as it
  receives it over the wire. One exception is that when it receives an
  ESC character (ASCII 27), it goes into a special mode where it looks
  for commands to change its behavior. For example:

      ESC[12;45f

  moves the cursor to line 12, column 45.

      ESC[1m

  changes the font to bold.

  - Draw a state machine diagram for a VT-100 that can consume regular
    character sequences as well as the two above ESC sequences.

> If you're curious, [here are all the VT-100 escape
> sequences](http://ascii-table.com/ansi-escape-sequences-vt-100.php).
> More common these days is a superset of VT-100 called [ANSI escape
> sequences](http://ascii-table.com/ansi-escape-sequences.php). If
> you've ever put colors and stuff in your Bash prompt, this is what you
> used to do it.
>
> One of your instructors was once hired to implement VT-100 emulation
> in an app, and they used a state machine to do it.

![<?xml version="1.0" standalone="no"?>

<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="43.5" cy="48.5" rx="30" ry="30"/>
	<text x="26.5" y="54.5" font-family="Times New Roman" font-size="20">start</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="345.5" cy="48.5" rx="30" ry="30"/>
	<text x="328.5" y="54.5" font-family="Times New Roman" font-size="20">text </text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="204.5" cy="195.5" rx="30" ry="30"/>
	<text x="183.5" y="201.5" font-family="Times New Roman" font-size="20">ESC </text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="363.5" cy="195.5" rx="30" ry="30"/>
	<text x="341.5" y="201.5" font-family="Times New Roman" font-size="20">ESC[</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="529.5" cy="195.5" rx="30" ry="30"/>
	<text x="502.5" y="201.5" font-family="Times New Roman" font-size="20">ESC[1</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="709.5" cy="195.5" rx="30" ry="30"/>
	<text x="677.5" y="201.5" font-family="Times New Roman" font-size="20">ESC[12</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="709.5" cy="355.5" rx="30" ry="30"/>
	<text x="675.5" y="361.5" font-family="Times New Roman" font-size="20">ESC[12;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="742.5" cy="69.5" rx="30" ry="30"/>
	<text x="702.5" y="75.5" font-family="Times New Roman" font-size="20">Bold Font</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="557.5" cy="433.5" rx="30" ry="30"/>
	<text x="518.5" y="439.5" font-family="Times New Roman" font-size="20">ESC[12;4</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="405.5" cy="339.5" rx="30" ry="30"/>
	<text x="361.5" y="345.5" font-family="Times New Roman" font-size="20">ESC[12;45</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="181.5" cy="472.5" rx="30" ry="30"/>
	<text x="27.5" y="478.5" font-family="Times New Roman" font-size="20">moves the cursor to line 12 column 45</text>
	<polygon stroke="black" stroke-width="1" points="73.5,48.5 315.5,48.5"/>
	<polygon fill="black" stroke-width="1" points="315.5,48.5 307.5,43.5 307.5,53.5"/>
	<text x="130.5" y="69.5" font-family="Times New Roman" font-size="20">regular char seq</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 372.297,35.275 A 22.5,22.5 0 1 1 372.297,61.725"/>
	<text x="418.5" y="54.5" font-family="Times New Roman" font-size="20">regular character sequence</text>
	<polygon fill="black" stroke-width="1" points="372.297,61.725 375.83,70.473 381.708,62.382"/>
	<polygon stroke="black" stroke-width="1" points="65.655,68.728 182.345,175.272"/>
	<polygon fill="black" stroke-width="1" points="182.345,175.272 179.809,166.185 173.066,173.57"/>
	<text x="42.5" y="142.5" font-family="Times New Roman" font-size="20">ESC char</text>
	<polygon stroke="black" stroke-width="1" points="324.733,70.15 225.267,173.85"/>
	<polygon fill="black" stroke-width="1" points="225.267,173.85 234.413,171.537 227.196,164.615"/>
	<text x="193.5" y="113.5" font-family="Times New Roman" font-size="20">ESC char</text>
	<polygon stroke="black" stroke-width="1" points="234.5,195.5 333.5,195.5"/>
	<polygon fill="black" stroke-width="1" points="333.5,195.5 325.5,190.5 325.5,200.5"/>
	<text x="280.5" y="216.5" font-family="Times New Roman" font-size="20">[</text>
	<polygon stroke="black" stroke-width="1" points="393.5,195.5 499.5,195.5"/>
	<polygon fill="black" stroke-width="1" points="499.5,195.5 491.5,190.5 491.5,200.5"/>
	<text x="441.5" y="216.5" font-family="Times New Roman" font-size="20">1</text>
	<polygon stroke="black" stroke-width="1" points="559.5,195.5 679.5,195.5"/>
	<polygon fill="black" stroke-width="1" points="679.5,195.5 671.5,190.5 671.5,200.5"/>
	<text x="614.5" y="216.5" font-family="Times New Roman" font-size="20">2</text>
	<polygon stroke="black" stroke-width="1" points="709.5,225.5 709.5,325.5"/>
	<polygon fill="black" stroke-width="1" points="709.5,325.5 714.5,317.5 704.5,317.5"/>
	<text x="698.5" y="281.5" font-family="Times New Roman" font-size="20">;</text>
	<polygon stroke="black" stroke-width="1" points="555.321,180.226 716.679,84.774"/>
	<polygon fill="black" stroke-width="1" points="716.679,84.774 707.248,84.544 712.34,93.151"/>
	<text x="640.5" y="153.5" font-family="Times New Roman" font-size="20">m</text>
	<polygon stroke="black" stroke-width="1" points="682.809,369.197 584.191,419.803"/>
	<polygon fill="black" stroke-width="1" points="584.191,419.803 593.591,420.599 589.026,411.702"/>
	<text x="618.5" y="385.5" font-family="Times New Roman" font-size="20">4</text>
	<polygon stroke="black" stroke-width="1" points="531.985,417.721 431.015,355.279"/>
	<polygon fill="black" stroke-width="1" points="431.015,355.279 435.189,363.739 440.449,355.234"/>
	<text x="486.5" y="377.5" font-family="Times New Roman" font-size="20">5</text>
	<polygon stroke="black" stroke-width="1" points="379.704,354.816 207.296,457.184"/>
	<polygon fill="black" stroke-width="1" points="207.296,457.184 216.727,457.399 211.622,448.8"/>
	<text x="281.5" y="396.5" font-family="Times New Roman" font-size="20">f</text>
</svg>](http://madebyevan.com/fsm/img.png)

## Computation

Fill out truth tables for the following expressions:

1. `(A ∧ ¬B)` (alternate: `(A && !B)`)

```
A     B     result
-------------------
0     0       ?
0     1       ?
1     0       ?
1     1       ?
```

2. `(¬A ∨ B) ∧ ¬(A ∧ ¬B)` (alternate: `(!A || B) && !(A && !B)`)

```
A     B     result
-------------------
0     0       ?
0     1       ?
1     0       ?
1     1       ?
```

3. `¬(A ∧ B) ∨ ( (A ∧ C) ∧ ¬(B ∨ ¬C) )` (alternate: `!(A && B) || ( (A && C) && !(B || !C) )`)

- (Hint: Is it possible to calculate this using code?)

```
A     B     C     result
-------------------------
0     0     0       ?
0     0     1       ?
0     1     0       ?
0     1     1       ?
1     0     0       ?
1     0     1       ?
1     1     0       ?
1     1     1       ?
```

## STRETCH GOAL

The sum of two binary digits can be represented with the following truth table:

- A + B

```
A     B     CARRY   SUM
------------------------
0     0       0      0
0     1       0      1
1     0       0      1
1     1       1      0
```

This can be represented with boolean algebra like so:

- `SUM = A ⊕ B` (alternate: `A ^ B` or `A xor B`)
- `CARRY = A ∧ B` (alternate: `A && B`)

How can you represent the SUM and CARRY of adding THREE digits with a truth table and in boolean algebra?

- A + B + C

```
A     B     C      carry   sum
--------------------------------
0     0     0        ?      ?
0     0     1        ?      ?
0     1     0        ?      ?
0     1     1        ?      ?
1     0     0        ?      ?
1     0     1        ?      ?
1     1     0        ?      ?
1     1     1        ?      ?
```

- SUM = ?
- CARRY = ?
