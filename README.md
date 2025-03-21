# CC3K 🎮

<div align="center">

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A text-based dungeon crawler roguelike game written in C++. Navigate through 5 floors of procedurally generated dungeons, battle enemies, collect treasures, and try to reach the final floor!

</div>

## 🎯 Features

- **Multiple Playable Races**
  - Shade (default)
  - Drow
  - Vampire
  - Goblin
  - Troll

- **Dynamic Gameplay**
  - Procedurally generated dungeon floors
  - Enemy AI with random movement
  - Combat system with race-specific interactions
  - Potion and treasure collection
  - Stats management (HP, ATK, DEF)

- **Game Controls**
  - Movement: `no`, `ne`, `ea`, `so`, `se`, `sw`, `we`, `nw` (compass directions)
  - Combat: `a` + direction
  - Use Potion: `u` + direction
  - Toggle Enemy Movement: `f`
  - Quit Game: `q`
  - Restart Game: `r`

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++ recommended)
- Make

### Installation

1. Clone the repository
```bash
git clone https://github.com/yourusername/chamber-crawler.git
```

2. Build the project
```bash
make
```

3. Run the game
```bash
./cc3k [layout_file]
```
> Note: The layout file is optional. If not provided, the game will use default layouts.

## 🎮 How to Play

1. Choose your race:
   - `s` - Shade
   - `d` - Drow
   - `v` - Vampire
   - `g` - Goblin
   - `t` - Troll
   - Any other character defaults to Shade

2. Navigate through the dungeon:
   - Use compass directions to move
   - Collect gold (`G`) and potions (`P`)
   - Battle enemies (various letters represent different enemies)
   - Find stairs (`/`) to progress to the next floor

3. Combat and Items:
   - Use potions with `u` + direction
   - Attack enemies with `a` + direction
   - Each race has unique interactions with different enemies
   - Stats reset when reaching a new floor

4. Win Condition:
   - Reach and use the stairs on the 5th floor
   - Your final score will be displayed

## 🎨 Game Elements

- `@` - Player character
- `G` - Gold
- `P` - Potion
- `D` - Dragon
- `/` - Stairs
- Various letters represent different enemies

## 🛠️ Technical Details

- Written in C++17
- Object-oriented design with inheritance
- Procedural dungeon generation
- Event-driven architecture

## 🤝 Contributing

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

<div align="center">
  Made with ❤️ by Omar Elserwi
</div>
