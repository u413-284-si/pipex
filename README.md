# pipex
This project is a recreation of the UNIX mechanism 'piping' allowing a chain of commands to feed their outputs to each other in a consecutive manner.


## Project Overview

Just as the shell accepts several commands which can be chained to one another and directs their output to each other, the program is able to reproduce this behaviour. An input file and an output file are specified which serve respectively as input for the first command / recipient of the output of the last command. 

Following example illustrates the aforementioned description:

### Program call
```
./pipex infile "ls -l" "wc -l" outfile
```
behaves just as

### Shell command
```
< infile ls -l | wc -l > outfile
```

In the enhanced implementation (bonus) the program is able to

* process more than two commands as well as 
* reproduce the here_doc feature of shell


### Program call
```
./pipex here_doc LIMITER "ls -l" "wc -l" outfile
```
behaves just as

### Shell command
```
ls -l << LIMITER | wc -l >> outfile
```

The goal of the project is to familiarise oneself with
* Pipes and their application
* Forking, parent & child processes
* Especially how to ensure a clean termination of the program with no leftover child processes (orphans), open file descriptors or memory leaks
* Execution of system calls/commands via the program
* Here_doc behaviour
* Shell and how it works in the background

## Installation

```
git clone https://github.com/u413-284-si/pipex pipex
cd pipex
make
./pipex infile "<cmd 1>" "<cmd 2>" outfile
```

For bonus program (while within the pipex directory):

```
make bonus
./super_pipex infile "<cmd 1>" "<cmd 2>" "<cmd 3>" ... outfile
or
./super_pipex here_doc LIMITER "<cmd 1>" "<cmd 2>" "<cmd 3>" ... outfile
```

Que aproveche!
