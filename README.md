# 2048-terminal

**2048-terminal** is a lightweight, ncurses-based clone of the popular 2048 puzzle game, designed to run natively inside your Linux terminal.  
It brings the addictive slide-and-merge gameplay into a distraction-free, colorful, text-based environment — perfect for quick breaks.

---

## 🎮 Gameplay

- Usage:
    - **arrow keys** to slide the tiles. 
    - **q** to quit the game. 
    - **u** to undo the last move. 
    - **r** to redo the last move. 
    - **h** to get a hint. 
    - **?** to display the help message. 
- When two tiles with the same number collide, they merge into one. 
- New tiles appear after every move. 
- Score: combining two tiles increases the score by their sum. 
- If the board fills up with no possible moves, the game is over. 

---

## ✨ Features

- Minimal, colorful, retro-style **ncurses** interface.  
- Smooth keyboard-driven controls.  
- Works in any Linux terminal. 
- Lightweight: single binary, very few dependencies. 
- Faithful to the original 2048 mechanics. 

---

## 📦 Installation

### 1. From official PPA (Recommended 🚀)
The easiest way to install 2048-terminal on Ubuntu/Debian-based distros is via the official PPA on Launchpad:

```bash
sudo add-apt-repository ppa:shadymansour19/2048-terminal
sudo apt update
sudo apt install 2048-terminal
```

This way, you guarantee to get the latest updates automatically.


By default, the binary installs into /usr/games/2048-terminal.
Check with:

```bash
which 2048-terminal
```

### 2. From Debian Package
Download the .deb package provided in the [release page](https://github.com/Shadymansour19/2048-terminal/releases/).

```bash
sudo apt install wget
wget https://github.com/shadymansour19/2048-terminal/releases/latest/download/2048-terminal_<VERSION>_amd64.deb
```
Replace ```<VERSION>``` with the desired version.


Then install the package.
```bash
sudo apt install ./2048-terminal_<VERSION>_amd64.deb
```

---

### 3. From source code
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

```bash
2048-terminal
```


---

## 🛠 Dependencies

- gcc (required for building only in case of installation from source code)
- libncurses5-dev (or libncursesw5-dev)


### On Debian/Ubuntu:

```
sudo apt install build-essential libncurses5-dev
```

---

## 📸 Screenshoots

<img width="1054" height="543" alt="image" src="https://github.com/user-attachments/assets/403f7e81-5958-4de7-a14e-86e2fc6ae8f1" />

<img width="1054" height="543" alt="image" src="https://github.com/user-attachments/assets/758d1bb7-64dc-49b8-ad41-d9c2dc9c5603" />

<img width="1054" height="699" alt="image" src="https://github.com/user-attachments/assets/0615cee8-9093-4745-bfe8-d644e2924727" />

<img width="1054" height="699" alt="image" src="https://github.com/user-attachments/assets/e8dc67f2-fa0d-47c0-9c46-ca6219718caf" />

<img width="1054" height="699" alt="image" src="https://github.com/user-attachments/assets/5e15eb52-c70e-47c2-abd7-9e867b538e1d" />


---

## 👩‍💻 Author

Developed by Shady Mansour

📧 shadymansour19@gmail.com

🌍 [LinkedIn](https://linkedin.com/in/shadymansour19) • [GitHub](https://github.com/shadymansour19)
