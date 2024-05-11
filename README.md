# CC3K

C++ dungeon crawler game.

● First run make command
● Run ./cc3k (you can add the name of a file that specifies the layout of each of the
5 floors <- this is optional)
● Specify the race you want to play as: ‘s’ for shade, ‘d’ for drow, ‘v’ for vampire, ‘g’
for goblin, ‘t’ for troll. If any other character is given, race will default to shade.
● At this point, you should see a board rendered, where potions are represented
with ‘P’, gold represented with ‘G’, your character represented by ‘@’, dragon
horde also represented by ‘G’ but has a dragon (‘D’) next to it, the stairs
represented by ‘/’, and the remaining letters just represent the various enemies in
the game. See below for example:

![Alt text](/ExampleScenario.png?raw=true "Example")

● You should be able to navigate through the board using the following commands:
‘no’, ‘ne’, ‘ea’, ‘so’, ‘se’, ‘sw’, ‘we’, ‘nw’. (compass directions).
● You can walk over gold and see your gold stat adjust accordingly.
● You can walk through hallways to navigate between chambers, but you cannot
walk through walls.
● You can use potions using the command ‘u’ followed by the direction the potion is
relative to you (must be within one block radius of you). You will see your stats
adjust accordingly. Also notice that health does not drop below 0, and does not
go above the starting hp (expectation is vampires, where they have no max hp).
Additionally, notice that atk and def also do not drop below 0, and that they are
reset to their default values after reaching a new floor.
● You can fight enemies by using the command ‘a’ followed by the direction the
enemy is relative to you (must be within one block radius of you). You will see
your health and gold adjust accordingly based on the outcome of the combat.
● There are also various special interactions between certain enemies and
playable characters which are all implemented as outlined in the assignment
instructions.
● You should make your way to the stairs(‘/’), in order to get to the second floor,
where you will see that a new board is generated, and you spawn in a random
location once again.
● Keep making your way till you get to the end of the 5th floor, and access the
stairs there, in which the game ends with a victory and your score is displayed.
● Also, you can press ‘f’ at any time in order to stop the enemy random movement
(note that they will still attack you if you get close to them).
● Additionally, ‘q’ can be used to quit the game at any time, and ‘r’ can be used to
restart the game.

