# IPv4_Manager

Recruitment task for Phoenix_systems.

## How to build and run

1. Run `cmake --preset default` from project direcotry.

2. Run `cmake --build --preset default` from project direcotry.

3. Run `./build/IPV4_MANAGER` from project directory.

## Project description

This project implements a way to store, add, delete and search IP prefixes. 
Tests are implemented using assertions in `main()` function.

Data structure which is used to store IP prefixes is a trie data structure. 
Trie data structure allows for fast searching of IP prefixes with complexity O(m) where m is depth of Trie tree.

Each node in implemented trie data tree is equivalent to a separate bit in IP prefix. `check()` function is based on 
comparation of each bit in prefix and ip address. 
