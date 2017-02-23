# 8INF846-TP1:
## Vacu-bot, ready for duty !

This program has been made for an assignment in the Artificial Intelligence course at UQAC.
The program has 2 main elements:
* An environment of 25 rooms in a 2-dimensional grid, which is a hotel.
* An Agent with an Artificial Intelligence, which is a vacuum bot.

The hotel becomes dusty through the time and sometimes, customers drop jewels on the ground. The goals of Vacu-Bot is to vacuum the maximum of dust and the least of jewels and to try to use the least energy possible.

Our goal was to develop an AI for Vacu-Bot with a BDI software-model and to use exploration algorithm for its action planning, but first, we had to model and display the environment.

To do, so we've decided to represent the rooms with a class *CaseEnvironnement* containing mainly a dust counter and a jewel counter (even if in the example, it's only going up to 1 and down to 0). The Rooms are then stored in 1D and 2D in a GlobalEnvironnement variable, which inherits from Environnement, due to some common factor with another environment.

Well, let's talk about the Vacu-Bot now. First, what are its abilities? He has 3 possible actions:
* Going to an adjacent room
* Vacuuming its current room
* Picking a jewel in its current room
All these actions have the same energetic cost of 1 energy unit.
He has also a special action, which is to synchronise its data (more on that later). However, the robot has to avoid to do it has much has possible, due to err... let's say a cheap antenna.

Every time the bot refresh its data, he's also planning it's route before going in his holy war against dust. To do so, we chose to use a Depth-Limited Algorithm. The depth limit is the energy available for its plan, and we try to maximise this value without doing a lot worse than before, if he does, the bot freeze it's energy available to the latest acceptable value. And this is the Intent part of or BDI as well as the learning part of our robot.

To evaluate what's he's doing, the robot has a scoring chart he can use, and this is clearly defined in the Heuristic class:
* If the bot loose a jewel, he loses 8 points,
* If the bot clear some dust, he earns 8,
* If he picked a jewel, he loses 2 (remember we only care about dust, jewel are only an obstacle !),
* And if he moves, he loses 1.
This Heuristic is the representation of Vacu-Bot's Desires - even if in short, he justs want the hi-score -.

Then, its Beliefs are simply programmed: A lost Jewel counter and an asynchronous copy of GlobalEnvironnement (mentioned earlier): LocalEnvironnement. Both those variables are synchronised just before the action planning.

We were very satisfied with the result of our work, and please do not hesitate to test it, a Windows executable is included in the release section of this repo.
