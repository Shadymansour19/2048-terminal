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

### From Debian Package
Download the .deb package provided in the [release page](https://github.com/Shadymansour19/2048-terminal/releases/).

```bash
sudo apt install wget
wget https://github.com/Shadymansour19/2048-terminal/releases/download/v1.0/2048-terminal_1.0-1_amd64.deb
```

Install the package.
```bash
sudo apt install ./2048-terminal_1.0-1_amd64.deb
```

By default, the binary installs into /usr/games/2048-terminal. You can check it by:
```bash
which 2048-terminal
```

---

### From source code
Clone the repository and build:

```bash
git clone https://github.com/shadymansour19/2048-terminal.git
cd 2048-terminal
sudo make install
```

---

### Build Debian/Ubuntu package locally?

You can also build a .deb package similar to the one provided in the [release page](https://github.com/Shadymansour19/2048-terminal/releases/) from the source code as follows:


```
sudo apt install checkinstall
sudo checkinstall
```

---

## 🎮 Running the game

Run the game with:

```
2048-terminal
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

## 📸 Screenshoots

<img width="979" height="607" alt="Screenshot from 2025-09-11 15-32-17" src="https://github.com/user-attachments/assets/c6808e9e-740f-4daa-ad86-c2f3a9555974" />

<img width="979" height="607" alt="Screenshot from 2025-09-11 15-32-36" src="https://github.com/user-attachments/assets/52fb9701-8f7f-4a19-98ea-8ba94ba30db8" />


---

## 👩‍💻 Author

Developed by Shady Mansour

📧 shadymansour19@gmail.com

🌍 [LinkedIn](https://linkedin.com/in/shadymansour19) • [GitHub](https://github.com/shadymansour19)

