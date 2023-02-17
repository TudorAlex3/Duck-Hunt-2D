# Duck Hunt 2D

This is an implementation of a Duck Hunt game. You can test the original game here: https://www.duck-hunt.org/.

### Ducks

###### ➢ Construction

The ducks are represented by a few 2D geometric primitives (at least 4: body, wings, and head), positioned suggestively.


###### ➢ Animation

To build the duck, a set of several manually defined objects is needed that will move together but will also have independent animations.
Thus, the duck:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;* Will have a flying animation: it will flap its wings - a simple rotation on each wing. <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;* Will fly in various directions uniformly - the entire set of objects that make up the duck will move or rotate together.<br>


###### ➢ Display

The ducks appear one by one on the screen, so that at any given time, there is only one duck present on the scene. When a duck is shot or evades, the next one can be displayed.


###### ➢ Movement

The ducks appear at the bottom of the screen and will start flying in a random direction on the plane. Continuing in that direction, at some point, they will reach the edge of the screen. In this situation, the duck must "bounce" and continue in the corresponding direction, like a billiard ball hitting the edge of the table.

If the duck is shot, it will fall to the ground with a downward vertical animation, and if it evades, it will fly off the screen with an upward vertical animation.

After a reasonable number of seconds, in which the duck has collided with the edge of the screen several times, it will evade.


### Lives

The player will start with 3 lives. When a duck escapes (the player misses to hit the duck with all 3 bullets), the player loses a life. The number of remaining lives will be drawn on the screen in the upper left corner.


### Bullets

At any given time, the player needs to know how many bullets are available. For this, in the upper left corner (under the number of lives), the number of available bullets is displayed in a similar way to the number of lives.


### Score

For each shot duck, the player's score will increase. It will also be represented in the graphical interface in the upper right corner with the help of two rectangles:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;* A wireframe rectangle, which represents the maximum score level.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;* A solid blue rectangle inside the wireframe, which represents the current score.<br>


### Gameplay

The goal of the game is for the player to shoot as many ducks as possible before running out of lives. The game starts with a certain number of available lives, of which one is lost each time a duck manages to escape without being shot.

The ducks appear one by one on the screen, each after the disappearance (by evading or being shot) of the previous one. A duck will fall to the ground when shot and will fly vertically upwards to symbolize evasion.


###### ➢ Shooting

To shoot a duck, the player has 3 bullets that will reload each time a new duck appears. Each time the player clicks on the screen, it will be considered as a bullet shot at that point on the screen, and the number of available bullets will decrease by 1. If the point on the screen where the bullet was shot intersects with the duck, it will be considered shot, and the score will increase, and the duck will fall to the ground.

### Bonus features

➢ Variable score based on the duck's speed and a multiplier applied for the number of consecutive ducks shot (killing spree). An animated element (for example, a simple rotating diamond shape) needs to be displayed when this threshold is reached.

➢ After 5 ducks appear, the game advances to the next level and the ducks move faster.

➢ Each duck has a random color (similar to the original game).

➢ Creating the bottom grass layer behind which the duck appears, so that it doesn't suddenly appear on the screen out of nowhere.

➢ "Special" ducks that give the player certain abilities - an extra bullet, an extra life.
