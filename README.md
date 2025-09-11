# 2048-terminal

**2048-terminal** is a lightweight, ncurses-based clone of the popular 2048 puzzle game, designed to run natively inside your Linux terminal.  
It brings the addictive slide-and-merge gameplay into a distraction-free colorful text-based environment — perfect for quick breaks.

---

## 🎮 Gameplay

- Use **arrow keys** to slide the tiles.  
- When two tiles with the same number collide, they merge into one.  
- New tiles appear after every move.  
- Score: combining two tiles increases score with the tiles sum.   
- If the board fills up with no possible moves, game is over.

---

## ✨ Features

- Minimal, colorful, retro-style **ncurses** interface.  
- Smooth keyboard-driven controls.  
- Works in any Linux terminal. 
- Lightweight: single binary, very few dependencies. 
- Faithful to the original 2048 mechanics. 

---

## 📦 Installation

### From source
Clone the repository and build:

```bash
git clone https://github.com/shadymansour19/2048-terminal.git
cd 2048-terminal
sudo make install
```

By default, the binary installs into /usr/games/2048-terminal.

Run it with:

```
2048-terminal
```

---

### 📦 Debian/Ubuntu package

You can also build a .deb package (for easy installation):


```
sudo apt install checkinstall
sudo checkinstall
```

---

## 🛠 Dependencies

- gcc (for building)
- libncurses5-dev (or libncursesw5-dev)


### On Debian/Ubuntu:

```
sudo apt install build-essential libncurses5-dev
```

---

## 👨‍💻 Author

Developed by Shady Mansour

📧 shadymansour19@gmail.com

🌍 [LinkedIn](https://linkedin.com/in/shadymansour19) • [GitHub](https://github.com/shadymansour19)

