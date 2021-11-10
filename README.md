# Lemin

### Goal
###### The project : make a GPS for ants !
###### The goal is to make an algorithm that allows the ants to move between rooms and tunnels, at the end they have to be in the last room.
###### There has to be just one ant per tunnel and one ant per room, except the first one and the last one.

### Understand the outputs
The standard binary display the number of the ant that move and where she moves :
##### Example : 
P1-2 --> The first ant move to the room number two.
P1-3 --> The first ant move to the room number three.
...


### Program compilation and launch:
  ```sh
        make
```
***To use it :***
  ```sh
        ./lem_in < [file]
```

### Example Map

```
3
##start
0 1 0
##end
1 13 0 #bedroom
2 5 0
# The next room is the kitchen
3 9 0
0-2
2-3
3-1
```
