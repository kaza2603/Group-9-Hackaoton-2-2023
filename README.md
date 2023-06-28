# Group-9-Hackaoton-2-2023
This is a CPT113 Group Assignment (Hackathon II)

# Group Members
 - LUQMANUL HAKIM BIN AFIZAR (163550)
 - KHALIL AHMAD BIN
 - MAHDIL

# Description 
## Medina League
"Medina League" is a C++ text-based, adventure-puzzle-fantasy multiplayer game that our group 9 created! The game sets in a fantasy world where two players with different role (Player 1 & Player 2) must cooperate together to fight the darkness by beating up multiple enemies with different attributes. The player will need to accumulate coin through beating low-level monster and used to buy skill in shop. This game is a combination of action-packed and puzzle experience to guide through the journey in defeating the main bos.

# Features
- It is a multiplayer (2-player) game
- It has 5 stages with unique mechanics
 - **Stage 1:** Kill the enemies (Action)
 - **Stage 2:** Find the Exit (Adventure)
 - **Stage 3:** Problem Solving & defeat an enemy (Action & Puzzle)
 - **Stage 4:** Quiz (Question)
 - **Stage 5 (Final):** Kill the game Boss (Action)
 
# Playing the game
Upon starting the game, player 1 will be assign to role "Fighter" with a skill of physical damage and player 2 will be assign to role "Mage" with a skill of magical damage. These role will affect the gameplay, as different level and challenges may become hard or easy based on the character's strengths and weaknesses.

After every stage cleared, you will be given option to buy equipment in shop. Use the chance to increase your skill to help through this adventure.

**Stage 1:** Use commands number 1 or 2 to defeat the enemy minion and collect gold.
**Stage 2:** Both player will taking turn to guess the correct room that have the key to exit. If either one player are guess the room that holding the witch, the player will get attacked.
**Stage 3:** The wizard will choose randomly from either two player and asked a puzzle.If the player failed to answer, it will get attacked. To clear this stage, both player must defeat the wizard.
**Stage 4:** Right before entering the final stage, Players need to face the Guardian and answer four formidable questions that will relies on player's problem-solving skills.
**Stage 5:** Defeat the final bos with your accumulation of skill and experience .

### Special Tips:
**Read the Introduction:** Familiarize yourself with the game's introductory text, which sets the stage for your adventure and provides essential background information about the game.

**Navigate and Explore:** Use commands in a range number of 1 - 5 to explore multiple level or goes to shop for buying equipment to enhance the player skill.

**Make Choices:** During interactions with enemy and stage, you'll be presented with choices. Use the provided options or type your responses to shape the outcome of the game. Your decisions may influence your character's the direction of the storyline.

**Manage Inventory and Upgrades:** Acquire and manage your character's inventory, which includes weapons and skills . Upgrade your equipment when possible to enhance your character's abilities and combat effectiveness.

Save Your Progress: Use the game's save function to record your progress and continue your adventure from where you left off in future sessions.


# How object-oriented concepts were used to develop our game :

1. **Classes and Objects:** We use 5 class (Character, Player , Enemy , Item , Map) to represent game's entities, such as characters, enemy, items and location. Each specific class  defines its properties (attributes) and behavior (methods). For example, Character class that represents the player's character and an Items class for the equipment and skill. These classes encapsulate related data and functionality.

2. **Inheritance:** Common attributes and behaviors are defined in a Character class, and specialized classes like Player and Enemy is inherit from it. Also the items class is inherited from Player class.These class inherited the shared properties and methods while also adding their own unique characteristics.

3. **Composition:**  Composition involves building complex objects by combining simpler objects or components. For example, a Stage struct composed of Enemy objects, Player objects, and other components. This allows for flexible construction of game elements and facilitates interactions between different class.

4. **Encapsulation:**  We implement this concept by hiding the instance variables of a class by making them private. Only member functions of the same class can access them. For instance, we implemented a Player class and its member variables are private. To acess the variables, there are setters and getters to modify and return the attributes of a player such as setName and getPlayer respectively.

5. **Abstraction:** We focus on hiding unnecessary complexity using  classes and methods are designed to abstract away the low-level implementation details, enabling higher-level interactions and gameplay mechanics.

6. **Modularity:**  similar with encapsulation , we  divide into manageable modules and classes allowing the game's codebase to be easier maintenance, scalability, and code reusability.

# How linked lists play a important role in your game :

We relies heavily on linked list for Pathfinding and Location Sequencing . 
In this game where the player navigates through different locations, a linked list used to represent the sequence of locations visited. Each node in the list corresponds to a specific location and contains information about it, such as the stage name, description, player ,  enemy  and connections to neighboring locations. As the players moves from one location to another, nodes are added to the linked list, creating a path that can be traversed backward or forward, allowing for easy movement tracking and exploration . 

# Screenshot Of Our Game :
Here are the screenshots of the game: 

# Link to game demo video : 

You can view the livestream here: https://www.youtube.com/watch?v=iLHAKXQBOoA

# How to run the game :
Run this command in the terminal:
`g++ main.cpp Player.h -o main`
`./main`
