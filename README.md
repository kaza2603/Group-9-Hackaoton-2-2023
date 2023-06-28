# Group-9-Hackaoton-2-2023 :💻
This is a CPT113 Group Assignment (Hackathon II) 

# Group Members (Contributors) 🏠
 - LUQMANUL HAKIM BIN AFIZAR (163550)
 - KHALIL AHMAD BIN ZAINALABIDIN (164416)
 - MAHDIL ASHRONIE BIN MUHAMAD MURTADZA (163966)

# Description 
## Medina Legend 🎮
"Medina Legend" is a C++ text-based, adventure-fantasy multiplayer game that our group 9 created! The game sets in a fantasy world where two players with different roles (Player 1 & Player 2) must cooperate together to fight the darkness by beating up multiple enemies with different attributes. The player will need to accumulate coins by beating low-level monsters and using them to buy skills in the shop. This game is a combination of action-packed to guide the players through the journey of defeating the main boss.

# Features 🧰
 - It is a multiplayer (2-player) game
 - It has 5 stages with a different enemy (linked list)
 - Load and save the game 
 - Class and object for data encapsulation
 
# Playing the game 🎲
Upon starting the game, player 1 will be assigned to the role "Fighter" with a skill of physical damage and player 2 will be assigned to the role "Mage" with a skill of magical damage. These roles will affect the gameplay, as different levels and challenges may become hard or easy based on the character's strengths and weaknesses.

After every stage is cleared, you will be given the option to buy equipment and food in the shop. Use the chance to increase your skill to help through this adventure.

 - **Stage 1:** Minion (low-tier monster)
 - **Stage 2:** Find the Exit from the witch
 - **Stage 3:** The wizard 
 - **Stage 4:** The Guardian
 - **Stage 5 (Final):** Defeat the final bos
   

### Special Tips: 💡
**Read the Introduction:** Familiarize yourself with the game's introductory text, which sets the stage for your adventure and provides essential background information about the game.

**Navigate and Explore:** Use commands in a range number of 1 - 5 to explore multiple levels or goes to a shop for buying equipment to enhance the player's skill.

**Make Choices:** During interactions with the enemy and stage, you'll be presented with choices. Use the provided options or type your responses to shape the outcome of the game. Your decisions may influence your character's direction in the storyline.

**Manage Inventory and Upgrades:** Acquire and manage your character's inventory, which includes weapons and skills. Upgrade your equipment when possible to enhance your character's abilities and combat effectiveness.

Save Your Progress: Use the game's save function to record your progress and continue your adventure from where you left off in future sessions.


# How object-oriented concepts were used to develop our game 🔬

1. **Classes and Objects:** We use 5 classes (Character, Player, Enemy, Item, Map) to represent the game's entities, such as characters, enemies, items and location. Each specific class  defines its properties (attributes) and behaviour (methods). For example, a Character class that represents the player's character and an Item class for the equipment and skill. These classes encapsulate related data and functionality.

2. **Inheritance:** Common attributes and behaviours are defined in a Character class, and specialized classes like Player and Enemy are inherited from it. Also, the item's class is inherited from the Player class. These classes inherited the shared properties and methods while also adding their own unique characteristics.

3. **Composition:**  Composition involves building complex objects by combining simpler objects or components. For example, a Stage struct is composed of Enemy objects, Player objects, and other components. This allows for the flexible construction of game elements and facilitates interactions between different classes.

4. **Encapsulation:**  We implement this concept by hiding the instance variables of a class by making them private. Only member functions of the same class can access them. For instance, we implemented a Player class and its member variables are private. To access the variables, there are setters and getters to modify and return the attributes of a player such as setName and getPlayer respectively.

5. **Abstraction:** We focus on hiding unnecessary complexity using  classes and methods designed to abstract away the low-level implementation details, enabling higher-level interactions and gameplay mechanics.

6. **Modularity:**  Similar to encapsulation, we  divide into manageable modules and classes allowing the game's codebase to be easier maintenance, scalability, and code reusability.

# How linked lists play an important role in your game ⛓️

We rely heavily on a linked list for Pathfinding and Location Sequencing. 
In this game where the player navigates through different locations, a linked list is used to represent the sequence of locations visited. Each node in the list corresponds to a specific location and contains information about it, such as the stage name, description, player,  enemy  and connections to neighbouring locations. As the players move from one location to another, nodes are added to the linked list, creating a path that can be traversed backwards or forwards, allowing for easy movement tracking and exploration. 

# Screenshot Of Our Game: 📷
Here are the screenshots of the game: 

# Link to a game demo video: 🎥

You can view the live stream here: [https://www.youtube.com/watch?v=iLHAKXQBOoA](https://youtu.be/QdTOxXxvVlw)]

# How to run the game : ⚙️
Run this command in the terminal:
`g++ main.cpp Player.h -o main`
`./main`
